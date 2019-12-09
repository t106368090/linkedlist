#include	<stdio.h>
#include	<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node Node;
Node *first, *current, *previous; 


void shownode(Node* head)
{
	printf("Data: ");
	while(head != NULL)
	{
		//printf("address = %p, ",current);
		printf("%d ",head->data);
		//printf("next = %p\n",current->next);
		head = head->next;
	}
	printf("\n");
	return;
}

void createnode(int *num)
{
	int	i;
	for(i=0; i<*num; i++)
	{
		current = (Node*)malloc(sizeof(Node));
		printf("Data for node %d: ",i+1);
		scanf("%d",&(current->data));
		if(i == 0)
		{
			first = current;
		}
		else
		{
			previous->next = current;
		}
		current->next = NULL;
		previous = current;
	}
	current = first;
	return;
}

void addone(int* data,char* select)
{
	Node *new;
	
	new = (Node*)malloc(sizeof(Node));
	new->data = *data;
	current = first;
	
	if(select == "begin")
	{
		new->next = current;
		first = new;
	}
	if(select == "end")
	{
		current = first;
		while(current != NULL)
		{
			current = current->next;
		}	
		
		new->next = current;
		if(current == first)
		{
			first = new;
		}
		else
		{
			previous->next = new;
		}
	}

	return;
}

void swap(Node *a, Node *b) 
{ 
	int temp = a->data; 
	a->data = b->data; 
	b->data = temp; 
} 

void bubbleSort() 
{ 
	int swapped, i; 
	Node *p1; 
	Node *last = NULL; 
  
    /* Checking for empty list */
	if (start == NULL) 
	
	return; 
  
	do
	{ 
		swapped = 0; 
		p1 = first; 
  
		while (p1->next != last) 
		{ 
			if (p1->data > p1->next->data) 
			{  
				swap(p1, p1->next); 
				swapped = 1; 
			} 
			p1 = p1->next; 
		} 
		last = p1; 
	} 
	while (swapped); 
} 



int main()
{
	int num, b;
	
	printf("Number of Node: ");
	scanf("%d",&num);
	createnode(&num);
	bubbleSort(first);
	shownode(first);
	
	printf("Insert: ");
	scanf("%d",&b);
	addone(&b,"begin");
	addone(&b,"end");
	bubbleSort(first);
	shownode(first);
	
	
	return 0;
}
