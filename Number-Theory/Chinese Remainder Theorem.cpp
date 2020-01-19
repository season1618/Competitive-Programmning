#include<bits/stdc++.h>
using namespace std;
#define type int
struct solution{type x,y;};
solution bezout(type a,type b){//ax+by=1,gcd(a,b)=1
	solution sol;
	if(__gcd(a,b)!=1){//exception
		cout<<"error"<<endl;
		sol.x=0; sol.y=0; 
	}else if(a%b==1){
		sol.x=1;
		sol.y=-a/b;
	}else{
		sol=bezout(b,a%b);
		swap(sol.x,sol.y);
		sol.y=sol.y-(a/b)*sol.x;
	}return sol;
}
type CRT2(type a,type b,type m,type n){//O(log min(m,n))
	solution vec=bezout(m,n);
	type ans=a*n*vec.y+b*m*vec.x
	return ans%(m*n);
}
type CRTn(int N,vector<type> &A,vector<type> &M){//O(log min(M))
	if(N==1){
		return A[0];
	}
	type result=1;
	for(int i=0;i<N;i++){
		result*=M[i];
	}
	vector<solution> vec(N);
	for(int i=0;i<N;i++){
		vec[i]=bezout(M[i],result/M[i]);
	}
	type ans=0;
	for(int i=0;i<N;i++){
		ans+=A[i]*result/M[i]*vec[i].y;
	}return ans%result;
}
int main(){
	int N=3;
	vector<int> A={1,2,3};
	vector<int> M={2,3,5};
	cout<<CRTn(N,A,M);
}