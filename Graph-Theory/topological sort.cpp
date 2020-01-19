#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
const int size=1e5;
int N,M;
vector<int> g[size];int deg[size]={};
deque<int> res; //deg==0
void tsort(){ //O(N^2)
	queue<int> ver;
	rep(i,0,N)if(deg[i]==0) ver.push(i);
	while(!ver.empty()){
		int v=ver.front(); ver.pop();
		res.push_back(v);
		for(int u:g[v]){
			deg[u]--;
			if(deg[u]==0) ver.push(u);
		}
	}
	rep(i,0,N)if(deg[i]) //not DAG
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
	print(res,N);
}