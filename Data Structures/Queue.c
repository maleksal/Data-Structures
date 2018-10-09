#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

// Two glboal variables to store address of head and tail nodes. 
struct Node* head = NULL;
struct Node* tail = NULL;

// To Enqueue an integer
void Enqueue(int x) {
	struct Node* temp = 
		(struct Node*)malloc(sizeof(struct Node));
	temp->data =x; 
	temp->next = NULL;
	if(head == NULL && tail == NULL){
		head = tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

// To Dequeue an integer.
void Dequeue() {
	struct Node* temp = head;
	if(head == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(head == tail) {
		head = tail = NULL;
	}
	else {
		head = head->next;
	}
	free(temp);
}

void Head()
{
    	if(head == NULL) {
		printf("Queue is empty\n");
		return;
	}
	return head->data;
}

void Print() {
	struct Node* temp = head;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue 
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();
}

