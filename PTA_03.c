#include<stdio.h>
#include<stdlib.h>
typedef struct PolyNode *Polynomial;
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
};
void Attach(int c, int e, Polynomial *Rear);
void Attach(int c, int e, Polynomial *Rear){
    Polynomial tmp;
    tmp=(Polynomial)malloc(sizeof(struct PolyNode));
    tmp->coef=c;
    tmp->expon=e;
    tmp->link=NULL;
    (*Rear)->link=tmp;
    (*Rear)=(*Rear)->link;
}
Polynomial ReadPoly();
Polynomial ReadPoly(){
    Polynomial P,Rear;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    Rear=P;
    int n,c,e;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &c, &e);
        Attach(c,e,&Rear);
    }
    Rear=P;
    P=P->link;
    free(Rear);
    return P;
}
void PrintPoly(Polynomial P);
void PrintPoly(Polynomial P){
    if(!P){
        printf("0 0");
    }
    int flag=1;
    while(P)
    {
        if(flag)
            flag=0;
        else{
            printf(" ");
        }
        printf("%d %d", P->coef, P->expon);
        P=P->link;
    }
    return;
}
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Add(Polynomial P1, Polynomial P2){
    if(!P1&&!P2){
        printf("These are empty Poly");
        return NULL;
    }
    Polynomial P,Rear;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    Rear=P;
    while(P1&&P2)
    {
        int sum,c,e;
        if(P1->expon>P2->expon){
            c=P1->coef;
            e=P1->expon;
            P1=P1->link;
            Attach(c,e,&Rear);
        }
        else if(P1->expon<P2->expon){
            c=P2->coef;
            e=P2->expon;
            P2=P2->link;
            Attach(c,e,&Rear);
        }
        else{
            sum=P1->coef+P2->coef;
            if(sum){
                c=sum;
                e=P1->expon;
                Attach(c,e,&Rear);
            }
            P1=P1->link;
            P2=P2->link;
        }
    }
    if(P1){
    Rear->link=P1;
    }
    if(P2){
    Rear->link=P2;
    }
    Rear=P;
    P=P->link;
    free(Rear);
    return P;
}
Polynomial Mult(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2){
    Polynomial P,Rear,PP1,PP2;
    int c,e;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    Rear=P;
    PP2=P2;
    while(PP2)
    {
        c=P1->coef*PP2->coef;
        e=P1->expon+PP2->expon;
        Attach(c,e,&Rear);
        PP2=PP2->link;
    }
    P1=P1->link;
    PP1=P1;
    while(PP1)
    {
        Rear=P;
        PP2=P2;
        while(PP2)
        {
            c=PP1->coef*PP2->coef;
            e=PP1->expon+PP2->expon;
            while(Rear->link&&Rear->link->expon>e)
            {
                Rear=Rear->link;
            }
            if(Rear->link&&Rear->link->expon==e){
                if(!(Rear->link->coef+=c)){
                    Polynomial t;
                    t=Rear->link;
                    Rear->link=Rear->link->link;
                    free(t);
                }
                PP2=PP2->link;
                continue;
            }
            Polynomial tmp;
            tmp=(Polynomial)malloc(sizeof(struct PolyNode));
            tmp->coef=c;
            tmp->expon=e;
            tmp->link=Rear->link;
            Rear->link=tmp;
            PP2=PP2->link;
        }
        PP1=PP1->link;
    }
    Rear=P;
    P=P->link;
    free(Rear);
    return P;
}
int main()
{
    Polynomial P1,P2,P3,P4;
    P1=ReadPoly();
    P2=ReadPoly();
    P3=Mult(P1,P2);
    P4=Add(P1,P2);
    PrintPoly(P3);
    printf("\n");
    PrintPoly(P4);
    return 0;
}