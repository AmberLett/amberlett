/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h> 
 
typedef struct node {  
 int data;  
 struct node* next;  
} node;  
 
void markEven(node* head) { // dont have to use "struct node* head" because typedef was used!!

   node *temp= head; // make a temporary node to go through the link list and set it to head to start the search for even nums
   
   while (temp!=NULL){ // check to make sure the temp is not null 
   if (temp->data %2 == 0 ){ // check if temp is even and if so do the following within the if statement 
   
   node* newNode= (node*)malloc(sizeof(node)); // allocate space for the newNode of value -1 to be inserted inside the list 
   
   newNode->data= -1; // set the value of the data inside the node of the newNode to -1 
   
   newNode->next=temp->next; // the newNode next link needs to be connected to temps next so its inserted behind the even number in the link list
   
   temp->next= newNode; // temp next needs to be linked to newNode so the newNode is successful added in behind the even data value 
   
   temp= newNode->next; // temp node now needs to be linked to the node after the inserted newNode of -1 to check the next node in the link list and evaluate back through the loop 
   
   }
   
   else{
       
       temp=temp->next; // points to temp's next if its odd and goes back through the while loop 
     }  
   
   }
    
}
 
void deallocateList(node** head) 
{ 
 node* tmp = *head; 
  
 while (tmp != NULL) 
 { 
  *head = tmp->next; 
  free(tmp); 
  tmp = *head; 
 } 
  
 *head = NULL; 
} 
 
int insertList(node** head, int data) 
{ 
 node* newNode = (node*) malloc(sizeof(node)); 
  
 if (newNode == NULL) 
  return -1; 
  
 newNode->data = data; 
 newNode->next = NULL; 
  
 newNode->next = *head; 
 *head = newNode; 
  
 return 1; 
} 
 
 
void printList(node* head) 
{ 
 node* tmp = head; 
  
 while (tmp != NULL) 
 { 
  printf("%d",tmp->data); 
  if (tmp->next != NULL) 
  { 
   printf(", "); 
  } 
  else 
  { 
   printf(".\n"); 
  } 
  tmp = tmp->next; 
 } 
} 
 
int main(void) 
{ 
 node* head = NULL; 
  
 insertList(&head, 8); 
 insertList(&head, 3); 
 insertList(&head, 1); 
 insertList(&head, 7); 
 insertList(&head, 6); 
 insertList(&head, 2); 
  
 printf("Initial List:\n"); 
 printList(head); 
 markEven(head); 
 printf("Marked List:\n"); 
 printList(head); 
  
 deallocateList(&head); 
}