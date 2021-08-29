#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
class graph{
public:
	int n;
	vector<vector<int>> node;
	vector<int> depth;
	vector<vector<int>> par;
	graph(int n){
		this->n = n;
		node.resize(n);
		depth.resize(n); depth[0] = -1;
		par.resize(20, vector<int>(n));
	}

private:
	void dfs(int v = 0, int p = 0){
		par[0][v] = p;
		depth[v] = depth[p] + 1;
		for(int u:node[v]){
			if(u == p) continue;
			dfs(u, v);
		}
	}
	void doubling(){ // O(NlogN)
		int vec[n];
		rep(i,0,19){
			rep(j,0,n) vec[j] = par[i][par[i][j]];
			rep(j,0,n) par[i+1][j] = vec[j];
		}
	}

public:
	void calc(){
		dfs();
		doubling();
	}
	int lca(int v, int u){ // Lowest Common Ancestor O(log^2N)
		if(depth[v] < depth[u]) swap(v, u);
		rep(i,0,20){
			if((depth[v] - depth[u]) & (1<<i)) v = par[i][v];
		}
		int i = 0;
		while(v != u){
			if(par[i][v] == par[i][u]){
	            if(i == 0) return par[0][v];
				v = par[i-1][v];
				u = par[i-1][u];
				i = 0;
			}else i++;
		}
		return v;
	}
	int dist(int v, int u){
		return depth[v] + depth[u] - 2 * depth[lca(v, u)];
	}
};

int main(){
	cin>>N;
	graph g(N);
	rep(i,0,N-1){
		int a,b; cin>>a>>b; a--; b--;
		g.node[a].push_back(b);
		g.node[b].push_back(a);
	}
	calc();
	int Q; cin>>Q;
	rep(_,0,Q){
		int a,b; cin>>a>>b; a--; b--;
		cout<<g.dist(a, b) + 1<<endl;
	}
}