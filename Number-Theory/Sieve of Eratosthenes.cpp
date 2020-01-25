#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const int size=1e5;
int id[size]={};//-1:not prime
deque<int> pr;
void sieve(int n){// Sieve of Eratosthenes O(NloglogN)
	int k=0;
    id[0]=-1; id[1]=-1;
    rep(i,0,n){
    	if(id[i]==0){
    		id[i]=k; k++;
    		pr.push_back(i);
    		for(int j=2*i; j<size; j+=i) id[j]=-1;
    	}
    }return;
}
vector<pair<int,int>> vp;
void factorization(int n){// O(\sqrt{n})
	vp.clear();
	rep(i,2,(int)sqrt(n)+1){
		if(n%i==0){
			int cnt=0;
			while(n%i==0){
				cnt++;
				n /= i;
			}
			vp.push_back({i,cnt});
		}
	}
	if(n>1) vp.push_back({n,1});
	return;
}
int main(){
    sieve(100);
    print(id,,100);
    print(pr,,25);

    factorization(60);
    print(vp,.first,5);
    print(vp,.second,5);
}