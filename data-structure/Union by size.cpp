#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const int size=1e5;
int N,M;
class union_find{
public:
	vector<int> par;
	vector<int> sub;
	union_find(int n):par(n),sub(n){
		rep(i,0,n){ par[i] = i; sub[i] = 1; }
	}
	int root(int v){
		if(par[v] == v) return v;
		return root(par[v]);
		// return par[v] = root(par[v]); O(alpha(n))
	}
	void unite(int x,int y){//union by size O(log n)
		x = root(x);
		y = root(y);
		if(x == y) return;
		if(sub[x] < sub[y]) swap(x, y);
		par[y] = x;
		sub[x] += sub[y];
		return;
	}
	bool same(int x,int y){
		return root(x) == root(y);
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
}