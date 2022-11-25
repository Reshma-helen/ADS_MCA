#include<stdio.h>
#include<conio.h>

void push();
void pop();
void search();
void display();

struct node
{
	int val;
	struct node *next;
};

struct node *head=NULL;

void main()
{
	int choice;
	 clrscr();
	printf("\n Stack operations using linked list \n");
	while(1)
	{
		printf("\n\n 1.Push \n 2.Pop \n 3.Search \n 4.Display \n 5.Exit");
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:push();
			break;
		case 2:pop();
			break;
		case 3:search();
			break;
		case 4:display();
			break;
		case 5:exit(0);
			break;
		}
	}
}

void push()
{
	int val;
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("not able to push the element");
	}
	else
	{
		printf("Enter the value:");
		scanf("%d",&val);
		if(head==NULL)
		{
			ptr->val=val;
			ptr->next=NULL;
			head=ptr;
		}
		else
		{
			ptr->val=val;
			ptr->next=head;
			head=ptr;
		}
		printf("Item pushed");
	}
}

void pop()
{
	int item;
	struct node *ptr;
	if(head==NULL)
	{
		 printf("underflow");
	}
	else
	{
		item=head->val;
		ptr=head;
		head=head->next;
		free(ptr);
		printf("Item popped is %d",item);
	}
}

void display()
{
	int i;
	struct node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("stack is empty \n");
	}
	else
	{
		printf("Printing stack elements \n");
		while(ptr!=NULL)
		{
			printf("%d \t",ptr->val);
			ptr=ptr->next;
		}
	}
}
void search()
{       struct node *ptr;
	int item,i=0,flag;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n Empty list \n");
	}
	else
	{
		printf("\n enter the element which you want to search: ");
		scanf("%d",&item);
		while(ptr!=NULL)
		{
			if(ptr->val==item)
			{
				printf("item found at location %d",i+1);
				flag=0;
				break;
			}
			else
			{
			     flag=1;
			}
			i++;
			ptr=ptr->next;

		}
		if(flag==1)
		{
		printf("Item not found");
		}
	}

}

