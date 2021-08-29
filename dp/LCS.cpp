#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){// Longest Common Subseqence
	string s,t; cin>>s>>t;
	int dp[s.size()+1][t.size()+1]={};
	rep(i,1,s.size()+1)rep(j,1,t.size()+1){
		if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
		else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	}
	string ans="";
	int a=s.size(),b=t.size();
	int lgh=dp[s.size()][t.size()];
	while(lgh){
		if(s[a-1]==t[b-1]){
			ans=s[a-1]+ans;
			a--; b--;
			lgh--;
		}else{
			if(dp[a-1][b] > dp[a][b-1]) a--;
			else b--;
		}
	}cout<<ans<<endl;
}