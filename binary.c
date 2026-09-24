//Converting decimal value to binary value by using stack//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 10
struct stack //creates a stack//
{
    int top;
    int data[size];
};
typedef struct stack S;

void push(S *s,int item)//pushes the element to stack//
{
    s->data[++(s->top)]=item;
}

void convert(S *s,int n)//converts the given decimal value to binary//
{
 int r,q,i,re;
 re=n;
 while(n!=0)
 {
    q=n/2;
    r=n%2;
    push(s,r);
    n=q;
 }
 int x;
  if(s->top<3)// makes a 4digit representation//
  {
    x=s->top;
    while(x<3)
    {
    push(s,0);
    x++;
    }
  }  
//displays the binary value//
printf("\n%d in binary is  ",re);
for(i=s->top;i>-1;i--)
{
    printf("%d",s->data[i]);
}
}
 
void main()
{
    S s;
    s.top=-1;
    int n;
    printf("\nEnter the number to be converted: ");
    scanf("%d",&n);
    convert(&s,n);
}