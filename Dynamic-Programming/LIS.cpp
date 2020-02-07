#include<bits/stdc++.h>
using namespace std;
const int inf=1e5;
int N;vector<int> A(size);
int dp[size];
int binary(int a,int b,int s){
	int res;
	while(b-a > 1){
		res = (a+b)/2;
		if(dp[res] < s) a = res;// < or <=
		else b = res;
	}return b;
}
int LIS(vector<int> A){//Longest Increasing Subsequence
	int LIS = 0;
	dp[0] = 0;int k;
	rep(i,1,N+1){
		k = binary(0 , LIS+1 , A[i-1]);
		dp[k] = A[i-1];
		LIS = max(LIS , k);
	}return LIS;
}
int main(){
	cin>>N;
	rep(i,0,N) cin>>A[i];
	cout<<LIS(A)<<endl;
}