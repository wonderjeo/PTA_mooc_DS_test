#include<stdio>
#include<iostream>
typedef struct TreeNode* Tree;
struct TreeNode{
	int v;
	Tree Left;
	Tree Right;
	int flag;
}
Tree CreateTree(int N);
Tree CreateTree(int N){
	int i;
	int V;
	Tree T;
	cin>>V;
	T=NewNode(V);
	for(i=0;i<N;i++){
		cin>>V;
		Insert(T,V);
	}
	return T;
}
void Insert(Tree T, int V);
void Insert(Tree T, int V){
	if(!Tree)
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
	}
	return 0;
}
