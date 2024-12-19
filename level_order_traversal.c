#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to perform level-order traversal of the binary tree
void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    // Create a queue to store pointers to nodes
    struct Node **queue = (struct Node **)malloc(sizeof(struct Node *) * 100);
    int front = 0, rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear)
    {
        // Dequeue a node from the queue
        struct Node *current = queue[front++];

        // Process the current node
        printf("%d ", current->data);

        // Enqueue the left child
        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }

        // Enqueue the right child
        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }

    // Free the allocated memory for the queue
    free(queue);
}

int main()
{
    // Create the binary tree
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform level-order traversal
    printf("Level order traversal of binary tree: ");
    levelOrderTraversal(root);

    return 0;
}
