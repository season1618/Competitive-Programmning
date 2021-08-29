#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){// Longest Increasing Subsequence O(NlogN)
	int N; cin>>N;
	int a[N];
	rep(i,0,N) cin>>a[i];
	pair<int,int> goal[N] ;// length k -> smallest latest item, index
	int dist[N] = {},prev[N];
	rep(i,0,N) goal[i] = {inf, 0};
	rep(i,0,N){
		int k = lower_bound(goal, goal + N, make_pair(a[i], i)) - goal;
		// <= {a[i], i} < {a[i], -i}
        dist[i] = k;
        prev[i] = (k == 0 ? -1 : goal[k-1].second);
        goal[k] = {a[i], i};

        /*int k = lower_bound(dp1, dp1 + N, make_pair(a[i], -i)) - dp1;
		// <= {a[i], i} < {a[i], -i}
        vp1[i].first = k;
        vp1[i].second = (k == 0 ? -1 : -dp1[k-1].second);
        dp1[k] = {a[i], -i};*/
    }
    cout<<lower_bound(goal, goal + N, make_pair(inf, 0)) - goal<<endl;
    print(dist,,N);print(prev,,N);
}