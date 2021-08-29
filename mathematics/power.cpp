#include<bits/stdc++.h>
using namespace std;
const long mod = 1e9+7
template<typename T>
T power(T x, T n){
	ret = 1; T i = 0;T
	while(n >= (1<<i)){
		if(n & (1<<i)) ret *= x;
		i++; x = x * x;
	}return ret;
}
long modpow(long x, int n, long p){
	long ret = 1; int i = 0;
	while(n >= (1<<i)){
		if(n & (1<<i)) (ret *= x) %= p;
		i++;
		x = (x * x) % p;
	}return ret;
}
int main(){
	long x;int n;cin>>x>>n;
	cout<<power(x,n)<<" "<<modpow(x,n,mod)<<endl;
}