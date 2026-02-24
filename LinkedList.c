#include <stdio.h>
#include <stdlib.h>

struct tnode
{
	int data;
	struct tnode *next;
};

typedef struct tnode node;

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

void popMid (int target)
{
	if (head == NULL)
	{
		return;
	}
	else if (head == tail && head->data == target)
	{
		free(head);
		head = tail = NULL;
	}
	else if (head->data == target)
	{
		popHead();
	}
	else if (tail->data == target)
	{
		popTail();
	}
	else
	{
		node *temp = head;
		while (temp->next != NULL && temp->next->data != target)
		{
			temp = temp->next;
		}

		if (temp->next == NULL)
		{
			puts("target tidak ada");
			return;
		}
		
		node *hapus = temp->next;
		temp->next = hapus->next;
		free(hapus);
	}
}

void viewAll()
{
	if (head == NULL)
	{
		puts("Kosong");
			return;
	}

	node *temp = head;
	while(temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}

	puts("");
}

int main ()
{	
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
