#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int maxnum = 500;
const int maxint = 99999;

int Cmax, Sp;//the maximum of the capacity
int dist[maxnum];//the length of the shortest path to ith station
int nb[maxnum];//the need of bikes in ith station
int t[maxnum][maxnum];//the length of the road between stations
int n, m;//the total number of the stations and the roads
stack<int> ssnb;//the stack to save snb
int snb;//the sum of nb
int minnb;//the min snb

int c[maxnum];//the number of the bikes in the ith station
vector<int> path[maxnum];//record the path

void Dijkstra(int n, int v, int *dist, vector<int> *prev, int c[maxnum][maxnum])
{
	bool s[maxnum];//judge if the node in s
	for (int i = 0; i <= n; ++i) 
	{
		dist[i] = c[v][i];
		s[i] = 0;//init
		if (dist[i] < maxint)
			prev[i].push_back(v);
	}
	dist[v] = 0;
	s[v] = 1;

	//choose the shortest distance to s node
	for (int i = 1; i <= n; i++)
	{
		int tmp = maxint;
		int u = v;
		//choose the shortest path node which has not been used
		for(int j = 0; j <= n; j++)
			if ((!s[j]) && dist[j] < tmp)
			{
				u = j;
				tmp = dist[j];
			}
		s[u] = 1;//node u has been put into s

		//refresh the dist
		for(int j = 0; j <= n; j++)
			if ((!s[j]) && t[u][j] < maxint)
			{
				int newdist = dist[u] + t[u][j];
				int newnb = nb[u] + nb[j];
				if (newdist <= dist[j])
				{
					if (newdist < dist[j]) {
						prev[j].clear();
						dist[j] = newdist;
					}
					prev[j].push_back(u); 
				}
			}
	}
}
//the shortest path from v to u
//mode=0;search the target path
//mode=1;output the path
void searchPath(vector<int> *prev, int v, int u, int sta[], int len,int mode) 
{
	if (u == v) 
	{
		if (mode == 0)//search the path with smaller need of bikes
		{
			if (snb < minnb)
				minnb = snb;
		}
		else //output the path
		{
			if (snb == minnb)
			{
				cout << u;
				while (len--)
					cout << "->" << sta[len];
				cout << endl;
			}
		}
		return;
	}
	sta[len] = u;//the lenth node of this path is u
	snb += nb[u];//refresh the need of bikes in this path
	ssnb.push(snb);//save the snb in case of mulpath
	for (int i = 0; i < prev[u].size(); i++) 
	{
		if (i > 0)//reload the snb
		{
			snb = ssnb.top();
		}
		searchPath(prev, v, prev[u][i], sta, len + 1,mode);
	}
	ssnb.pop();
}

int main() {
	vector<int> prev[maxnum];//record the prev node
	cin >> Cmax;
	//input the number of nodes
	cin >> n;
	cin >> Sp;
	// input the number of roads
	cin >> m;
	int ci;//input the ci
	for (int i = 1; i <= n; i++)
	{
		cin >> ci;
		c[i] = ci;
		nb[i] = Cmax / 2 - ci;
	}
	int p, q, len;//input the p,q nodes and the distance
	//init the length of the roads
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			t[i][j] = maxint;
	//input the length of the roads
	for (int i = 1; i <= m; i++)
	{
		cin >> p >> q >> len;
		if (len < t[p][q])
		{
			t[p][q] = len;
			t[q][p] = len;
		}
	}
	//init the distance to PBMC
	for (int i = 0; i <= n; i++)
		dist[i] = maxint;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%8d", t[i][j]);
		}
		printf("\n");
	}

	Dijkstra(n, 0, dist, prev, t);

	int sta[maxnum];//record the path
	snb = 0;//init
	minnb = Cmax;//init minnb
	searchPath(prev, 0, Sp, sta, 0, 0);
	//output
	cout << "到目标节点的最短路径长度:" << dist[Sp] << endl;
	cout << "路径:";
	snb = 0;//init
	searchPath(prev, 0, Sp, sta, 0, 1);
	if (minnb < 0)
	{
		cout << "需要的最少自行车数:" << 0 << endl;
		cout << "需要退回的最少自行车数:" << -minnb << endl;
	}
	else
	{
		cout << "需要的最少自行车数:" << minnb << endl;
		cout << "需要退回的最少自行车数:" << 0 << endl;
	}
	getchar();
	getchar();
}