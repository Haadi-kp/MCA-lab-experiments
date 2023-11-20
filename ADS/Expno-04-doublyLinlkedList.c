#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}*head, *last;


struct Node* head = NULL;
struct Node* tail = NULL;


void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert.\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    if (tail == NULL) {
        tail = newNode;
    }
    printf("Inserted %d at the beginning.\n", value);
}


void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert.\n");
        return;
    }
    newNode->data = value;
    newNode->prev = tail;
    newNode->next = NULL;
    if (tail != NULL) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == NULL) {
        head = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}


void insertAtN(int data, int position)
{
    int i;
    struct Node * newNode, *temp;


    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;


        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }


        if(position == 1)
        {
            insertAtBeginning(data);
        }
        else if(temp == last)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));


            newNode->data = data;
            newNode->next = temp->next; 
            newNode->prev = temp;          


            if(temp->next != NULL)
            {

                temp->next->prev = newNode;
            }

            temp->next = newNode;


            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}


void deleteFromEnd()
{
    struct Node * toDelete;


    if(tail == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = tail;

        last = tail;
        last = last->prev; 

        if (last != NULL)
            last->next = NULL; 


        free(toDelete);       
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
    }
}



void deleteFromBeginning()
{
    struct Node * toDelete;


    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;


        head = head->next; 

        if (head != NULL)
            head->prev = NULL; 


        free(toDelete); 
        printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
    }
}

void deleteFromN(int position)
{
    struct Node *current;
    int i;


    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }


    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;


        free(current); // Delete the n node


        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}


int search(int value) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}


void display() {
    struct Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position,n;

    while (1) {
        printf("\n***************************************************\n");
        printf("\n1. Insert at the beginning\n2. Insert at the end\n3. Insert at position\n4. Delete From End\n5. Delete from beginning\n6. Delete From Position\n7. Search\n8. Display\n9. Quit\n");
        printf("\n***************************************************\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                 printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &value);


                insertAtN(value, n);
                break;

            case 4:
                deleteFromEnd();
                break;
            case 5:
                 deleteFromBeginning();
                 break;
            case 6:
                printf("Enter the node position which you want to delete: ");
                scanf("%d", &n);
                deleteFromN(n);
                break;
            case 7:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                position = search(value);
                if (position != -1) {
                    printf("%d found at position %d in the list.\n", value, position);
                } else {
                    printf("%d not found in the list.\n", value);
                }
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
    




