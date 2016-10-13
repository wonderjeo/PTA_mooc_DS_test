#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Stacknum ); /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case pop:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

/* Your function will be put here */
Stack CreateStack( int MaxElements ){
	Stack S;
	ElementType a[10000];//maximum size of the array is 10000
	Stack=(Stack)malloc(sizeof(struct StackRecord));
	S->Array=a;
	S->Capacity=MaxElements;
	S->Top1=a;//top pointer of stack1
	S->Top2=&a[MaxElements];//top pointer of stack2
	return S;
}
int IsEmpty( Stack S, int Stacknum ){
	int flag=0;
	if(Stacknum==1){
		if(S->Top1==S->Array)
		{
			flag=1;//isEmpty
		}
	}
	else//stack2
	{
		if(S->Top2==(S->Array+S->Capacity))
		{
			flag=1;//isEmpty
		}
	}
	return flag;
}
int IsFull( Stack S ){
	int flag=0;
	if(S->Top1==S->Top2)
	{
		flag=1;//isFull
	}
	return flag;
}
int Push( ElementType X, Stack S, int Stacknum ){
	if(isFull(S))
		return 0;
	if(Stacknum==1)//stack1
	{
		*(S->Top1)=X;
		(S->Top1)++;
	}
	else//stack2
	{
		*(S->Top2)=X;
		(S->Top2)--;
	}
	return 1;
}
ElementType Top_Pop( Stack S, int Stacknum ){
	if(isEmpty(S))
		return 0;
	ElementType e;
	if(Stacknum==1)//stack1
	{
		e=*(S->Top1);
		(S->Top1)--;
	}
	else//stack2
	{
		e=*(S->Top2);
		(S->Top2)++;
	}
	return 1;
}
