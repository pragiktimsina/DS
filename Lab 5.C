//evaluation of postfix expression
#include<stdio.h> 
#include<conio.h> 
#include<math.h> 
#include<ctype.h> 
int compute(char symbol,int op1,int op2) 
{
    switch(symbol)
    {
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;
        case '$':
        case '^':return pow(op1,op2);
    }
    
}

void main()
{
    
    int s[20],op1,op2,res;
    int i,top; 
    char postfix[20], symbol;
    clrscr(); 
    top=-1; 
    printf("Enter the postfix expression\n"); 
    gets(postfix);
    
    for(i=0;i<strlen(postfix);i++) 
    {
        symbol=postfix[i];
        if(isdigit(symbol)) 
        {
            top=top+1;
            s[top]=symbol-'0';
        }
        
        else
        {
            op2= s[top--];
            op1=s[top--];
            res=compute(symbol,op1,op2); 
            top=top+1; 
            s[top]=res; 
        }
        
    }
    res=s[top--];
    printf("the result is %d\n",res); 
    getch(); 
} 
