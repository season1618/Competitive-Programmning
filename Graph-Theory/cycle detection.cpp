#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int N,M;
vector<int> g[1000];
int visit[1000] = {};
int depth[1000] = {};
deque<int> dq(2000,0);
bool dfs(int v){// O(N + M)
    bool flag = false;
	visit[v]++;
	for(int u:g[v]){
        if(visit[u] == 0){
            depth[u] = depth[v] + 1;
            if(dfs(u)) flag = true;
        }else if(visit[u] == 1){
            flag = true;
            if(depth[v] - depth[u] > dq.size()) continue;// smallest
			dq.clear();// size : depth[v] - depth[u] + 1
			rep(i,0,N)if(visit[i] == 1 && depth[i] >= depth[u]) dq.push_back(i+1);
		}
	}visit[v]++;
    return flag;
}
int main(){
	cin>>N>>M;
	int a,b;
	rep(i,0,M){
		cin>>a>>b; a--; b--;
		g[a].push_back(b);
	}
	rep(i,0,N){// O(N^2)
        if(visit[i]) continue;
        rep(j,0,N) depth[j] = 0;
        dfs(i);
    }
    if(dq.size() == 2000) cout<<-1<<endl;
	else{
		cout<<dq.size()<<endl;
		rep(i,0,dq.size()) cout<<dq[i]<<endl;
	}
}