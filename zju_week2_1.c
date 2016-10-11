#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
	    int Coefficient;
		    int Exponent;
			    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
	    Polynomial a, b, s;
		a = Read();
		b = Read();
		s = Add(a, b);
		Print(s);
		return 0;
}

/* Your function will be put here */
Polynomial Add(Polynomial a, Polynomial b){
    if(!a&&!b){
        return NULL;
    }
    Polynomial P,Rear;
    P=(PtrToNode)malloc(sizeof(struct Node));
    Rear=P;
    while(a&&b)
    {
        int sum,c,e;
		PtrToNode tmp;
		tmp=(PtrToNode)malloc(sizeof(struct Node));
        if(a->Exponent>b->Exponent){
            c=a->Coefficient;
            e=a->Exponent;
            a=a->Next;
			tmp->Coefficient=c;
			tmp->Exponent=e;
			tmp->Next=NULL;
        }
        else if(a->Exponent<b->Exponent){
            c=b->Coefficient;
            e=b->Exponent;
            b=b->Next;
			tmp->Coefficient=c;
			tmp->Exponent=e;
			tmp->Next=NULL;
        }
        else{
            sum=a->Coefficient+b->Coefficient;
            if(sum){
                c=sum;
                e=a->Exponent;
				tmp->Coefficient=c;
				tmp->Exponent=e;
				tmp->Next=NULL;
            }
            a=a->Next;
            b=b->Next;
        }
		Rear->Next=tmp;
		Rear=Rear->Next;
    }
    if(a){
    Rear->Next=a;
    }
    if(b){
    Rear->Next=b;
    }
	Rear=result;
	result=result->Next;
	free(Rear);
    return P;
}
