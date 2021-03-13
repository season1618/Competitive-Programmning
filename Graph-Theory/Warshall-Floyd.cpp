#include<bits/stdc++.h>
using namespace std;
const int size=200;
const int inf=1e9;
int N,M;
int len[size][size] = {};
int d[size][size];
void warshall_floyd(long dist[][size]){// O(N^3)
	rep(i,0,N)rep(j,0,N){
		if(i == j) dist[i][j] = 0;
		else if(len[i][j] == 0) dist[i][j] = inf;
		else dist[i][j] = len[i][j];
	}rep(k,0,N)rep(i,0,N)rep(j,0,N){
		if(dist[i][j] > dist[i][k] + dist[k][j]){
			dist[i][j] = dist[i][k] + dist[k][j];
		}
	}return;
}
int main(){
	cin>>N>>M;
	int a,b,c;
	rep(i,0,M){
		cin>>a>>b>>c;a--;b--;
		len[a][b] = c;
		len[b][a] = c;
	}
}