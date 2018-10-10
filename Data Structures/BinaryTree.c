#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
	int data;
	Node* right;
	Node* left;
};

// Search
Node* Search(Node* current, int key)
{
	if (current == NULL)
	{
		return NULL; 
	}

	if (current->data == key)
	{
		return current;
	}

	if (key >= current->data)
	{
		Search(current->right, key);
	}
	else 
	{
		Search(current->left, key);
	}
}

// Insert
void Add(Node** current, int data)
{
	if (*current == NULL)
	{
		*current = malloc(sizeof(Node));
		(*current)->data = data;
		(*current)->left = NULL;
		(*current)->right = NULL;
		return;
	}

	if (data >= (*current)->data)
	{
		Add(&(*current)->right, data);
	}
	else
	{
		Add(&(*current)->left, data);
	}
}

struct Node * minValueNode(struct Node* node) 
{ 
    struct Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

// Delete
struct Node* deleteNode(struct Node* root, int data) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    if (data < root->data) 
        root->left = deleteNode(root->left, data); 
   
    else if (data > root->data) 
        root->right = deleteNode(root->right, data); 
  
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct Node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct Node *temp = root->left; 
            free(root); 
            return temp; 
        }  
        struct Node* temp = minValueNode(root->right); 
        
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data); 
    }
    return root;
}

void PrintInOrder(Node* currentNode)
{
	if (currentNode == NULL)
	{
		return;
	}

	PrintInOrder(currentNode->left);
	printf("%d\n", currentNode->data);
	PrintInOrder(currentNode->right);
}
// Test
int main() 
{
	Node* tree = NULL;

	Add(&tree, 6);
	Add(&tree, 5);
	Add(&tree, 4);
	Add(&tree, 5);
	Add(&tree, 2);
	Add(&tree, 8);
	Add(&tree, 7);
	Add(&tree, 10);
	
	Node* searchPt = Search(tree, 20);
    tree = deleteNode(tree ,7);
    PrintInOrder(tree);
}