#include<stdio.h>
#include<conio.h>

void main()
{
clrscr();
int a[50],b[50],c[100],m,n,i,j,k;
printf("\n enter the size of array:");
scanf("%d",&m);

printf("enter sorted array elments:\n");
for(i=0;i<m;i++)
{
scanf("%d",&a[i]);
}


printf("\n enter the size of second array:");
scanf("%d",&n);

printf("enter sorted array elments:\n");
for(i=0;i<n;i++)
{
scanf("%d",&b[i]);
}
i=j=k=0;
while(i<m && j<n)
{
if(a[i]<b[j])
{
c[k]=a[i];
i++;
}
else if(a[i]>b[j])
{
c[k]=b[j];
j++;
}
else
{
c[k]=a[i];
i++;
j++;
}

k++;
}
while(i<m)
{
c[k]=a[i];
i++;
k++;

}
while(j<n)
{
c[k]=b[j];
j++;
k++;
}

printf("\n After merging:\n");
for(i=0;i<m+n;i++)
{
printf("\n%d\t",c[i]);
}
getch();
}
