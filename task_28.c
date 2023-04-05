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
        printf("You cant delete this number\n");
    } else if (n >= count) {
        free(temp);
    }
    else {
        for (int i = 0; i < n; i++) {
            struct Node *del_nod = (*head_ref)->prev;
            del_nod->prev->next = *head_ref;
            (*head_ref)->prev = del_nod->prev;
            free(del_nod);
        }
    }
}



int main() {
    struct Node* MyList = NULL;
    int val;
    int x;
    printf("How elements you want add: ");
    scanf("%d", &x);
    if (x == 0) {
        printf("You cant write 0");
        getchar();
        exit(0);
    } else {
        for (int i = 0; i < x; i++) {
        scanf("%d", &val);
        push_front(&MyList, val);
    }
    PrintList(MyList);
    printf("How many elements from end you want delete: ");
    scanf("%d", &x);
    delete_n_element(&MyList, x);
    PrintList(MyList);
    }
    return 0;
}
