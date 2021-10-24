#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
template<typename T> class segtree{
private:
	int n;
  	T e = - 1e16;
  	vector<T> node;
public:
	segtree(int siz){
		n = 1;
		while(n < siz) n *= 2;
		node.resize(2*n-1, e); // tanigen
		// parent:(i-1)/2 children:2i+1,2i+2
	}
	T func(T x, T y){
		return max(x, y);
	}
	T& at(int v){
		return node[v+n-1];
    }
    void update(){
    	for(int i = n-2; i >= 0; i--){
        	node[i] = func(node[2*i+1], node[2*i+2]);
        }
    }
	void update(int v, T s){ // O(log n)
		v += n-1;
		node[v] = func(node[v], s);
		while(v > 0){
			v = (v-1) / 2;
			node[v] = func(node[2*v+1], node[2*v+2]);
		}
	}
	T query(int l, int r, int v = 0, int a = 0, int b = -1){ // [l,r)
		if(b == -1) b = n;
		if(b <= l || r <= a) return e;
		else if(l <= a && b <= r) return node[v];
		else{
			T s = query(l, r, 2*v+1, a, (a+b)/2);
			T t = query(l, r, 2*v+2, (a+b)/2, b);
			return func(s, t);
		}
	}
};

class lazysegtree{
private:
	int n;
	long e1 = 1e9, e2 = 0;
	vector<long> node, lazy;
public:
	lazysegtree(int siz){
		n = 1;
		while(n < siz) n *= 2;
		node.resize(2*n-1, e1);
		lazy.resize(2*n-1, e2); // tanigen
	}
private:
	void eval(int v, int l, int r){
		if(lazy[v] != e2){
			node[v] = node[v] + lazy[v];
			if(r - l > 1){
				lazy[2*v+1] = lazy[2*v+1] + lazy[v];
				lazy[2*v+2] = lazy[2*v+2] + lazy[v];
			}
			lazy[v] = e2;
		}
	}
public:
	void set(int v, int x){
		node[v+n-1] = x;
	}
	long get(int v){
		return node[v+n-1] + lazy[v+n-1];
	}
	void update(){
		for(int i = n-2; i >= 0; i--){
			node[i] = min(node[2*i+1], node[2*i+2]);
		}
	}
	void update(int l, int r, long x, int v = 0, int a = 0, int b = -1){ // node[i] += x, i in [l, r)
		if(b == -1) b = n;
		eval(v, a, b);
		if(b <= l || r <= a) return;
		else if(l <= a && b <= r){
			lazy[v] = x;
			eval(v, a, b);
		}
		else{
			update(l, r, x, 2*v+1, a, (a+b)/2);
			update(l, r, x, 2*v+2, (a+b)/2, b);
			node[v] = min(node[2*v+1], node[2*v+2]);
		}
	}
	long query(int l, int r, int v = 0, int a = 0, int b = -1){
		if(b == -1) b = n;
		if(b <= l || r <= a) return e1;
		eval(v, a, b);
		if(l <= a && b <= r) return node[v];
		int s = query(l, r, 2*v+1, a, (a+b)/2);
		int t = query(l, r, 2*v+2, (a+b)/2, b);
		return min(s, t);
	}
};

int main(){ // Range Minimum Query
	int n,q; cin>>n>>q;
	segtree<int> st(n);
	int c; int x, y;
	rep(i,0,q){
		cin>>c>>x>>y;
		if(c) cout<<st.query(x,y+1)<<endl;
		else st.update(x,y);
	}
}