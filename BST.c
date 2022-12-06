#include<stdio.h>
#include<stdlib.h>

struct btnode
{ 
    int value;
    struct btnode*l;
    struct btnode*r;
}*root=NULL,*temp=NULL,*t,*t1,*t2;

int data,data1,flag=1;

void insert();
void delete();
void delete1();
void inorder();
void create();
void preorder();
void postorder();
int smallest();
int largest();
int get_data();
void search();
void search1();
int searchv(int);

void main()
{ 
    int ch;
    printf("\n---OPERATIONS---");
    printf("\n1.Insert \n 2.Delete \n 3.InOrder Traversal \n 4.PreOrder Traversal \n 5.PostOrder Traversal  \n 6.Search \n 7-Exit");  
    while(1)
    {
        printf("\nEnter your choice:"); 
        scanf("%d",&ch);
        switch(ch)
        { 
            case 1: insert(); 
                     break;
            case 2: delete();
                     break; 
            case 3: inorder(root);
                     break; 
            case 4: preorder(root);
                     break; 
            case 5: postorder(root);
                     break; 
            case 6:data1=get_data();
                    if(searchv(data1)==1)
                    {
                        printf("Data found! \n");
                    }
                    else
                    {
                        printf("\n Data does not found! \n");
                    }
                    break;
            case 7: exit(0);
            default: printf("Wrong choice,Please enter correct choice");
                     break;
        }
    }
}

void insert()
{ 
    create(); 
    if(root==NULL)
    root=temp;
    else
    search(root);
}
void create()
{ 
    int data;
    printf("Enter data of node to be inserted:");
    scanf("%d",&data);
    temp=(struct btnode*)malloc(1*sizeof(struct btnode)); 
    temp->value=data; 
    temp->l=temp->r=NULL;
}
void search(struct btnode *t)
{
    if(((temp->value)>(t->value))&&(t->r!=NULL))
    search(t->r);
    else if((temp->value>t->value)&&(t->r==NULL))
    t->r=temp;
    else if((temp->value<t->value)&&(t->l!=NULL))
    search(t->l);
    else if((temp->value<t->value)&&(t->l==NULL))
    t->l=temp;
}
void inorder(struct btnode *t)
{ 
    if(root==NULL)
    {
    printf("No elements in a tree to display");
    return;
    } 
    if(t->l!=NULL)
        inorder(t->l); 
    printf("%d->",t->value); 
    if(t->r!=NULL) 
        inorder(t->r);
}
void delete()
{ 
    int data; 
    if(root==NULL)
    {
        printf("No elements in a tree to delete");
        return;
    }
    printf("Enter the data to be deleted:"); 
    scanf("%d",&data);
    t1=root; 
    t2=root;
    search1(root,data);
}

void preorder(struct btnode *t)
{ 
    if(root==NULL)
    {
    printf("No elements in a tree to display: ");
    return;
    }
    printf("%d->",t->value);  
    if(t->l!=NULL) 
        preorder(t->l); 
    if(t->r!=NULL)
        preorder(t->r);
}

void postorder(struct btnode *t)
{ 
    if(root==NULL)
    {
        printf("No elements in a tree to display:");
        return;
    }
    if(t->l!=NULL)
        postorder(t->l); 
    if(t->r!=NULL)
        postorder(t->r);
    printf("%d->",t->value);
}


void search1(struct btnode *t,int data)
{
    if((data>t->value))
    { 
        t1=t;
        search1(t->r,data);
    } 
    else if((data<t->value))
    { 
         t1=t;
        search1(t->l,data);
    }
    else if((data==t->value))
    { 
        delete1(t);
    }
}

void delete1(struct btnode *t)
{ 
    int k;
    if((t->l==NULL)&&(t->r==NULL))
    { 
    if(t1->l==t)
    {
        t1->l=NULL;
    }
    else
    {
    t1->r=NULL;
    }
    t=NULL;
    free(t);
    return;
    }
    else if((t->r==NULL))
    { 
        if(t1==t)
        { 
            root=t->l;
            t1=root;
        }
        else if(t1->l==t)
        { 
            t1->l=t->l;
        } 
        else
        { 
            t1->r=t->l; 
        }
        t=NULL;
        free(t);
        return;
    }
    else if(t->l==NULL)
    { 
        if(t1==t)
        { 
            root=t->r; t1=root;
        }
        else if(t1->r==t)
            t1->r=t->r;
        else 
            t1->l=t->r; 
        t==NULL;
        free(t);
        return;
    }
    else if((t->l!=NULL)&&(t->r!=NULL))
    { 
        t2=root;
        if(t->r!=NULL)
        { 
        k=smallest(t->r);
        flag=1; 
        }   
        else
        { 
            k=largest(t->l);
            flag=2;
        }
        search1(root,k);
        t->value=k;
        }
}

int smallest(struct btnode *t)
{ 
    t2=t; 
    if(t->l!=NULL)
    {
        t2=t;
        return(smallest(t->l));
    }
    else
        return(t->value);
}

int largest(struct btnode *t)
{ 
    if(t->r!=NULL)
    { 
        t2=t;
        return(largest(t->r));
    } 
    else
        return(t->value);
}

int searchv(int key)
{
  temp=root;
  while(temp!=NULL)
  {
      if(key==temp->value)
      {
          return 1;
      }
      else if(key>temp->value)
      {
          temp=temp->r;
      }
      else
      {
          temp=temp->l;
      }
    }
      return 0;
}

int get_data()
{
 printf("\nEnter Data: ");
 scanf("%d", &data);
 return data;
} 
