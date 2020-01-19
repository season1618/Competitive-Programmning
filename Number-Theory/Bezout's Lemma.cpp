#include<bits/stdc++.h>
using namespace std;
template<typename T>
class dioph{
public:
	pair<T,T> extEuc(T a,T b){//ax+by=1
		pair<T,T> ans;
		T g=__gcd(a,b);
		a/=g;b/=g;
		if(a%b==1) ans={1,-a/b};
		else{
			ans=extEuc(b,a%b);
			swap(ans.first,ans.second);
			ans.second = ans.second-(a/b)*ans.first;
		}return ans;
	}
	pair<T,T> Bezout(T a,T b,T c){//ax+by=c
		if(!(a||b||c)) return {0,0};
		T g=__gcd(a,b);
		if(!c%g) return {0,0};
		a/=g;b/=g;
		pair<T,T> ans=extEuc(a,b);
		ans.first*=c;ans.second*=c;
		return ans;
	}
	T inv(T x,T p){//x^-1 mod p
		if(__gcd(x,p)!=1) return 0;
		pair<T,T> ans=extEuc(x,p);
		return (ans.first % p + p) % p;
	}
};
int main(){
	int a,b;cin>>a>>b;
	dioph<int> d;
	pair<int,int> res=d.extEuc(a,b);
	cout<<res.first<<" "<<res.second<<endl;
	cout<<d.inv(a,b)<<endl;
}