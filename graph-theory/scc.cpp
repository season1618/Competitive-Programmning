#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(int)(x);i<(int)(y);i++)
#define print(A,x,n) {rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;}
#define pprint(A,y,m,n) {rep(J,0,m){print(A[J],y,n);}}
const long mod=1e9+7;
const int siz=3e5;
const int inf=1e6;
// Strong Connected Component
int N,M;
vector<int> g[siz], h[siz];
int group[siz] = {}, order[siz];
int visited[siz] = {};
void dfs1(int v, int& k){
	visited[v] = 1;
	for(int u:g[v]){
		if(visited[u] == 0) dfs1(u, k);
	}
	group[v] = k++;
	order[group[v]] = v;
}
void dfs2(int v, int p){
	visited[v] = 2;
	group[v] = group[p];
	for(int u:h[v]){
		if(visited[u] == 1) dfs2(u, p);
	}
}
int main(){
	cin>>N>>M;
	int a,b;
	rep(i,0,M){
		cin>>a>>b; a--; b--;
		g[a].push_back(b);
		h[b].push_back(a);
	}
	int k = 0;
	for(int i = 0; i < N; i++){
      	if(visited[i] == 0) dfs1(i, k);
    }
	for(int i = N-1; i >= 0; i--){
        int p = order[i];
        if(visited[p] == 1) dfs2(p, p);
    }
  
    long ans = 0; long cnt[N] = {};
    rep(i,0,N) cnt[group[i]]++;
    rep(i,0,N) ans += cnt[i] * (cnt[i] - 1) / 2;
    cout<<ans<<endl;
}