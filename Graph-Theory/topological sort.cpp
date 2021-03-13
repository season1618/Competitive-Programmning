#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int N,M;
vector<int> g[size];
int deg[size] = {};
deque<int> ord; //deg == 0
void tsort(){// O(M)
	queue<int> ver;
	rep(i,0,N)if(deg[i] == 0) ver.push(i);
	while(!ver.empty()){
		int v = ver.front(); ver.pop();
		ord.push_back(v);
		for(int u:g[v]){
			deg[u]--;
			if(deg[u] == 0) ver.push(u);
		}
	}
	rep(i,0,N)if(deg[i])// not DAG
	return;
}
int main(){
	cin>>N>>M;
	int a,b;
	rep(i,0,M){
		cin>>a>>b; a--;b--;
		g[a].push_back(b);//a into b
		deg[b]++;
	}
	tsort();
	print(res,,N);
}