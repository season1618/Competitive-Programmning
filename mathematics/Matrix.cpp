#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
template<typename T>
class Matrix:public vector<vector<T>>{
public:
    int n, m;
    Matrix(int n, int m):vector<vector<T>>(n, vector<T>(m)){
        this->n = n;
        this->m = m;
    }
    Matrix<T> operator = (Matrix<T> b){
		rep(i,0,n)rep(j,0,m) (*this)[i][j] = b[i][j];
		return *this;
	}
    Matrix<T> operator % (long p){
        Matrix<T> res(n, m);
        rep(i,0,n)rep(j,0,m) res[i][j] = (*this)[i][j] % p;
        return res;
    }
    Matrix<T> operator %= (long p){
        (*this) = (*this) % p;
        return *this;
    }
	Matrix<T> operator + (Matrix<T> b){
		Matrix<T> res(n, m);
		rep(i,0,n)rep(j,0,m) res[i][j] = (*this)[i][j] + b[i][j];
		return res;
	}
    Matrix<T> operator += (Matrix<T> b){
        *this = *this + b;
        return *this;
    }
	Matrix<T> operator * (Matrix<T> b){
		Matrix<T> res(n, b.m);
		rep(i,0,n)rep(j,0,b.m){
			rep(k,0,m) res[i][j] += (*this)[i][k] * b[k][j] % mod;
		}return res;
	}
    Matrix<T> operator *= (Matrix<T> b){
        *this = *this * b;
        return *this;
    }
};

Matrix<long> modpow(Matrix<long> a, long n, long p){
	int i = 0;
	Matrix<long> res(a.n, a.n);
    rep(i,0,a.n)rep(j,0,a.n) res[i][j] = i == j;
	while(n >= (1LL<<i)){
		if(n & (1LL<<i)) (res *= a) %= p;
		i++;
		a = (a * a) % p;
	}return res;
}

int main(){
    Matrix<int> a(2, 3), b(3, 4);
    rep(i,0,2)rep(j,0,3) a[i][j] = i + j;
    rep(i,0,3)rep(j,0,4) b[i][j] = i + j;
    a = a + a;
    Matrix<int> c = a * b;
    pprint(a,, 2, 3);
    pprint(b,, 3, 4);
    pprint(c,, 2 ,4);
    
    Matrix<long> A(2, 2);
	A[0][0] = 1; A[0][1] = 1; A[1][0] = 1; A[1][1] = 0;
	pprint(modpow(A, 5, mod),,2,2);
}