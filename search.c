#include "stdlib.h"
#include "stdio.h"

struct node {
    int info;
    struct node *link;
};

struct node *insertInEmpty(struct node *start, int info);
struct node *insertAtEnd(struct node *start, int info);
struct node *createList(struct node *start);
void showList(struct node *start);
void searchList(struct node *start, int x);

int main(){
    int choice, x;

    struct node *start;
    start = (struct node *)malloc(sizeof(struct node));
    start = NULL;

    start = createList(start);
    showList(start);

    while(1){
        printf("Enter 0 to search for an element in the list\n");
        printf("Enter 1 to quit the program\n");
        scanf("%d", &choice);

        if(choice){
            break;
        }
        else{
            printf("Please enter the number that you would like to search for\n");
            scanf("%d", &x);
            searchList(start, x);
        }

    }
}

struct node *insertInEmpty(struct node *start, int info){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info;

    temp->link = start;
    start = temp;

    return start;
}

struct node *insertAtEnd(struct node *start, int info){
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info;

    p = start;
    while(p->link != NULL){
        p = p->link;
    }

    p->link = temp;
    temp->link = NULL;

    return start;
}

struct node *createList(struct node *start){
    int info, n;

    printf("Please enter the size of the list\n");
    scanf("%d", &n);

    printf("Please enter the data that you would like to store in node 1\n");
    scanf("%d", &info);
    start = insertInEmpty(start, info);

    for(int i = 1; i < n; i++){
        printf("Please enter the data that you would like to store in node %d\n", i+1);
        scanf("%d", &info);
        start = insertAtEnd(start, info);
    }

    return start;
}

void showList(struct node *start){
    struct node *p;

    p = start;
    while(p != NULL){
        printf("%d | ", p->info);
        p = p->link;
    }
    printf("\n");
}

void searchList(struct node *start, int x){
    struct node *p;
    int count = 0; 

    p = start;
    while(p->link != NULL){
        count++;
        if(p->info == x){
            printf("%d was found at node %d", x, count);
        }
        p = p->link;
    }
    printf("\n");
}

