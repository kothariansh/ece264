flowchart LR
  %% ========= HIGH-LEVEL PIPELINE (snappy like the ref figure) =========
  %% STYLE HINTS
  classDef stage fill:#f6f8fa,stroke:#2b6cb0,stroke-width:1px,rx:6,ry:6;
  classDef op fill:#ffffff,stroke:#555,rx:6,ry:6;
  classDef file fill:#fff7e6,stroke:#a15c00,rx:6,ry:6;
  classDef note fill:#eef,stroke:#88a,stroke-dasharray:3 3,rx:6,ry:6;

  %% ---------------- Inputs ----------------
  D0[Route data folder]:::file
  D1[model_build_inputs/route_data.json]:::file
  D2[model_build_inputs/package_data.json]:::file
  D3[(new_)travel_times.json]:::file
  D4[actual_sequences.json]:::file

  %% ---------------- Step 0: Build Instance ----------------
  subgraph P["Preparation"]
    direction LR
    P0[Extract route_id\n(select or first)]:::op
    P1[Collect stops (exclude Station)]:::op
    P2[Sum service_s per stop\n+ merge time windows]:::op
    P3[Build travel-time matrix T\n(+ depot links via means)]:::op
    P4[Create Instance{route_id, stops, index_of, T,\ncapacity_cm3, total_volume_cm3}]:::stage
  end

  %% ---------------- Step 1: Initialize Sequencing ----------------
  subgraph I["Solve – Initialization"]
    direction LR
    I0[Optional warm start:\nload_actual_order]:::op
    I1[Double-bridge kick]:::op
    I2[Two-opt timeboxed (short)]:::op
    I3[_init_population(n) + educate each\n(local_search_fast half budgets)]:::stage
  end

  %% ---------------- Step 2: HGS Loop ----------------
  subgraph H["Solve – Hybrid Genetic Search (time-boxed)"]
    direction LR
    H0{Time left &\nno_improve < limit?}:::op
    H1[Pick parents (prefer feasible\nvia biased_fitness)]:::op
    H2[OX crossover (slice p1, fill from p2)]:::op
    H3[Optional kicks:\n10% double-bridge,\n20% random swap]:::op
    H4[Local search fast:\n2-opt sampled + relocate sampled]:::op
    H5[Classify child →\nfeasible vs infeasible pools\n(trim by biased_fitness)]:::op
    H6{Improved best?}:::op
    H7[best = child;\nno_improve = 0]:::op
    H8[no_improve += 1;\nrestart if ≥ 200\n(keep elites, refill, educate)]:::op
    H9[[Return best feasible\nelse best infeasible/base]]:::stage
  end

  %% ---------------- Step 3: Persist + Score ----------------
  subgraph O["Output & Scoring"]
    direction LR
    O0[Convert best order → {sid: rank}]:::op
    O1[Merge into\nmodel_apply_outputs/proposed_sequences.json]:::stage
    O2[score_against_ground_truth:\nKendall τ, Spearman F, PPA,\nΔtravel, Δobjective,\npaper_style_score]:::stage
  end

  %% ---------------- CLI Modes (simple) ----------------
  subgraph C["CLI entry points"]
    direction TB
    C0[--run-all:\nloop all route_ids → solve_route → score]:::note
    C1[--compare:\nsolve_route + print vs actual]:::note
    C2[--improve-actual:\nlocal search starting from actual\n(write proposed)]:::note
    C3[--eval-actual:\nroute_cost on actual only]:::note
    C4[default:\nsolve_route one route]:::note
  end

  %% --------- Connections ---------
  D0 --> D1
  D0 --> D2
  D0 --> D3
  D0 --> D4

  D1 --> P0 --> P1
  D2 --> P2
  D3 --> P3
  P1 --> P2 --> P3 --> P4

  P4 --> I0
  D4 --> I0
  I0 --> I1 --> I2 --> I3

  I3 --> H0
  H0 -- yes --> H1 --> H2 --> H3 --> H4 --> H5 --> H6
  H6 -- yes --> H7 --> H0
  H6 -- no  --> H8 --> H0
  H0 -- no  --> H9

  H9 --> O0 --> O1 --> O2

  %% CLI hooks to default path
  C0 -. calls .-> P0
  C1 -. calls .-> P0
  C2 -. calls .-> I0
  C3 -. calls .-> P0
  C4 -. calls .-> P0
