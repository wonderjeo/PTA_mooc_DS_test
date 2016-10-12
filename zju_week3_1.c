#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

/* Your function will be put here */
Deque CreateDeque(){
	Deque D;
	D=(Deque)malloc(sizeof(struct DequeRecord));
	D->Front=(PtrToNode)malloc(sizeof(struct Node));
	D->Front->Last=NULL;
	D->Front->Next=NULL;
	D->Rear=D->Front;
	return D;
}
int Push( ElementType X, Deque D ){
	PtrToNode tmp;
	tmp=(PtrToNode)malloc(sizeof(struct Node));
	tmp->Element=X;
	if(D->Front==D->Rear)//if empty deque
	{
		tmp->Last=D->Front;
		tmp->Next=NULL;
		D->Front->Next=tmp;
		D->Rear=tmp;
	}
	else{
		tmp->Next=D->Front->Next;
		tmp->Last=D->Front;
		D->Front->Next->Last=tmp;
		D->Front->Next=tmp;
	}
	return 1;
}
ElementType Pop( Deque D ){
	if(D->Rear==D->Front)//if empty deque
	{
		return ERROR;
	}
	PtrToNode tmp;
	ElementType e;
	tmp=D->Front->Next;
	if(tmp==D->Rear)//if the deque has only one node
	{
		D->Rear=D->Front;
		D->Front->Next=NULL;
	}	
	else{
		D->Front->Next=tmp->Next;
		D->Front->Next->Last=D->Front;
	}
	e=tmp->Element;
	free(tmp);
	return e;
}
int Inject( ElementType X, Deque D ){
	PtrToNode tmp;
	tmp=(PtrToNode)malloc(sizeof(struct Node));
	tmp->Element=X;
	if(D->Front==D->Rear)//if empty deque
	{
		tmp->Last=D->Front;
		tmp->Next=NULL;
		D->Front->Next=tmp;
		D->Rear=tmp;
	}
	else{
		tmp->Next=NULL;
		tmp->Last=D->Rear;
		D->Rear->Next=tmp;
		D->Rear=tmp;
	}
	return 1;
}
ElementType Eject( Deque D ){
	if(D->Rear==D->Front)//if empty deque
	{
		return ERROR;
	}
	PtrToNode tmp;
	ElementType e;
	tmp=D->Rear;
	D->Rear=D->Rear->Last;
	e=tmp->Element;
	free(tmp);
	return e;
}
