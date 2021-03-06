#include<iostream>
#include<stdlib.h>
using namespace :: std;
typedef struct TreeNode* Tree;
struct TreeNode{
	int v;
	Tree Left,Right;
	int Height;
};
Tree CreateAVLTree(int N);
Tree Insert(Tree T, int V);
Tree SingleLeftRotation(Tree T);
Tree SingleRightRotation(Tree T);
Tree DoubleLeftRightRotation(Tree T);
Tree DoubleRightLeftRotation(Tree T);
Tree NewNode(int V);
int GetHeight(Tree T);
int GetHeight(Tree T){
	if(!T)
		return 0;
	else
		return T->Height;
}
Tree CreateAVLTree(int N)
{
	Tree T,E;
	int i, V;
	for(i=0;i<N;i++)
	{
		cin>>V;
		T=Insert(T,V);
	}
	return T;
}
Tree Insert(Tree T, int V){
	if(!T)
	{
		T=NewNode(V);
	}//如果T为空树，则新建一个树
	else
	{
		if(V<T->v)
		{
			T->Left=Insert(T->Left,V);//插入左子树
			if(GetHeight(T->Left)-GetHeight(T->Right)==2)//平衡被破坏
			{
				if(V<((T->Left)->v))//引发破坏的节点位于左子树的左子树
					T=SingleLeftRotation(T);//左单旋
				else
					T=DoubleLeftRightRotation(T);//左右双旋
			}
		}
		else
		{
			T->Right=Insert(T->Right,V);//插入右子树
			if(GetHeight(T->Right)-GetHeight(T->Left)==2)//平衡被破坏
			{
				if(V<((T->Right)->v))//引发破坏的节点位于右子树的左子树
					T=DoubleRightLeftRotation(T);//右左双旋
				else
					T=SingleRightRotation(T);//右单旋
			}
		}
		T->Height=(GetHeight(T->Left)>GetHeight(T->Right)?GetHeight(T->Left):GetHeight(T->Right))+1;
	}
	return T;
}
Tree SingleLeftRotation(Tree T){
	Tree tmp;
	tmp=T->Left;
	T->Left=tmp->Right;
	tmp->Left=T;
	return tmp;
}
Tree SingleRightRotation(Tree T){
	Tree tmp;
	tmp=T->Right;
	T->Right=tmp->Left;
	tmp->Right=T;
	return tmp;
}
Tree DoubleLeftRightRotation(Tree T){
	Tree tmp1,tmp2;
	tmp1=T->Left;
	tmp2=T->Left->Right;
	T->Left=tmp2;
	tmp1->Right=tmp2->Left;
	tmp2->Left=tmp1;
	T->Left=tmp2->Right;
	tmp2->Right=T;
	return tmp2;
}
Tree DoubleRightLeftRotation(Tree T){
	Tree tmp1,tmp2;
	tmp1=T->Right;
	tmp2=T->Right->Left;
	T->Right=tmp2;
	tmp1->Left=tmp2->Right;
	tmp2->Right=tmp1;
	T->Right=tmp2->Left;
	tmp2->Left=T;
	return tmp2;
}
Tree NewNode(int V){
	Tree T;
	T=(Tree)malloc(sizeof(TreeNode));
	T->v=V;
	T->Left=T->Right=NULL;
	T->Height=1;
	return T;
}
int main()
{
	Tree T;
	int N;
	cin>>N;
	T=CreateAVLTree(N);
	cout<<T->v;
	return 0;
}
