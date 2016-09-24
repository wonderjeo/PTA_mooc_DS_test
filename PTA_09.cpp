#include<stdlib.h>
#include<iostream>
using namespace :: std;
typedef struct TreeNode* Tree;
struct TreeNode{
	int v;
	Tree Left;
	Tree Right;
	int flag;
};
Tree CreateTree(int N);
Tree NewNode(int V);
Tree Insert(Tree T, int V);
void PrintTree(Tree T);
int Judge(Tree T,int N);
int check(Tree T, int V);
void Reset(Tree T);
void Free(Tree T);
Tree CreateTree(int N){
	int i;
	int V;
	Tree T;
	cin>>V;
	T=NewNode(V);
	for(i=0;i<N-1;i++){
		cin>>V;
		T=Insert(T,V);
	}
	return T;
}
Tree NewNode(int V){
	Tree T;
	T=(Tree)malloc(sizeof(struct TreeNode));
	T->v=V;
	T->Left=NULL;
	T->Right=NULL;
	T->flag=0;
	return T;
}
Tree Insert(Tree T, int V){
	if(!T)
		T=NewNode(V);
	else{
		if(V<T->v)
			T->Left=Insert(T->Left,V);
		else
			T->Right=Insert(T->Right,V);
	}
	return T;
}
void PrintTree(Tree T){
	if(T){
		cout<<T->v<<endl;
		PrintTree(T->Left);
		PrintTree(T->Right);
	}
	return;
}
int Judge(Tree T, int N){
	int i;
	int V,f;
	f=1;
	for(i=0;i<N;i++){
		cin>>V;
		if(f)
			if(!check(T,V))
				f=0;
	}
	return f;
}
int check(Tree T, int V){
	if(T->flag)//该节点已经被检查过
	{
		if(V<T->v)
			return check(T->Left,V);
		else if(V>T->v)
			return check(T->Right,V);
		else
			return 0;
	}
	else//该节点未被检查过
	{
		if(V==T->v)
		{
			T->flag=1;
			return 1;
		}
		else
			return 0;
	}
}
void Reset(Tree T){
	if(T){
		T->flag=0;
		Reset(T->Left);
		Reset(T->Right);
	}
}
void Free(Tree T){
	if(T){
		Free(T->Left);
		Free(T->Right);
		free(T);
	}
}
int main()
{
	int N,L;
	int i;
	cin>>N;
	while(N)
	{
		cin>>L;
		Tree T;
		T=CreateTree(N);
		for(i=0;i<L;i++){
			if(Judge(T,N))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
			Reset(T);
		}
		Free(T);
		cin>>N;
	}
}
