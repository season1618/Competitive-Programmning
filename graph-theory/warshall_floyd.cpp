#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int N,M;
int dist[400][400];
void warshall_floyd(){ // O(N^3)
	rep(k,0,N){
		rep(i,0,N)rep(j,0,N){
			if(dist[i][j] > dist[i][k] + dist[k][j]){
				dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}
int main(){
	cin>>N>>M;
	rep(i,0,N)rep(j,0,N) dist[i][j] = (i == j ? 0 : inf);
	int a,b,c;
	rep(i,0,M){
		cin>>a>>b>>c; a--;b--;
		dist[a][b] = c;
	}
}