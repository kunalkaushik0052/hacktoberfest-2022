#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node* newNode(int item)        // A function to create a new BST node
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

void inorder(struct node* root)      // A function to do in-order traversal of BST
{
    if (root != NULL)
    {
        inorder(root -> left);
        printf("%d ", root -> key);
        inorder(root -> right);
    }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    if (node == NULL)                  // If the tree is empty, return a new node //
        return newNode(key);
    if (key < node -> key)             // Otherwise, recur down the tree //
        node -> left = insert(node -> left, key);
    else
        node -> right = insert(node -> right, key);
    return node;                       // return the (unchanged) node pointer //
}

/* Given a non-empty binary search tree, return the node with minimum key value found in that tree */
struct node* minValueNode(struct node* node)
{
    struct node* current = node;       // loop down to find the leftmost leaf //
    while (current && current -> left != NULL)
        current = current -> left;
    return current;
}

/* Given a binary search tree and a key, this function deletes the key and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root -> key)
        root -> left = deleteNode(root -> left, key);
    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root -> key)
        root -> right = deleteNode(root -> right, key);
    // if key is same as root's key, then This is the node to be deleted
    else
    {
        if (root -> left == NULL)            // node with only one child or no child//
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root -> right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root -> right);
        root -> key = temp -> key;           // Copy the in-order successor's content to this node//
        root -> right = deleteNode(root -> right, temp -> key);         // Delete the in-order successor//
    }
    return root;
}
// Driver Code
int main()
{
    struct node* root = NULL;
    root = insert(root, 121);
    root = insert(root, 64);
    root = insert(root, 65);
    root = insert(root, 75);
    root = insert(root, 82);
    root = insert(root, 102);
    root = insert(root, 94);
    root = insert(root, 108);
    root = insert(root, 12);
    root = insert(root, 15);
    root = insert(root, 26);
    root = insert(root, 45);
    root = insert(root, 82);
    root = insert(root, 95);

    printf("In-order traversal of the given tree: \n");
    inorder(root);
    printf("\nDelete: 65\n");
    root = deleteNode(root, 65);

    printf("\nIn-order traversal of the modified tree: \n");
    inorder(root);
    printf("\nDelete: 75\n");
    root = deleteNode(root, 75);

    printf("\nIn-order traversal of the modified tree: \n");
    inorder(root);
    printf("\nDelete: 15\n");
    root = deleteNode(root, 15);

    printf("\nIn-order traversal of the modified tree: \n");
    inorder(root);
    printf("\nDelete: 45\n");
    root = deleteNode(root, 45);

    printf("\nIn-order traversal of the modified tree: \n");
    inorder(root);
    printf("\nDelete: 95\n");
    root = deleteNode(root, 95);

    printf("\nIn-order traversal of the Final modified tree: \n");
    inorder(root);

    return 0;
}
