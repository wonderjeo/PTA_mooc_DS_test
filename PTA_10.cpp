#include<iostream>
typedef struct TreeNode* Tree;
typedef Tree Position;
struct TreeNode{
	int v;
	Tree Left,Right;
	int Height;
};
struct 
Tree CreateAVLTree(int N);
Tree CreateAVLTree(int N)
{
	Tree T,E;
	int i, V;
	for(i=0;i<N;i++)
	{
		cin>>V;
		T=Insert(T,V);
		}
	}
	return T;
}
Tree Insert(Tree T, int V);
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
			if((T->Left)->Height-(T->Right)->Height==2)//平衡被破坏
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
			if((T->Right)->Height-(T->Left)->Height==2)//平衡被破坏
			{
				if(V<((T->Right)->v))//引发破坏的节点位于右子树的左子树
					T=DoubleRightLeftRotation(T);//右左双旋
				else
					T=SingleRightRotaion(T)//右单旋
			}
		}
	}

	return T;
}
Tree NewNode(int V);
Tree NewNode(int V){
	Tree T;
	T=(Tree)malloc(sizeof(TreeNode));
	T->v=V;
	T->Left=T->Right=NULL;
	T->Height=0;
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
