#include<stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[MaxTree];
Tree CreateTree(struct TreeNode T[]);
Tree CreateTree(struct TreeNode T[]){
	int n;
	Tree R;
	int i;
	char cl,cr;
	int check[MaxTree];
	scanf("%d", &n);
	if(n)
	{
		for(i=0;i<n;i++)
			check[i]=0;
		for(i=0;i<n;i++){
			scanf("%c %c %c\n",&T[i].Element, &cl, &cr);
			if(cl!='-'){
				T[i].Left=cl-'0';
				check[T[i].Left]=1;
			}
			else
				T[i].Left=Null;
			if(cr!='-'){
				T[i].Right=cr-'0';
				check[T[i].Right]=1;
			}
			else
				T[i].Right=Null;
		}
		for(i=0;i<n;i++){
			if(!check[i])
				break;
		}
		R=i;
	}
	return R;
}

int Isomorphic(Tree R1, Tree R2);
int Isomorphic(Tree R1, Tree R2){
	if(R1==Null||R2==Null)
		return (R1==Null&&R2==Null);
	if(T1[R1].Element!=T2[R2].Element)
		return 0;
	if(T1[R1].Left==T2[R2].Left)
		return (Isomorphic(T1[R1].Left, T2[R2].Left)&&Isomorphic(T1[R1].Right,T2[R2].Right));
	else
		return (Isomorphic(T1[R1].Left, T2[R2].Right)&&Isomorphic(T1[R1].Right, T2[R2].Left));
}
int main()
{
	Tree R1, R2;
	R1=CreateTree(T1);
	R2=CreateTree(T2);
	if(Isomorphic(R1,R2))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;	
}
