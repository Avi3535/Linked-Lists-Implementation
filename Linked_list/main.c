// Linked List Implementation
// Read Comments for more details

#include <stdio.h>
#include <stdlib.h>

// Each node will have the data and address pointing to the next node.
// With this type of declaration of the structure we can initialize nodes without using the keyword 'struct' every time.

typedef struct node{
    int data; // This will store the data
    struct node* link; // This will point to the next node.
}node;

node* head = NULL; // This is the head node. Initialize to zero when there are no nodes.

// Call this function by value with 'val' to be in the linked list.
 void Insert(int val){

    node* temp; // Create a temporary node to insert new node.
    temp = (node*)malloc(sizeof(node)); // Take memory from heap of size of data-type node.
    temp->data = val; // Copy data into the new node.
    temp->link = head; // store previous node address with new data.
    head = temp; // New head will contain address of the new data.
 }

 // Call function to print data in the nodes.
 void Print(){
    struct node* temp; // Create a temporary node to traverse the list. // We can use struct node to define node as well.
    temp = head; // Take the first node in the list.
    while(temp != NULL){ // Till the list is not empty, i.e, last node will have address NULL
        printf("%d\n", temp->data);// Print the data.
        temp = temp->link;// Address of the next node
    }
 }

 // This function will remove the last element in the linked list.
 void dequeue(){
  node* temp1; // Temporary node to hold next node.
  node* temp2; // Node to hold 'temp1'
  temp1 = head; // Start with the head node.
  while(temp1 != NULL){ // Till list is not empty
    if(temp1->link == NULL){ // enter this loop if next node is the last node
        temp2->link = NULL; // Previous node will point to NULL
        free(temp1); // Free memory in the heap since we will be not using it.
        return;
    }
    temp2 = temp1; // temp2 is previous node now
    temp1 = temp1->link; // Go to next node and temp1 is new node.
  }
 }

 // This function will insert a new node at a particular position.
 void insert_at_n(int val, int n){

    node* temp = (node*)malloc(sizeof(node*));

    if(n == 1){
       temp->data = val;
       temp->link = head;
       head = temp;
    }
    else{
        node* temp1 = (node*)malloc(sizeof(node*));
        node* temp2 = (node*)malloc(sizeof(node*));
        temp1 = head;
        int i = 1;
        while(1){

            if(i == n){
                temp->data = val;
                temp->link = temp1;
                temp2->link = temp;
                return;
            }

            temp2 = temp1;
            temp1 = temp1->link;
            i++;
            if(temp1->link == NULL){
                temp->data = val;
                temp->link = NULL;
                temp1->link = temp;
                return;
            }
        }
    }
 }

int main()
{
    int size, val, pos; // Size will store size of the linked list, Val is the data in the list.
    printf("Enter number of elements in the linked list : \n");
    scanf("%d", &size); // Input size
    for(int i = 0; i<size; i++){ // Take input of all elements.
        printf("Enter the element : \n");
        scanf("%d", &val); // Input value
        Insert(val); // insert val in linked list by calling Insert function
    }

    printf("The Linked list is : \n");
    if (size>0) Print(); // Print elements in the linked list.
    else printf("No elements...\n");

    dequeue();
    size--;
    if(size < 0) size = 0;
    printf("After Dequeue the Linked list is : \n");
    if (size>0) Print(); // Print elements in the linked list.
    else printf("No elements...\n");
    printf("Size Of the List after Dequeuing is : ");
    printf("%d\n",size);

    printf("Enter New Element To Enter In the Linked List : \n");
    scanf("%d", &val);
    printf("What position do you wish to enter it in the Linked List : \n");
    scanf("%d", &pos);
    insert_at_n(val,pos);
    size++;
    printf("After Inserting at nth position the Linked list is : \n");
    if (size>0) Print(); // Print elements in the linked list.
    else printf("No elements...\n");
    printf("Size Of the List after inserting at nth position is : ");
    printf("%d\n",size);
    return 0;
}
