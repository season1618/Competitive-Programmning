#include<bits/stdc++.h>
using namespace std;

vector<int> BIT={5,8,7,24,6,10,1,37};
int LSB(int n){	return n&(-n); }
int cum(int n){//O(log n)
	n++;int sum=0;
	while(n>0){
		sum=sum+BIT[n-1];
		n-=LSB(n);
	}return sum;
}
void update(int n,int k){//O(log n)
	n++;
	while(n<=BIT.size()){
		BIT[n-1]=BIT[n-1]+k;
		n+=LSB(n);
	}return;
}
int main(){
}
