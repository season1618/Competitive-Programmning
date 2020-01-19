#include<bits/stdc++.h>
using namespace std;
vector<int> RLE(int N,vector<int> A,int a,int b){
	vector<int> B;
	int count=0;int temp=a;
	for(int i=0;i<N;i++){
		if(A[i]==a){
			if(temp==a){
				count++;
			}else{
				B.push_back(count);
                temp=a;
				count=1;
			}
		}else if(A[i]==b){
			if(temp==b){
				count++;
			}else{
				B.push_back(count);
                temp=b;
				count=1;
			}
		}
	}B.push_back(count);
	return B;
}
int main(){
	int N;cin>>N;
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
	}vector<int> B=RLE(N,A,1,2);
    for(int i=0;i<B.size();i++){
		cout<<B[i]<<" ";
	}
}