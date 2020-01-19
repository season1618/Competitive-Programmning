#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const int INF=1e9;
struct edge{
	int first;
	int second;
	int cost;
    /*void operator = (edge e){
        this->first = e.first;
        this->second = e.second;
        this->cost = e.cost;
        return;
    };*/
};
int N,M;
vector<edge> g;
int dist[size],pred[size];
void bellman_ford(int s){// O(VE)
	rep(i,0,N){ dist[i]=INF; pred[i]=-1; }
	dist[s]=0;
	rep(i,0,N){// n times
		rep(j,0,M){// all edges
            edge e=g[j];
			int v=e.first;
			int u=e.second;
			if(dist[u]>dist[v]+e.cost){
				dist[u]=dist[v]+e.cost;
				pred[u]=v;
				if(i==N-1){ cout<<"negative loop"<<endl; break; }
			}
		}
	}return;
}
int main(){
	cin>>N>>M;
	int a,b,c;
	rep(i,0,M){
		cin>>a>>b>>c;
		g.push_back({a,b,c});
        //g[i]={a,b,c};
	}bellman_ford(0);
}