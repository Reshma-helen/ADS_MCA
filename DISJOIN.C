#include<stdio.h>
#include<stdlib.h>

struct DisJoint{
	int parent[10];
	int rank[10];
	int n;
}dis;

void makeset()
{
	int i;
	for(i=0;i<dis.n;i++){
		dis.parent[i]=i;
		dis.rank[i]=0;
	}
}

void display()
{
	int i;
	printf("\nParent");
	for(i=0;i<dis.n;i++)
	{
		printf("%d\t",dis.parent[i]);
	}
	printf("\nRank");
	for(i=0;i<dis.n;i++)
	{
		printf("%d\t",dis.rank[i]);
	}
}

int find(int x)
{
	if(dis.parent[x]!=x)
	{
		dis.parent[x]=find(dis.parent[x]);
	}
	return dis.parent[x];
}

void Union(int x,int y)
{
	int setx=find(x);
	int sety=find(y);
	if(setx==sety)
		return;
	if(dis.rank[setx]>dis.rank[sety])
	{
		dis.parent[sety]=setx;
		dis.rank[sety]=-1;
	}
	else if(dis.rank[setx]<dis.rank[sety])
	{
		dis.parent[setx]=sety;
		dis.rank[setx]=-1;
	}
	else
	{
		dis.parent[sety]=setx;
		dis.rank[setx]+=1;
		dis.rank[sety]=-1;
	}
}

void main()
{
	int choice,x,y;
	while(1)
	{
		printf("\nDisjoint Set Operations");
		printf("\n------------------------");
		printf("\n1.Make Sets");
		printf("\n2.Find");
		printf("\n3.Union");
		printf("\n4.Display");
		printf("\n5.Exit");
		printf("\nEnter your choices:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:printf("\nEnter no of elements in a set:");
				scanf("%d",&dis.n);
				makeset();
				break;
			case 2:printf("\nEnter two elements to find they are connected:");
				scanf("%d%d",&x,&y);
				if(find(x)==find(y))
					printf("\n%d and %d are connected to a single leader %d",x,y,find(x));
				else
					printf("\nDisconnected components");break;
			case 3: printf("\nEnter two elements to perform union:");
				scanf("%d%d",&x,&y);
				Union(x,y); break;
			case 4:display();
				 break;
			case 5:exit(1);
		}
	}
}