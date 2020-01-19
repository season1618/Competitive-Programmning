#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const long inf=(1l<<31)-1;
int k=(1<<17);
class segment{
public:
	vector<long> g;
	segment(int n):g(n){
		rep(i,0,n) g[i]=inf;//tanigen
		// parent:(i-1)/2 children:2i+1,2i+2
	}
	long func(long x,long y){
		return min(x,y);
	}
	void update(int v,long s){
		v+=k-1; g[v]=s;
		while(v>0){
			v=(v-1)/2;
			g[v]=func(g[2*v+1],g[2*v+2]);
		}return;
	}
	long query(int l,int r,int v,int a,int b){// [l,r)
		if(b<=l||r<=a) return inf;
        else if(l<=a&&b<=r) return g[v];
        else{
            long s=query(l,r,2*v+1,a,(a+b)/2);
            long t=query(l,r,2*v+2,(a+b)/2,b);
            return func(s,t);
        }
	}
};
int main(){// Range Minimum Query
	int n,q; cin>>n>>q;
	segment sg(2*k-1);
	int c;int x;long y;
	rep(i,0,q){
		cin>>c>>x>>y;
		if(c) cout<<sg.query(x,y+1,0,0,k)<<endl;
		else sg.update(x,y);
	}
}