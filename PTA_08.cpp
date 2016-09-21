#include<iostream>
#include<stack>
#include<string>
using namespace::std;
#define Maxtree 30
#define Tree int
#define Null -1
struct TreeNode{
	Tree Left;
	Tree Right;
}T[Maxtree];
int PreArray[Maxtree];
int InArray[Maxtree];
stack<int> s;
void GetArrays(int n);
void GetArrays(int n){
	int PreIndex=0;
	int InIndex=0;
	n*=2;
	if(n){
		int i;
		for(i=0;i<n;i++){
			string cmd;
			cin>>cmd;
			if(cmd[1]!='u'&&cmd[1]!='o')
				cout<<"Your command is wrong!"<<endl;
			if(cmd[1]=='u'){
				cin>>cmd;
				PreArray[PreIndex]=cmd[0]-'0';
				s.push(PreArray[PreIndex]);
				PreIndex++;	
			}
			else{
				InArray[InIndex]=s.top();
				s.pop();
				InIndex++;
			}
		}
	}
	int j;
	n/=2;
	for(j=0;j<n;j++){
		cout<<PreArray[j]<<endl;
	}
	for(j=0;j<n;j++){
		cout<<InArray[j]<<endl;
	}
	return;
}
Tree CreateTree(int PreIndex, int InIndex, int length);
Tree CreateTree(int PreIndex, int InIndex, int length){
	if(length<=0)
		return Null;
	Tree Root=PreArray[PreIndex];
	int i;
	for(i=InIndex;i<Maxtree;i++)
		if(InArray[i]==Root)
			break;
	int l;
	l=i-InIndex;
	T[Root].Left=CreateTree(PreIndex+1,InIndex,l);
	T[Root].Right=CreateTree(PreIndex+l+1,i+1,length-l-1);
	return Root;
}
int main()
{
	Tree R;
	int n;
	cin>>n;
	GetArrays(n);
	R=CreateTree(0, 0, n);
}
