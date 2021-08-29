#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}

class union_find {
public:
    vector<int> par;
    union_find(int n):par(n){
        for(int i = 0; i < n; i++) par[i] = i;
    }
    int root(int v){
        if(par[v] == v) return v;
        return par[v] = root(par[v]);
    }
    void unite(int x, int y){
        x = root(x);
        y = root(y); 
        if(x == y) return;
        par[y] = x;
        return;
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
};
class union_find {
public:
	vector<int> par;
	vector<int> rank;
	union_find(int n):par(n),rank(n){
		for(int i = 0; i < n; i++){ par[i] = i; rank[i] = 1; }
	}
	int root(int v){
		if(par[v] == v) return v;
		return root(par[v]);
	}
	void unite(int x,int y){ // union by rank O(log n)
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
class union_find {
public:
	vector<int> par;
	vector<int> sub;
	union_find(int n):par(n),sub(n){
		for(int i = 0; i < n; i++){ par[i] = i; sub[i] = 1; }
	}
	int root(int v){
		if(par[v] == v) return v;
		return root(par[v]);
	}
	void unite(int x,int y){ // union by size O(log n)
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
	int N,M; cin>>N>>M;
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