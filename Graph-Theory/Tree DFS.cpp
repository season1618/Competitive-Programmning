#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
const int size=1e5;
vector<int> g[size];
int depth[size],sub[size];
void dfs(int v,int p){
	sub[v]=1;
	for(int u:g[v]){
		if(u!=p){
			depth[u]=depth[v]+1;
			dfs(u,v);
			sub[v]+=sub[u];
		}
	}return;
}
int main(){
	int N;cin>>N;
	int a,b;
	rep(i,0,N-1){
		cin>>a>>b;a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int root=0;depth[root]=0;
	dfs(root,-1);
}