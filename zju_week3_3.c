#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );

int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

/* Your function will be put here */
ElementType EvalPostfix( char *expr )
{
	int i=0,top=0;
	double a[50],x,y;
	char str[50];
	int len=0;
	while (expr[i])
	{
		len=0;
		while (expr[i]&&expr[i]!=' ')
		{
			str[len++]=expr[i++]; 
		}
		str[len]=0; 
		if (expr[i]==' ') i++;
		if (len==1&&str[0]<48)
		{
			if (top<2) return Infinity;
			switch (str[0])
			{
				case '+':y=a[top--];x=a[top--];a[++top]=x+y;break;
				case '-':y=a[top--];x=a[top--];a[++top]=x-y;break;
				case '*':y=a[top--];x=a[top--];a[++top]=x*y;break;
				case '/':y=a[top--];x=a[top--];if (!y) return Infinity;a[++top]=x/y;break;
			}
		}
		else
			{
				a[++top]=atof(str);
			}
	}
	if (top!=1) return Infinity; 
	return a[1];
}
