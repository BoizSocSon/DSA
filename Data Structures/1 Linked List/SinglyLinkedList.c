#include <stdio.h>
#include <stdlib.h> // Thêm thư viện này để sử dụng hàm malloc

struct ListNode
{
    int data;
    struct ListNode *next; 
};

typedef struct ListNode ListNode;

// Hàm đếm số lượng node có trong list
int ListLength(ListNode *head);

// Khai báo hàm InsertInLinkedList
void InsertInLinkedList(ListNode **head, int data, int position);
void DeleteNodeFromLinkedList(ListNode **head, int position);

int main(void) {
     // Example usage
    ListNode *head = NULL;

    // Insert nodes at the beginning
    InsertInLinkedList(&head, 7, 1);
    InsertInLinkedList(&head, 1, 1);
    InsertInLinkedList(&head, 3, 3);

    // Insert node at the end
    InsertInLinkedList(&head, 5, ListLength(head) + 1);

    // Print the linked list
    ListNode *current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    DeleteNodeFromLinkedList(&head, 1);
    ListNode *current2 = head;
    while (current2!= NULL) {
        printf("%d ", current2->data);
        current2 = current2->next;
    }

    return 0;
}

int ListLength(ListNode *head){
    ListNode *current = head;
    int length = 0;

    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

void InsertInLinkedList(ListNode **head, int data, int position){
    int k = 1;
    ListNode *p, *q, *newNode;
    newNode = (ListNode *)malloc(sizeof(ListNode));
    if(!newNode){
        printf("Khong du bo nho de cap phat");
        return;
    }
    newNode->data = data;
    p = *head;
    if(position == 1){
        newNode->next = p;
        *head = newNode;
    }
    else{
        while((p!=NULL) && (k<position)){
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
    }
}

void DeleteNodeFromLinkedList(ListNode **head, int position){
    int k = 1;
    ListNode *p, *q;
    if(*head == NULL){
        printf("List Empty");
        return;
    }
    p = *head;
    if(position == 1){
        *head = p->next;
        free(p);
    }
    else{
        while((p!=NULL) && (k<position)){
            k++;
            q = p;
            p = p->next;
        }
        if(p == NULL)
        {
            printf("Khong tim thay node can xoa");
            return;
        }
        else{
            q->next = p->next;
            free(p);
        }
    }
}


int main() {
    ListNode *list1 = NULL;
    ListNode *list2 = NULL;
    ListNode *merge_list = NULL;

    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 4);

    insertAtEnd(&list2, 1);
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 4);

    printList(list1);
    printf("\n");
    printList(list2);
    printf("\n");
   

    return 0;
}