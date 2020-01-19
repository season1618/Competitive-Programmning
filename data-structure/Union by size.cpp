#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}const int size=1e5;
int N,M;
class union_find{// union by size
public:
	vector<int> par;
	vector<int> sub;
	union_find(int n):par(n),sub(n){
		rep(i,0,n){ par[i]=i; sub[i]=1; }
	}
	int root(int v){
		if(g[v]==v) return v;
		else return root(g[v]);
	}
	void unite(int x,int y){//union by size
		int a=root(x),b=root(y);
		if(a==b) return;
		if(sub[a]<sub[b]) swap(x,y);
		par[root(y)]=root(x);
		sub[root(x)]++;
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
	print(uf.par,N);
	cout<<uf.root(N-1)<<endl;
	cout<<uf.same(0,N-1)<<endl;
}