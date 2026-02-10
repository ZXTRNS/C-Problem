#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
	int data;
	struct node *next;
}node;

// create nodes
	node *head = NULL;
	node *tail = NULL;

node *create_node(int x)
{
	node *curr = (node *)(malloc(sizeof(node)));
	
	curr->data = x;
	curr->next = NULL;
	
	return curr;
}

void pushHead (node *curr)
{
	if (head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		curr->next = head;
		head = curr;
	}
}

void pushTail (node *curr)
{
	if (head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		tail->next = curr;
		tail = curr;
	}
}

//push mid itu sorted, dengan head = kecil, tail = besar
void pushMid (node *curr)
{
	if (head == NULL)
	{
		head = tail = curr;
	}
	else if (curr->data < head->data)
	{
		pushHead(curr);
	}
	else if (curr->data > tail->data)
	{
		pushTail(curr);
	}
	else
	{
		node *temp = head;
		
		while (curr->data > temp->next->data)
		{
			temp = temp->next;
		}
		
		curr->next = temp->next;
		temp->next = curr;
	}
}

void popHead ()
{
	if (head == NULL)
	{
		return;
	}
	else if (head == tail)
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		node *hapus = head;
		head = hapus->next;
		free(hapus);
	}
}

void popTail ()
{
	if (tail == NULL)
	{
		return;
	}
	else if (tail == head)
	{
		free(tail);
		tail = head = NULL;
	}
	else
	{
		node *temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		
		node *hapus = tail;
		tail = temp;
		tail->next = NULL;
		free(hapus);
	}
}

void popMid ()
{
	
}

int main ()
{	
	// allocate memory
	head = (struct node *)malloc(sizeof(struct node));
	tail = (struct node *)malloc(sizeof(struct node));
	
	// check allocation
	if (!head || !tail) {
		printf("memory allocation failed \n");
		return 1;
	}
	
	return 0;
}
