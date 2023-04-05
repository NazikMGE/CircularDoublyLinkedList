#include <stdio.h>
#include <stdlib.h>
//node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void push_front(struct Node** head_ref, int newElement) {  
    struct Node *newNode, *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node)); 
        newNode->data = newElement;  
        newNode->next = NULL;
        newNode->prev = NULL;
        if(*head_ref == NULL) {
            *head_ref = newNode;
            newNode->next = *head_ref;
            newNode->prev = *head_ref;
    } else {
    temp = *head_ref;
    while(temp->next != *head_ref) {
        temp = temp->next;
    }    
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = *head_ref;
    (*head_ref)->prev = newNode;
    *head_ref = newNode;
    }

}

//display the content of the list
void PrintList(struct Node* head_ref) {
    struct Node* temp = head_ref;
    if(head_ref != NULL) {
    printf("The list contains: ");
    while (1) {
        printf("%i ",temp->data);
        temp = temp->next;
        if(temp == head_ref)
        break;    
    }
    printf("\n");
    } else {
    printf("The list is empty.\n");
    }   
}

void delete_n_element(struct Node **head_ref, int n) {

    if (*head_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = *head_ref;
    
    int count = 1;

    while ( temp->next != *head_ref) {
        temp = temp->next;
        ++count;
    }

    if (n > count) {
        printf("You cant delete this number");
    } else {
        for (int i = 0; i < n; i++) {
            struct Node *del_nod = (*head_ref)->prev;
            del_nod->prev->next = *head_ref;
            (*head_ref)->prev = del_nod->prev;
            free(del_nod);
        }
    }
}

// test the code 
int main() {
    struct Node* MyList = NULL;
    int val;
    for (int i = 0; i < 7; i++) {
        scanf("%d", &val);
        push_front(&MyList, val);
    }
    // PrintList(MyList);
    delete_n_element(&MyList, 2);
    PrintList(MyList);
    return 0; 
}