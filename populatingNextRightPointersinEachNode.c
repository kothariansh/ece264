struct Node* connect(struct Node* root) {
	if (!root)
        return root;
    
    struct Node* ptr_node = root;
    struct Node* first = ptr_node;
    
    while (ptr_node->left) {
        
        while (ptr_node) {
            
            ptr_node->left->next = ptr_node->right;
            
            if (ptr_node->next) {
                ptr_node->right->next = ptr_node->next->left;
            }
            
            ptr_node = ptr_node->next;
        }
        
        first = first->left;
        ptr_node = first;
    }
    
    return root;
}


/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void connect_helper(struct Node *root) 
{
    if (!root)
        return;

    static struct Node dummy;
    dummy.next = 0;

    struct Node *last = &dummy;
    while(root)
    {
        if (root->left)
            last = last->next = root->left;
        if (root->right)
            last = last->next = root->right;

        root = root->next;
    }

    connect_helper(dummy.next);
}


struct Node* connect(struct Node* root) 
{
	connect_helper(root);

    return root;
}
