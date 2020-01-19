#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int to;
	int weight;
	Edge(int t,int w) : to(t),weight(w){}
};
using Graph=vector<vector<Edge>>;
int main(){
	int n,m;cin>>N>>M;
	Graph g(n);
	rep(i,0,m){
		int a,b,w;
		cin>>A>>B>>W;
		g[a].push_back(Edge(b,w));
	}
}