#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int data;

    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

node *create_node (int p){
    node *curr = (node *)(malloc(sizeof(node)));

    curr->data = p;

    curr->next = NULL;

    return curr;
}

void pushHead(node *curr)
{
    if (head == NULL){
        head = tail = curr;
    }
    else{
        curr->next = head;
        head = curr;
    }
}

void pushTail(node *curr){
    if (tail == NULL){
        head = tail = curr;
    }
    else{
        tail->next = curr;
        tail = curr;
    }
}

void pushMid(node *curr){
    if (head == NULL){
        head = tail = curr;
    }
    else if (curr->data < head->data){
        pushHead(curr);
    }
    else if (curr->data > tail->data){
        pushTail(curr);
    }
    else{
        node *temp = head;
        while (curr->data > temp->next->data){
            temp = temp->next;
        }
        
        curr->next = temp->next;
        temp->next = curr;
    }
}

void popHead(){
    if (head == NULL){
        puts("Tidak ada data...");
        return;
    }
    else if (head == tail){
        free(head);
        head = tail = NULL;
        return;
    }
    else{
        node *toDelete = head;
        head = head->next;
        free(toDelete);
    }
}

void popTail(){
    if (head == NULL){
        puts("Tidak ada data...");
        return;
    }
    else if (head == tail){
        free(head);
        head = tail = NULL;
        return;
    }
    else{
        node *temp = head;
        while (temp->next != tail){
            temp = temp->next;
        }

        node *toDelete = tail;
        tail = temp;
        tail->next = NULL;
        free(toDelete);
    }
}

void popMid(int target){
    if (head == NULL){
        puts("Tidak ada data...");
        return;
    }
    else if (head == tail && head->data == target){
        free(head);
        head = tail = NULL;
        return;
    }
    else if (head->data == target){
        popHead();
        return;
    }
    else{
        node *temp = head;
        while (temp->next != NULL && temp->next->data != target){
            temp = temp->next;
        }

        if (temp->next == NULL){
            puts("Tidak ada data...");
            return;
        }

        node *toDelete = temp->next;
        if (toDelete == tail){
            tail = temp;
        }
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void viewAll(){
    if (head == NULL){
        puts("Tidak ada data...");
        return;
    }
    else{
        node *temp = head;
        int count = 0;
        while (temp != NULL){
            count++;
            printf("%d. ( %d )\n", count, temp->data);
            temp = temp->next;
        }
    }
    puts(" ");
}

int main(){
    pushHead(create_node(4));
	pushTail(create_node(9));
	pushMid(create_node(10));
	viewAll();
	
	popHead();
	viewAll();
	
	popTail();
	viewAll();
	
	popMid(9);
	viewAll();


    return 0;
}