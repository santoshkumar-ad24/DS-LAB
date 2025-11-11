#include <stdio.h>
// #include <stdlib.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull();
int isEmpty();
void enQueue(int);
int deQueue();
void display();

int isFull(){
    if((front == rear +1) || (front == 0 && rear == SIZE -1)){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if (front == -1){
        return 1;
    }
    return 0;
}

void enQueue(int element){
    if (isFull()){
        printf("\n Queue is full!!");
    }
    else {
        if(front == -1) front =0;
        rear = (rear +1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d \n", element);
    }
}

int deQueue(){
    int element;
    if (isEmpty()){
        printf("\n Queue is empty !! \n");
        return (-1);
    }
    else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }

        else {
            front = (front + 1)% SIZE;
        }
        printf("\n Deleted element -> %d \n", element);
        return (element);

    }
}

void display(){
    int i;
    if (isEmpty())
        printf("\n Empty Queue\n");
    else{
        printf("\n Front -> %d", front);
        printf("\n Items -> \n");
        for(i = front; i!= rear; i =(i+1)%SIZE){
            printf("%d \n", items[i]);
        }
        printf("%d", items[i]);
        printf("\n Rear -> %d \n", rear);
    }
}

int main(){
    int choice,value;
    while(1){
        printf("***MENU***\n");
        printf("1. Display\n2. Insert\n3. Delete\n4. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: display();
                    break;
            case 2: printf("Enter your value to insert into circular QUeue: ");
                    scanf("%d", &value);
                    enQueue(value);
                    break;
            case 3: deQueue();
                    break;
            case 4: exit(0);
                    break;
            default: printf(" Enter Valid Choice!!! \n");
        }
    }
    return 0;
}
