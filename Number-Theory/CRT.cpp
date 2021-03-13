#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
template<typename T> pair<T,T> bezout(T a,T b){// ax + by = 1, gcd(a, b)=1
	if(__gcd(a, b) != 1) return {0, 0};
	else if(b == 1) return {1, - a + 1};
    else if(a % b == 1) return {1, - a / b};
	else{
		pair<T,T> p = bezout(b, a % b);
		swap(p.first, p.second);
		p.second = p.second - (a / b) * p.first;
        return p;
	}
}
template<typename T> T CRT2(T a, T b, T m, T n){// O(log min(m,n))
	pair<T,T> res = bezout(m, n);
	T ans = (a * n * res.second + b * m * res.first) % (m * n);
	return ans;
}
template<typename T> T CRTn(int N, vector<T> &A, vector<T> &M){// O(log min(M))
	if(N == 1) return A[0];
	T res = 1;
	rep(i,0,N) res *= M[i];
	vector<T> vec(N);
	rep(i,0,N) vec[i] = bezout(M[i], res / M[i]);
	T ans = 0;
	rep(i,0,N) ans += A[i] * res / M[i] * vec[i].second;
	return ans % res;
}
int main(){// Chinese Reminder Theorem
	int N = 3;
	vector<int> A = {1, 2, 3};
	vector<int> M = {2, 3, 5};
	cout<<CRTn(N, A, M)<<endl;
}