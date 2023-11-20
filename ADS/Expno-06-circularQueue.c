                                                                                                                                                                                                                                                                                                                                                                                                                                                  #include <stdio.h>
#include <stdlib.h>
int *queue;
int front = -1;
int rear = -1;
int size;
void initializeQueue();
int isFull();
int isEmpty();
void enqueue(int element);
int dequeue();
int searchElement(int element);
void displayQueue();

int main() {
    int choice, element, searchResult;

    printf("Enter the size of the Circular Queue: ");
    scanf("%d", &size);

    initializeQueue();

    do {
        printf("\n=================================");
        printf("\nCircular Queue Menu:\n\n");
        printf("1. Enqueue (Add element)\n");
        printf("2. Dequeue (Delete element)\n");
        printf("3. Search element\n");
        printf("4. Display Queue\n");
        printf("0. Exit\n");
        printf("=================================\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printf("\nEnter element to search: ");
                scanf("%d", &element);
                searchResult = searchElement(element);
                if (searchResult != -1) {
                    printf("\n%d found at position %d\n", element, searchResult);
                } else {
                    printf("\n%d not found in the queue\n", element);
                }
                break;

            case 4:
                displayQueue();
                break;

            case 0:
                printf("\nExiting the program.\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    free(queue);

    return 0;
}


void initializeQueue() {
    queue = (int *)malloc(size * sizeof(int));
}


int isFull() {
    return (front == (rear + 1) % size);
}
int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int element) {
    if (isFull()) {
        printf("\nQueue is full. Cannot enqueue %d\n", element);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = element;
    printf("\n%d enqueued to the queue\n", element);
}


int dequeue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is empty. Cannot dequeue\n");
        return -1;
    }

    element = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    printf("\n%d dequeued from the queue\n", element);
    return element;
}
int searchElement(int element) {
    if (isEmpty()) {
        printf("\nQueue is empty. Cannot search\n");
        return -1;
    }

    int current = front;
    int position = 1;

    do {
        if (queue[current] == element) {
            return position;
        }

        current = (current + 1) % size;
        position++;
    } while (current != (rear + 1) % size);

    return -1;  
}
void displayQueue() {
    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nQueue elements: ");
    int current = front;

    do {
        printf("\n%d ", queue[current]);
        current = (current + 1) % size;
    } while (current != (rear + 1) % size);

    printf("\n");
}



