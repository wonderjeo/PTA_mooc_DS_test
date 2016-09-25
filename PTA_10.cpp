#include<iostream>
typedef struct TreeNode* Tree;
struct TreeNode{
	int v;
	Tree Left,Right;
	int BF;
};
Tree CreateAVLTree(int N);
Tree CreateAVLTree(int N){
	Tree T;
	int i, V;
	for(i=0;i<N;i++){
		cin>>V;
		T=Insert(V);
	}
	return T;
}
Tree Insert(int V);
Tree Insert(int V){}
int main()
{
	Tree T;
	int N;
	cin>>N;
	T=CreateAVLTree(N);
	cout<<T.v;
	return 0;
}
