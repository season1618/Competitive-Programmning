#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const int size=1e5;
int N,M;
class union_find{// quick find
public:
	vector<int> par;
	vector<vector<int>> g;
	union_find(int n):par(n),g(n){
		rep(i,0,n){ par[i] = i; g[i].push_back(i); }
	}
	void unite(int x,int y){
		if(g[par[x]].size() < g[par[y]].size()) swap(x,y);
		int a = par[x];
		int b = par[y];
		for(int v:g[b]){
			par[v]=a;
			g[a].push_back(v);
		}
		g[b].clear();
		return;
	}
	bool same(int x,int y){
		return par[x]==par[y];
	}
};
int main(){
	cin>>N>>M;
	union_find uf(N);
	int a,b;
	rep(i,0,M){
		cin>>a>>b; a--; b--;
		uf.unite(a,b);
	}
	print(uf.par,N);
	cout<<uf.same(0,N-1)<<endl;
}