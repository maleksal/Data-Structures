// Linkedlist

#include<stdlib.h>
#include<stdio.h>

typedef struct Node Node;
struct Node
{
    int data;
    struct Node* next;
};
// global variable can be accessed anywhere
Node* head;

// Define Functions
void PrintList(Node* list);
void TestLinkedList();
void AddFirst(struct Node** head_ref, int value);
void AddLast(struct Node** head_ref, int value);
void Delete(struct Node **head_ref, int key);
void Enumerate(Node* list);

int main()
{
    TestLinkedList();
    return 0;
}

// Testing
void TestLinkedList()
{
    Node* list = NULL;

	AddFirst(&list, 5);
	AddFirst(&list, 3);
	AddLast(&list, 4);
	AddLast(&list, 1);

    Delete(&list, 1);
    PrintList(list);
}

//Print List

void PrintList(Node* list)
{
	Node* current = list;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}

//inserts a new node on the front of the list.

void AddFirst(struct Node** head_ref, int value) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));     //allocate node

    new_node->data  = value;     //put in the data 

    new_node->next = (*head_ref);    //Make next of new node as head 

    (*head_ref)    = new_node;     //move the head to point to the new node 

}

// insert a new node on the end of list

void AddLast(struct Node** head_ref, int value)
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));     //allocate node 
    struct Node *last = *head_ref;
    new_node->data  = value;     //put in the data 

    // This new node is going to be the last node, so make next  of it as NULL
    new_node->next = NULL; 
  
    //If the Linked List is empty, then make the new node as head 
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
       
    //Else traverse till the last node 
    while (last->next != NULL) 
        last = last->next; 
   
    // Change the next of last node 
    last->next = new_node; 
    return;     
}

// delete node
void Delete(struct Node **head_ref, int key) 
{ 
    // Store head node 
    struct Node* temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
}

//void Enumerate(Node* list)