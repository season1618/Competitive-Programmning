#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(int)(x);i<(int)(y);i++)
#define print(A,x,n) {rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;}
#define pprint(A,y,m,n) {rep(J,0,m){print(A[J],y,n);}}
template<class BidirectionalIterator>
bool next_combination(BidirectionalIterator begin, BidirectionalIterator end, int n){
	auto it = end;
	it--;
	int prev, next = n;
	for(; ; it--){
		if(*it < next - 1){
			(*it)++;
			prev = *it;
			break;
		}
        next = *it;
		if(it == begin) return false;
	}
	for(; it != end; it++){
		*it = prev++;
	}
	return true;
}

int main(){
    int a[3];
    rep(i,0,3) a[i] = i;
    do{
      	rep(i,0,3) cout<<a[i]<<" ";
        cout<<endl;
    }while(next_combination(a, a + 3, 5));
}