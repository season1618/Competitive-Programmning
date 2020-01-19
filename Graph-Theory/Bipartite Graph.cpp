#include<bits/stdc++.h>
using namespace std;
const int size=1e+5;
vector<int> g[size];
vector<int> color(size,-1);//1:black,0:white
int black=0,white=0;
bool dfs(int v){//O(E)
	for(int u:g[v]){
		if(color[u]!=-1){
			if(color[u]==color[v]) return 0;
		}else{
			color[u]=color[v]^1;
			if(!dfs(u)) return 0;
		}
	}return 1;
}
int main(){
	int N,M;cin>>N>>M;
	int a,b;
	rep(i,0,M){
		cin>>a>>b;a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
    }
    rep(i,0,N){//not connected
        if(color[i]==-1){
            color[i]=0;
            dfs(i);
        }
    }
}