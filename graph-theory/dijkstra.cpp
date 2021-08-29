#include<bits/stdc++.h>
using namespace std;
const int size=1e5;
const int inf=1e9;
int N,M;
vector<pair<int,long>> g[size];
long d[size]; int prev[size];
void dijkstra(long* dist, int a){// O(NlogN + M)
	priority_queue<pair<long,int>> pq;
	rep(i,0,N){
		if(i == a){ dist[a] = 0; pq.push({0, a}); }
		else{
			dist[i] = inf;
			//pq.push({-inf, i});
		}
	}
	while(!pq.empty()){
		long d = - pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if(dist[v] != d) continue;
		for(pair<int,long> p:g[v]){
            int u = p.first;
			long t = dist[v] + p.second;
			if(dist[u] > t){
				dist[u] = t;
				prev[u] = v;
				pq.push({-dist[u], u});
			}
		}
	}return;
}
struct vertex{};
vector<pair<vertex,long>>g[size];
map<vertex,long> d[size]; vertex prev[size];
void dijkstra(long* dist, vertex a){
	priority_queue<pair<long,vertex>> pq;
	rep(i,0,N){// all vertex
		if(i == a){ dist[a] = 0; pq.push({0, a}); }
		else{ dist[i] = inf; pq.push({-inf, i}); }
	}
	while(!pq.empty()){
		vertex v = pq.top().second;
		pq.pop();
		for(pair<vertex,long> p:g[v]){
			vertex u = p.first;
			long t = dist[v] + p.second;
			if(dist[u] > t){
				dist[u] = t;
				prev[u] = v;
				pq.push({-dist[u], u});
			}
		}
	}return;
}
int main(){
	cin>>N>>M;
	int a,b; long c;
	rep(i,0,M){
		cin>>a>>b>>c; a--;b--;
		g[a].push_back({b,c});
	}
}