#include<bits/stdc++.h>
using namespace std;
const int size=100;
const int dx[4]={-1,0,1,0};//h
const int dy[4]={0,-1,0,1};//w
int H,W;char g[size][size];
vector<vector<int>> dist(size,vector<int>(size,-1));
deque<pair<int,int>> task;
void bfs(int x,int y){
	int a,b,c,d;
	while(task.size()>0){
		a=task.front().first;
		b=task.front().second;
	    rep(i,0,4){
	    	c=a+dx[i];d=b+dy[i];
	    	if(c<0||c>=H||d<0||d>=W) continue;
	    	if(g[c][d]=='.'&&dist[c][d]==-1){
	    		dist[c][d]=dist[a][b]+1;
				task.push_back(make_pair(c,d));
	    	}
		}task.pop_front();
	}return;
}
int main(){
	cin>>H>>W;
	int a,b;cin>>a>>b;
	rep(i,0,H)rep(j,0,W) cin>>g[i][j];
	dist[a][b]=0;task.push_back(make_pair(a,b));
	bfs(a,b);
}