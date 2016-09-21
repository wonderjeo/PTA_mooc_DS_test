#include<iostream>
#include<stack>
using namespace std;
#define Maxtree 30
#define Tree int
#define Null -1
struct TreeNode{
	Tree Left;
	Tree Right;
}T[Maxtree];
int PreArray[Maxtree];
int InArray[Maxtree];
stack s;
void GetArrays();
void GetArrays(){
	int n;
	cin>>n;
	n*=2;
	if(n){
		
	}
}
int main()
{
	GetArrays();
	cout<<PreArray<<endl;
	cout<<InArray<<endl;
}
