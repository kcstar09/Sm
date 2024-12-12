#include<stdio.h>
int rem(int,int);
void main()
{
int i,j,k,d,dl;
int data[10],div[5],newdata[15],crc[5],datacrc[15],revdata[15],remd[5];
printf("\n Enter the data length= ");
scanf("%d",&d);
printf("\n Enter the divisor length= ");
scanf("%d",&dl);
printf("\n Enter the data : ");
for(i=0;i<d;i++)
scanf("%d",&data[i]);
printf("\n Enter the divisor : ");
for(i=0;i<dl;i++)
scanf("%d",&div[i]);
printf("\n The new data is : ");
for(i=0;i<(d+dl-1);i++)
{
if(i<d)
newdata[i]=data[i];
else
newdata[i]=0;
printf("%d",newdata[i]);
}
for(j=0;j<=d;j++)
{
for(i=0;i<dl;i++)
{
crc[i]=newdata[i+j];
if(crc[0]==1)
newdata[i+j]=rem(newdata[i+j],div[i]);
else
newdata[i+j]=rem(newdata[i+j],0);
}
printf("\n The Crc is : ");
for(i=0;i<dl-1;i++)
printf("%d",crc[i]);
}
printf("\n The data to be send is : ");
for(i=0;i<(d+dl-1);i++)
{
if(i<d)
datacrc[i]=data[i];
else
datacrc[i]=crc[i-d];
printf("%d",datacrc[i]);
}
printf("\n Enter the receiver side data : ");
for(i=0;i<(d+dl-1);i++)
scanf("%d",&revdata[i]);
for(j=0;j<=d;j++)
{
for(i=0;i<dl;i++)
{
remd[i]=revdata[i+j];
if(remd[0]==1)
revdata[i+j]=rem(revdata[i+j],div[i]);
else
revdata[i+j]=rem(revdata[i+j],0);
}
printf("\n The reminder is : ");
k=0;
for(i=0;i<dl-1;i++)
{
printf("%d",remd[i]);
if(remd[i]==0)
k++;
}
}
if(k==dl-1)
printf("\n There is no error found.");
else
printf("\n There is error found.");
}
int rem(int x, int y)
{
if(x==y)
return 0;
else
return 1;
}