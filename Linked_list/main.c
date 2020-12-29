// Linked List Implementation
// This program contains function to add a node at the end of the list, to dequeue the last element from the list, insert a node at a particular position, delete an nth node 
// and reverse the linked list. And of course, printing the output.

// The main focus was implementing the linked list. The size (to print) increments even if the input is INVALID. But it can be fixed by adding some additional loops.

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

    node* temp = (node*)malloc(sizeof(node*)); // temporary node to traverse the list.

    // If the node to be entered is at the first position
    if(n == 1){
       temp->data = val; // Copy the value in the node.
       temp->link = head; // Point to the previous head.
       head = temp; // Make this new node the head node.
    }
    else{
        // create two temporary nodes.
        node* temp1 = (node*)malloc(sizeof(node*));
        node* temp2 = (node*)malloc(sizeof(node*));
        temp1 = head; // head is also copied in the temp1
        int i = 1; // counter
        while(1){

            if(i == n){ // if we have reached the position
                temp->data = val; // Copy the value
                temp->link = temp1; // Make link to the next node
                temp2->link = temp; // Make link from previous node to new node
                return;
            }

            temp2 = temp1; // Store previous node
            temp1 = temp1->link; // Go to the next node
            i++; // Increment counter
            // This case considers if the position entered is beyond the last node.
            // In this case a node will added at the end.
            if(temp1->link == NULL){
                temp->data = val;
                temp->link = NULL;
                temp1->link = temp;
                return;
            }
        }
    }
 }

// This function deals with deleting a node at a specific position.
 void del_at_n(int pos){
    // Create three temporary nodes to store nodes
    node* temp = (node*)malloc(sizeof(node));
    node* temp1 = (node*)malloc(sizeof(node));
    node* temp2 = (node*)malloc(sizeof(node));

    temp = head; // start with the head node

    // If the head node is to be deleted.
    if(pos == 1){
        temp1 = temp; // copy the head node again
        temp = temp->link; // go to the enxt node.
        head = temp; // next node is the head node
        free(temp1); // Free memory so that it can be used.
        return;
    }
    // If not then iterate till pos-1
    for(int i = 1; i<pos-1; i++){
        temp = temp->link; // Find the node to be deleted

    }
    temp1 = temp; // Copy the node = C-Node
    temp = temp->link; // Next node = node to be deleted
    temp2 = temp; // Copy the node to be deleted = D-Node
    temp = temp->link; // Node after the one to be deleted = V-Node
    temp1->link = temp; // Join C- Node and V- Node.
    free(temp2);// Free memory of D-Node.
 }

// To reverse a Linked List use this function.
 void reverse(){
    // Create three temporary nodes to store....
    node* temp = (node*)malloc(sizeof(node)); // current node
    node* temp1 = (node*)malloc(sizeof(node)); // next node
    node* temp2 = (node*)malloc(sizeof(node)); // previous node

    temp = head; // Start with the head node
    temp1 = temp->link; // Copy the next node
    temp->link = NULL; // Current head node will point to NULL. Since it is the last node.

    while(temp1->link != NULL){ // Iterate till node that points to last node is found.
    temp2 = temp; // Copy previous node.
    temp = temp1;// Current node
    temp1 = temp1->link; // Next node
    temp->link = temp2; // Change link of previous node and current node
    }
    head = temp1; // New head is last node
    head->link = temp; // New head node will point to the previous node.

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

    printf("What is the position of the element you wish to delete in the Linked List : \n");
    scanf("%d", &pos);
    del_at_n(pos);
    size--;
    printf("After Deleting the nth node, the Linked list is : \n");
    if (size>0) Print(); // Print elements in the linked list.
    else printf("No elements...\n");
    printf("Size Of the List after deleting nth node is : ");
    printf("%d\n",size);

    reverse();
    printf("After Reversing, the Linked list is : \n");
    if (size>0) Print(); // Print elements in the linked list.
    else printf("No elements...\n");

    return 0;
}
