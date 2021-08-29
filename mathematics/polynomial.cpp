#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(int)(x);i<(int)(y);i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int siz=3e5;
const int inf=1e9;
struct rational{
	int a, b;
	rational(int a){ this->a = a; this->b = 1; }
	rational(int a, int b){
		int g = gcd(a, b);
		this->a = a/g; this->b = b/g;
	}
	rational operator + (rational r){
		int c = r.a; int d = r.b;
		return rational(a*d + b*c, b*d);
	}
	rational operator - (rational r){
		int c = r.a; int d = r.b;
		return rational(a*d - b*c, b*d);
	}
	rational operator * (rational r){
		int c = r.a; int d = r.b;
		return rational(a*c, b*d);
	}
	rational operator / (rational r){
		int c = r.a; int d = r.b;
		return rational(a*d, b*c);
	}
    void out(){
        cout<<a<<" / "<<b<<endl;
    }
};

template<typename T>
class polynomial:public vector<T>{
public:
  	int n;
	polynomial(int n):vector<T>(n+1){ this->n = n; };
	polynomial(initializer_list<T> init):vector<T>(init.begin(), init.end()){ this->n = init.size()-1; }
	polynomial operator + (polynomial b){
		int m = max(n, b.n);
		polynomial ret(m);
		for(int i = 0; i < m+1; i++) ret[i] = (*this)[i] + b[i];
		return ret;
	}
	polynomial operator * (polynomial b){
		int m = n + b.n;
		polynomial ret(m);
		for(int i = 0; i < n + 1; i++){
			for(int j = 0; j < b.n + 1; j++){
				ret[i+j] += (*this)[i] * b[j];
			}
		}
		return ret;
	}
	polynomial derivative(){
		polynomial ret(n-1);
		for(int i = 0; i < n; i++) ret[i] = (i+1) * (*this)[i+1];
		return ret;
	}
	polynomial integral(){
		polynomial ret(n+1); ret[0] = 0;
		for(int i = 1; i < n+2; i++) ret[i] = (*this)[i-1] / i;
		return ret;
	}
	void out(){
		for(int i = 0; i < n+1; i++){
          	if((*this)[i] == 0) continue;
			if((*this)[i] > 0) cout<<" + ";
            else cout<<" - ";
            if(i == 0 || abs((*this)[i]) != 1) cout<<abs((*this)[i]);
            if(i > 0) cout<<"x";
          	if(i > 1) cout<<"^"<<i;
		}cout<<endl;
	}
};

int main(){
	polynomial<int> a({1, 1, 1, 1, 1}), b({1, -1});
	a.out();
    a.derivative().out();
    a.derivative().integral().out();
    b.out();
    (a*b).out();

    rational p(1, 2), q(1, 3);
    (p+q).out(); (p*q).out();
}