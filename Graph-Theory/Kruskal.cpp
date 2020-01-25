#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int N,M;
priority_queue<pair<int,pair<int,int>>> pq;
class union_find{//union by rank
public:
	vector<int> g;
	union_find(int n){
		rep(i,0,n) g.push_back(i);
	}
	int root(int v){
		if(this->g[v]==v) return v;
		else{ this->g[v]=root(this->g[v]);return this->g[v]; }
	}
	void unite(int x,int y){ 
		this->g[root(x)]=root(y);
		return;
	}
	bool same(int x,int y){
		return root(x)==root(y);
	}
};
int kruskal(union_find uf){// O(ElogV)
	int cost=0;
	int v,u;
	while(!pq.empty()){
		v=pq.top().second.first;
		u=pq.top().second.second;
		if(!uf.same(v,u)){
			uf.unite(v,u);
			cost-=pq.top().first;
		}pq.pop();
	}return cost;
}
int main(){
	cin>>N>>M;
	union_find uf(N);
	int a,b;int c;
	rep(i,0,M){
		cin>>a>>b>>c;a--;b--;
		pq.push({-c,{a,b}});
	}
	cout<<kruskal(uf)<<endl;
}