#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define size 30
struct stack //creates a stack//
{
    int top;
    char data[size];
};
typedef struct stack S;

void push(S *s,char item)
{
    s->data[++(s->top)]=item;
}

char pop(S *s)
{
    return s->data[(s->top)--];
}

int preced(char symbol)
{
    switch(symbol)
    {
        case '^':return 3;
        case '*':
        case '/':
        case '%':return 2;
        case '+':
        case '-': return 1;
    }
}

void reverse(char prefix[size])
{
    int i,j;
    char te;
    j=strlen(prefix);
    for(i=0;i<j/2;i++)
    {
        te=prefix[i];
        prefix[i]=prefix[j-1-i];
        prefix[j-1-i]=te;
    }
}

void reverse1(char infix[size])
{
    int i,j;
    char te;
    j=strlen(infix);
    for(i=0;i<j/2;i++)
    {
        te=infix[i];
        infix[i]=infix[j-1-i];
        infix[j-1-i]=te;
    }
}

void toprefix(S *s,char infix[size])
{
    reverse1(infix);
    int i,j=0;
    char prefix[size],temp,symbol;
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        if(isalnum(symbol))
        {
            prefix[j++]=symbol;
        }
        else
        {
            switch(symbol)
            {
                case ')':
                    push(s,symbol);
                    break;
                case '(':
                    temp=pop(s);
                    while(temp!=')')
                    {
                        prefix[j++]=temp;
                        temp=pop(s);
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    if(s->top==-1 ||s->data[s->top]==')')
                    {
                        push(s,symbol);
                    }
                    else
                    {
                        while(preced(s->data[s->top])>=preced(symbol) && s->top!=-1 && s->data[s->top]!=')')
                        {
                            prefix[j++]=pop(s);

                        }
                        push(s,symbol);
                    }
                    break;
                default:printf("\nInvalid!!!");
                        exit(0);
            }
        }
    }
    while(s->top!=-1)
    {
        prefix[j++]=pop(s);
    }
    prefix[j]='\0';
    reverse(prefix);
    printf("\nThe prefix expression is %s\n",prefix);
}

void main()
{
    S s;
    s.top=-1;
    char infix[size];
    printf("\nRead infix expression: ");
    scanf("%s",infix);
    toprefix(&s,infix);
}