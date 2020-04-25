#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int N;
vector<int> g[size];
int dist[size],par[20][size];
void dfs(int p, int v){
	par[0][v] = p;
	dist[v] = dist[p] + 1;
	for(int u:g[v]){
		if(u == p) continue;
		dfs(v, u);
	}return;
}
void calc(){// O(NlogN)
	int vec[N];
	rep(i,0,19){
		rep(j,0,N) vec[j] = par[i][par[i][j]];
		rep(j,0,N) par[i+1][j] = vec[j];
	}return;
}
int LCA(int v,int u){// Lowest Common Ancestor O(log^2N)
	if(dist[v] < dist[u]) swap(v, u);
	rep(i,0,20){
		if(dist[v] - dist[u] & (1<<i)) v = par[i][v];
	}
	int i = 0;
	while(v != u){
		if(par[i][v] == par[i][u]){
            if(i == 0) return par[0][v];
			v = par[i-1][v];
			u = par[i-1][u];
			i = 0;
		}else i++;
	}return v;
}
int main(){
	cin>>N;
	rep(i,0,N-1){
		int a,b; cin>>a>>b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dist[0] = -1;
	dfs(0, 0);
    calc();
	int Q;cin>>Q;
	rep(i,0,Q){
		int a,b; cin>>a>>b; a--; b--;
		cout<<dist[a] + dist[b] - 2 * dist[LCA(a, b)] + 1<<endl;
	}
}