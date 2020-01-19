#include<bits/stdc++.h>
using namespace std;
const int size=1e5;
int num[size]={};//0:prime,1:not prime
void sieve(){
    num[0]=1;num[1]=1;
    rep(i,0,size)if(num[i]==0){
        for(int j=2*i;j<size;j=j+i) num[j]=1;
    }return;
}
deque<int> prime;
void judge(){
	rep(i,0,size)if(num[i]==0) prime.push_back(i);
    return;
}
int main(){
    sieve();
    judge();
}