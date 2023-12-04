
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top=0;

struct node* createNode(int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL){
        printf("Underflow");
    }
    else{
        newnode->data=value;
        newnode->next=top;
    }
    return newnode;
}
void push(int value){
    struct node* newnode= createNode(value);
    top=newnode;
    
}
void pop(){
    struct node* temp=top;
    if(top==0){
        printf("Stack is empty, unable to pop");
    }
    else{
    printf("popped element is %d",top->data);
    top=top->next;
    free(temp);
    }
}

void display (){
   struct node* temp=top;
    while(temp!= 0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
 int choice,value ;
  do{
    printf("Select \n");
    printf("1. Push\n2. Pop\n3. Display\n4. Search\n0. Exit\n");
    printf("Enter your choice : ");
    scanf("%d",& choice);
    switch( choice){
     case 1:
         printf("Enter value to push");
         scanf("%d",&value);
         push(value);
         break;
     case 2:
         pop();
         break;
     case 3:
         display();        
         break;
     case 4:
         //search ();      
         break;
     case 0:
         exit(0);  
    }
    }while(choice!= 0);
    
    return 0;
}
