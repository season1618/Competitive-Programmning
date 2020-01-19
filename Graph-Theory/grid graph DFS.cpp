#include<bits/stdc++.h>
using namespace std;
const int size=1e5;
int H,W;
char g[size][size];bool check[size][size]={};
const int dx[4]={-1,0,1,0};//h
const int dy[4]={0,-1,0,1};//w
void dfs(int x,int y){
	int a,b;
	rep(i,0,4){
		a=x+dx[i];b=y+dy[i];
		if(a<0||h<=a||b<0||w<=b) continue;
		if(g[a][b]=='.'&&!check[a][b]){
			check[a][b]=true;
			dfs(a,b);
		}
	}return;
}
int main(){
	cin>>H>>W;
	rep(i,0,H)rep(j,0,W) cin>>g[i][j];
	rep(i,0,H)rep(j,0,W){
		if(g[i][j]=='.'&&!check[i][j]){
			check[i][j]=true;
			dfs(i,j);
		}
	}
}