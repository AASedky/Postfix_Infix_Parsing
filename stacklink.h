#include<stdio.h>
typedef struct Node* pnode;
  struct Node{ pnode l;
int d;
};
typedef struct{
pnode t;
short int under;
}stack;
void create(stack &s)
{
	s.t=NULL;
}
int empty (stack s)
{
	if (s.t==NULL)
		 return 0;
	else
		return -1;
}
void create_node (pnode &pp)
{ pp= new Node[1];}
void push( stack &s, int x)
{
 pnode pp;
	  create_node(pp);
		pp->d=x;
		pp->l=s.t;
		s.t=pp;
}
int pop(stack &s,int *x)
{ pnode pp;
	if (empty(s)==0)
		s.under=-1;
	else
	{
		s.under=0;
		pp=s.t;
		*x=pp->d;
		s.t=pp->l;
		delete(pp);
		return *x;
	}
}
void disp(stack *s)
{int  x;  
while  (empty(*s)!=0)
{
	  x=pop(*s,&x);
	printf("%d",x);
	printf("\t");
}
}
int top(stack *s)
{
	 int x=pop(*s,&x);
	 push(*s,x);
	 return x;
}
 
