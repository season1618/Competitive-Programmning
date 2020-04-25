#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const int size=1e5;
int N,M;//N:vertex M:edge
class union_find{//union by rank
public:
	vector<int> par;
	vector<int> sub;// size of set
	union_find(int n):par(n),sub(n){
		rep(i,0,n){ par[i]=i; sub[i]=1; }
	}
	int root(int v){
		if(par[v]==v) return v;
		else{ par[v] = root(par[v]); return par[v]; }
	}
	void unite(int x,int y){
		int a = root(x);
		int b = root(y); 
		if(a==b) return;
		if(sub[a] < sub[b]) swap(a,b);
		par[b] = a;
		sub[a] += sub[b];
		return;
	}
	bool same(int x,int y){
		return root(x)==root(y);
	}
	int size(int v){
		return sub[root(v)];
	}
};
int main(){
	cin>>N>>M;
	union_find uf(N);
	int a,b;
	rep(i,0,M){
		cin>>a>>b;a--;b--;
		uf.unite(a,b);
	}
	print(uf.par,N);
	cout<<uf.root(N-1)<<endl;
	cout<<uf.same(0,N-1)<<endl;
	cout<<uf.size(N-1)<<endl;
/*
7 7
1 2
2 3
3 1
1 4
2 4
3 5
6 7
*/
/*
?
5
0
2
*/
}