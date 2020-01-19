#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
const int size=1e5;
vector<int> g[size];
vector<pair<bool,bool>> check(size,make_pair(false,false));
bool f,s;
bool cycle(int v){
	check[v].first=true;
	for(int u:g[v]){
		f=check[u].first;
		s=check[u].second;
		if(!f)if(cycle(u)) return true;
		else if(!s) return true;
	}check[v].second=true;
	return false;
}
int main(){
	int N,M;cin>>N>>M;
	int a,b;
	rep(i,0,M){
		cin>>a>>b;a--;b--;
		g[a].push_back(b);
	}
	rep(i,0,N){
		if(!check[i].first) cycle(i);
	}
}