#include<stdio.h>
#include<stack>
using namespace::std;
int main()
{
	int m, n, k, tmp, cur;
	stack<int> s;
	bool flag;
	scanf("%d %d %d", &m, &n, &k);
	while(k--){
		flag=true;
		cur=1;
		s.push(cur);
		for(int i=0;i!=n;i++){
			scanf("%d", &tmp);
			if(tmp>cur){
				for(int j=cur+1;j<=tmp;j++){
					s.push(j);
				}
				if(s.size()>m)
					flag=false;
				cur=tmp;
			}
			else{
				if(s.top()!=tmp)
					flag=false;
			}
			s.pop();
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
