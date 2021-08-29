#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const int siz=1e5;
vector<int> prime;
void sieve(int n){ // sieve of Eratosthenes O(nloglogn)
	vector<bool> isprime(n+1, 1);
    rep(i,2,n+1){
    	if(!isprime[i]) continue;
		prime.push_back(i);
		for(int j = 2*i; j <= n; j += i){
			isprime[j] = 0;
		}
    }
}
void sieve(int n){ // O(n)
	int minfactor[n] = {};
	rep(i,2,n){
		if(!factor[i]){
			prime.push_back(i);
			minfactor[i] = i;
		}
		for(int p:prime){
			if(p*i >= n || p > minfactor[i]) break;
			minfactor[p*i] = p;
		}
	}
}

//-------------------------------------------------------------

vector<int> prime;
int minfactor[siz] = {}, mobius[siz];
void sieve(int n){ // sieve of Eratosthenes
	vector<bool> isprime(n+1, 1);
	rep(i,0,n+1) mobius[i] = 1;
    rep(i,2,n+1){
    	if(!isprime[i]) continue;
		prime.push_back(i);

		minfactor[i] = i;
		mobius[i] = -1;

		for(int j = 2*i; j <= n; j += i){
			isprime[j] = 0;

			if(!minfactor[j]) minfactor[j] = i;
			if((j/i) % i == 0) mobius[j] = 0;
			else mobius[j] = - mobius[j];
		}
    }
}
vector<pair<int,int>> factorize(int n){ // O(logn)
	vector<pair<int,int>> ret;
	while(n > 1){
		int p = minfactor[n];
		int exp = 0;
		while(n % p == 0){
			n /= p;
			exp++;
		}
		ret.push_back({p, exp});
	}
	return ret;
}
vector<int> divisor(int n){ // O(\sigma(n)) \sigma(n) <= 1344, n <= 1e9
	vector<int> ret({1});
	vector<pair<int,int>> vp = factorize(n);
	for(auto [p, exp]:vp){
		int s = ret.size();
		for(int i = 0; i < s; i++){
			int k = 1;
			for(int j = 1; j <= exp; j++){
				k *= p;
				ret.push_back(v*k);
			}
		}
	}
	return ret;
}

//----------------------------------------------------------------

vector<pair<int,int>> factorize(int n){ // O(\sqrt{n})
	vector<pair<int,int>> ret;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			int exp = 0;
			while(n % i == 0){
				n /= i;
				exp++;
			}
			ret.push_back({i, exp});
		}
	}
	if(n > 1) ret.push_back({n, 1});
	return ret;
}
int main(){
    sieve(100);
    print(pr,,25);

    factorize(60);
    print(vp,.first,5);
    print(vp,.second,5);
}