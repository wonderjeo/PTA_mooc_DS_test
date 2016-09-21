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
int PreIndex=0;
int InArray[Maxtree];
int InIndex=0;
stack<int> s;
void GetArrays();
void GetArrays(){
	int n;
	cin>>n;
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
int main()
{
	GetArrays();
}
