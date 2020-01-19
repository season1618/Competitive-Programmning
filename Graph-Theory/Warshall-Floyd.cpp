#include<bits/stdc++.h>
using namespace std;
const int size=1e4;
const int INF=1e9;
int len[size][size]={};
int dist[size][size]={};
void warshall_floyd(int n){// O(N^3)
	rep(i,0,n)rep(j,0,n){
		if(i==j) dist[i][j]=0;
		else if(len[i][j]==0) dist[i][j]=INF;
		else dist[i][j]=len[i][j];
	}rep(k,0,n)rep(i,0,n)rep(j,0,n){
		if(dist[i][j]>dist[i][k]+dist[k][j]){
			dist[i][j]=dist[i][k]+dist[k][j];
		}
	}return;
}
int main(){
	cin>>N>>M;
	int a,b,c;
	rep(i,0,M){
		cin>>a>>b>>c;a--;b--;
		len[a][b]=c;
		len[b][a]=c;
	}
}