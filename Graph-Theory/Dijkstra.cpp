#include<bits/stdc++.h>
using namespace std;
const int size=1e5;
const int inf=1e9;
int N,M;
vector<vector<pair<int,long>>> g(size);
long d[size];int pre[size];
void dijkstra(int a){//O(E+NlogN)
	priority_queue<pair<long,int>> pq;
	rep(i,0,N){
		d[i]=inf;
		pq.push({-d[i],i});
	}
	d[a]=0;pq.push({0,a});
	int v;long temp;
	rep(i,0,N){
		v=pq.top().second;
		pq.pop();
        int u;
		for(pair<int,long> p:g[v]){
            u=p.first;
			temp=d[v]+p.second;
			if(d[u]>temp){
				d[u]=temp;
				pre[u]=v;
				pq.push({-d[u],u});
			}
		}
	}return;
}
int main(){
	cin>>N>>M;
	int a,b;long c;
	rep(i,0,M){
		cin>>a>>b>>c;a--;b--;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
}