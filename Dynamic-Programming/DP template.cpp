#include<bits/stdc++.h>
using namespace std;
int main(){//An=f(An-k,An-k+1,...,An-2,An-1)
	long N,M,K;cin>>N>>M>>K;
	long A[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
    long dp[N+1][M+1];
	for(int i=0;i<=N;i++){
        dp[i][0]=0;
    }long temp;
	for(long i=1;i<=N;i++){
		for(long j=1;j<=min(i,M);j++){
			temp=0;
			for(long k=max(j-1,i-K+1);k<i;k++){
				temp=max(temp,dp[k][j-1]);
			}dp[i][j]=temp+A[i-1];
		}
	}
    long ans=0;
    for(int i=N-K+1;i<=N;i++){
        ans=max(ans,dp[i][M]);
    }cout<<ans<<endl;
}