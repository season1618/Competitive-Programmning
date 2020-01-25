#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}const int size=1e5;
int N,M;//N:vertex M:edge
class union_find{//union by rank
public:
	vector<int> par;
	union_find(int n):par(n){
		rep(i,0,n) par[i]=i;
	}
	int root(int v){
		if(par[v]==v) return v;
		else{ par[v]=root(par[v]); return par[v]; }
	}
	void unite(int x,int y){
		int a=root(x);
		int b=root(y); 
		if(a!=b) par[a]=b;
		return;
	}
	bool same(int x,int y){
		return root(x)==root(y);
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
	cout<<uf.par[N-1]<<endl;
	cout<<uf.root(N-1)<<endl;
	cout<<uf.same(0,N-1)<<endl;
}