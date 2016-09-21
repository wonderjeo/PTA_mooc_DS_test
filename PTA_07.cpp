#include<stdio.h>
#include<queue>
using namespace::std;
#define Maxtree 10
#define Tree int
#define Null -1
struct TreeNode{
	Tree Left;
	Tree Right;
}T[Maxtree];
queue<int> Q;
Tree CreateTree(struct TreeNode T[]);
Tree CreateTree(struct TreeNode T[]){
	int n;
	Tree R;
	scanf("%d", &n);
	if(n){
		int i;
		char cl,cr;
		int check[Maxtree];
		for(i=0;i<n;i++)
			check[i]=0;
		for(i=0;i<n;i++){
			scanf("\n%c %c", &cl, &cr);
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
void PrintLeaves(Tree R);
void PrintLeaves(Tree R){
	Q.push(R);
	int flag=0;
	while(!Q.empty())
	{
		if(T[Q.front()].Left==Null&&T[Q.front()].Right==Null)
		{
			if(!flag)
				flag=1;
			else
				printf(" ");
			printf("%d", Q.front());
		}
		if(T[Q.front()].Left!=Null)
			Q.push(T[Q.front()].Left);
		if(T[Q.front()].Right!=Null)
			Q.push(T[Q.front()].Right);
		Q.pop();
	}
	return;
}
int main()
{
	Tree R;
	R=CreateTree(T);
	PrintLeaves(R);
	return 0;
}

