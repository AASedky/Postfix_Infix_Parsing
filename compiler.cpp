#include<conio.h>
#include<string.h>
#include"stacklink.h"
#include<iostream>
using namespace std;
int precedence(char o)
{
	if(o=='*'||o=='/')
		return 5;
	else if (o=='+'||o=='-')
		return 4;
else if (o=='<'||o=='>'||o=='=')
		return 3;
else if(o=='(')
    return 2;


}
void cov_postfix(stack *a,char b[],char m[])
{     
	int i=2,j=1,com,com1,bract=0,c; 
	m[0]=b[0];
	push(*a,b[i]);
	i++;
	while(b[i]!=NULL)
	{ 
		if (b[i]=='(')
		{
			push(*a,b[i]);
			i++;
			bract++;
		}
		else if(b[i]==')')
		{
			 while(empty(*a)!=0)///pop all between (<---------->)
		   {
			   c=top(a);
			   if(c=='(')
			   {
				   pop(*a,&c);
				   break;
			   }
			   else { 
				   c=pop(*a,&c);
				   m[j]=c;
				  j++;
			          }
			 }
		i++;}

	 
		else  if(b[i]=='+'||b[i] =='-'||b[i]=='*'||b[i]=='/')
		 {
			if(empty(*a)==0) 
			{  push(*a,b[i]);
			i++;
			}
			else
			{
				c=top(a);
				com=precedence(c);//compare
				com1=precedence(b[i]);//compare
				if(com<com1)
				{
					push(*a,b[i]);
					i++;
				}
			  else {
			  c=pop(*a,&c);
			  m[j]=c;
			  j++;}	
				} 
	          }
		 else  
		 {         
			  m[j]=b[i];
			  j++;
			  i++;
		 }
	    } 

	 while(empty(*a)!=0)
		  {
		 c=pop(*a,&c);
		 m[j]=c;
		 j++;
	 } 
	 //printf("%d\n",bract);
	 if (bract!=0)
	m[strlen(b)-(2*bract)]=NULL;
	 else 
     m[strlen(b)]=NULL;}
//============================================
int ch_int(char n)//convert character to  int number note:one digit
{
int x=n;
x=x-'0';
return x;
	 
}
//=======================================
int eva_post(stack &a, char m[])
{
	int eva=0,u,w,v,i,zyada;
	for (i=2;i<strlen(m);i++)
	{
		zyada=i+1;
		m[zyada]=NULL;
		  if(m[i]=='+')
		{
			w=pop(a,&w);
			v=pop(a,&v);
			eva=w+v ;
			push(a,eva);	 
		}
		  else if (m[i]=='-')
		{
			w=pop(a,&w);
			v=pop(a,&v);
			eva=v-w ;
			push(a,eva);
		}
		  else  if(m[i]=='*')
		{
			w=pop(a,&w);
			v=pop(a,&v);
			eva=w*v ;
			push(a,eva);
		}
		  else  if(m[i]=='/')
		{
			w=pop(a,&w);
			v=pop(a,&v);
			eva=v/w ;
			push(a,eva);	 
		}
		  else {
			u=ch_int(m[i]);
			 push(a,u);
			 }	 
	}
return eva;
}
////////////////
bool isChar(char x)
{
	int ch=x-'a';
	int ch1=x-'A';
	  if((ch>=0&&ch<=25) ||(ch1>=0&&ch1<=25))
	  {
		  return true;
	  }
	  return false;
}
bool isOperator(char x)
{
	switch (x)
	{
	case '*':
		printf("MUL ");
		 return true;
	case '+':
		printf ("ADD ");
		return true;
	case '-':
		printf("NEG ");
		return true;
	case '/':
		printf("DIV ");
		return true;
	default:
		return false;

		
	}
}
void recursive_decent(char *x)
{


	char * output=new char[100];
	int index=0;
	//replace(x);
	 printf("LIT %c ",x[0]);
	for(int i=1;x[i]!=NULL;i++)
	{   if (isOperator(x[i])==false)
	{
		if(isChar(x[i])==true)
		 printf("LIT %c LOAD ",x[i]);
	    else if(x[i]==-51) continue ; //garbege 
		else 	printf("LIT %c ",x[i]);
	}
	}
	printf("STORE");
}
///////////////
void main()
{
 	char *x ,*m; int y,result; stack z;
	create(z);
	x=new char[];
	  printf("Enter the infix expression:\t");
	gets(x);
	y=strlen(x);
	m=new char [y];
    cov_postfix(&z,x,m);
	
	 printf("the postfix expression is \t");
	puts(m);  
	recursive_decent(m);
   /* result=eva_post(z,m);
	 printf("evaluation of postfix expression=\t%d\n",result); */
	 
    _getch();
}
//=============================================================
