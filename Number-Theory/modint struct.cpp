#include<bits/stdc++.h>
using namespace std;
const long mod=1e9+7;
struct modint{
    long a;// a<p
    const long p = mod;
    modint operator = (modint b){
        (*this).a = b.a;
        return *this;
    }
    modint operator % (long b){
    	return {(*this).a % b};
    };
    modint operator + (modint b){
        return {((*this).a + b.a) % p};
    };
    modint operator - (modint b){
    	return {((*this).a - b.a + p) % p};
    };
    modint operator * (modint b){
    	return {((*this).a * b.a) % p};
    };
    modint operator / (modint b){
    	return {((*this).a * inv(b).a) % p};
    };
private:
    modint inv(modint x){// p is prime
    	long y = x.a;
    	if(y == 0) return {0};
    	int i = 0; long res = 1;
	    while( (p-2) >= (1<<i) ){
		    if((p-2) & (1<<i)) (res *= y) %= p;
		    i++; y = (y * y) % p;
		}return {res};
    };
};
int main(){
    modint x={6},y={7};
    cout<<(x+y).a<<endl;
    cout<<(x-y).a<<endl;
    cout<<(x*y).a<<endl;
    cout<<(x/y).a<<endl;
}