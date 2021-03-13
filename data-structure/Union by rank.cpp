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
	vector<int> rank;
	union_find(int n):par(n),rank(n){
		rep(i,0,n){ par[i] = i; rank[i] = 1; }
	}
	int root(int v){
		if(par[v] == v) return v;
		return root(par[v]);
		// return par[v] = root(par[v]); O(alpha(n))
	}
	void unite(int x,int y){// union by rank O(log n)
		x = root(x);
		y = root(y); 
		if(x == y) return;
		if(rank[x] < rank[y]) swap(x, y);
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
		return;
	}
	bool same(int x,int y){
		return root(x) == root(y);
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