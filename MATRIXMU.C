
#include<stdio.h>
#include<conio.h>
int a[5][5],b[5][5],c[5][5],x,y,i,j,k;
void main()
{
clrscr();
printf("enter the number of rows and columns\n");
scanf("%d%d",&x,&y);
printf("enter the elements of first matrix\n");
for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("enter the elements of second matrix\n");
for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
{
scanf("%d",&b[i][j]);
}
}
printf("multipy matrix\n");
for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
{
for(k=0;k<y;k++)
{
c[i][j]=a[i][k]*b[k][j];
}
}
}
 printf(" matrix\n");
for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}
getch();
}