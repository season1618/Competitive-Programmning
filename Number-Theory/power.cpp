#include<bits/stdc++.h>
using namespace std;
const long mod = 1e9+7
template<typename T>
T power(T x,T n){
	T i=0;T res=1;
	while(n>=(1<<i)){
		if(n&(1<<i)) res*=x;
		i++;x=x*x;
	}return res;
}
long modpow(long x,int n,long p){
	int i=0;long res=1;
	while(n>=(1<<i)){
		if(n&(1<<i)) (res*=x)%=p;
		i++;
		x=(x*x)%p;
	}return res;
}
int main(){
	long x;int n;cin>>x>>n;
	cout<<power(x,n)<<" "<<modpow(x,n,mod)<<endl;
}