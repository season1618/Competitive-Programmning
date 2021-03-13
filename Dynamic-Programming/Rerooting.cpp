#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
vector<int> g[size];
vector<int> dp[size];// dp[v][i] v to end
map<int,int> L[size],R[size];
int ans[size];
int func(int x,int y){ return func(x,y); }
int dfs1(int p,int v){
	int res = 0;// identity
	for(int u:g[v]){
        if(u == p) continue;
		dp[v].push_back(dfs1(v,u));
		res = func(res , dp[v].back());
	}
	return res + 1;
}
void dfs2(int p,int v){
	ans[v] = func(R[v][0] , dp[v].back());
    int j = 0;
	for(int u:g[v]){
		if(u == p) continue;
		int t = func(dp[v].back() , func(L[v][j] , R[v][j+1]));
		dp[u].push_back(t + 1);
		dfs2(v,u);
        j++;
	}
	return;
}
int main(){
	int N;cin>>N;
	int a,b;
	rep(i,0,N-1){
		cin>>a>>b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(-1,0);
	rep(i,0,N){
		L[i][0] = 0; R[i][dp[i].size()] = 0;// identity
		rep(j,0,dp[i].size()) L[i][j+1] = func(L[i][j] , dp[i][j]);
		for(int j = dp[i].size(); j > 0; j--) R[i][j-1] = func(R[i][j] , dp[i][j-1]);
	}
	dp[0].push_back(0);// identity
	dfs2(-1,0);
	print(ans,,N);
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
typedef pair<long,long> T;
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int N;
vector<int> g[size];
vector<T> dp[size];// dp[v][i] v to end
T e1 = {1, 1}, e2 = {0, 1};// left identify, right identify
map<int,T> L[size],R[size];
T ans[size];
T func1(T x, T y){// F x f
	T p;
	p.first = x.first * (y.first + y.second);
	p.second = x.second * y.second;
    return p;
}
T func2(T x, T y){// F x F
	T p;
	p.first = x.first * y.first;
	p.second = x.second * y.second;
    return p;
}
T dfs1(int p, int v){
    T res = e1;
	for(int u:g[v]){
        if(u == p) continue;
		dp[v].push_back(dfs1(v, u));
        res = func1(res, dp[v].back());
	}return res;
}
void dfs2(int p, int v){
	ans[v] = func1(R[v][0], dp[v].back());
    T t;
    int j = 0;
	for(int u:g[v]){
		if(u == p) continue;
        t = func1(func2(L[v][j], R[v][j+1]), dp[v].back());
        dp[u].push_back(t);
		dfs2(v, u);
        j++;
	}return;
}
int main(){
	cin>>N;
	int a,b;
	rep(i,0,N-1){
		cin>>a>>b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(-1, 0);
	rep(i,0,N){
		L[i][0] = e1; R[i][dp[i].size()] = e1;
		rep(j,0,dp[i].size()) L[i][j+1] = func1(L[i][j], dp[i][j]);
		for(int j = dp[i].size(); j > 0; j--) R[i][j-1] = func1(R[i][j], dp[i][j-1]);
	}
	dp[0].push_back(e2);
	dfs2(-1, 0);
	rep(i,0,N){
		cout<<ans[i].first<<endl;
	}
}