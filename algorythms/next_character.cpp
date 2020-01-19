#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;cin>>s>>t;
	int n=s.size();s+=s;
	vector<map<char,long>> next(n);
	int temp;
	rep(i,0,26){
		char c=(char)(i+97);
	    for(int j=2*n-1;j>=0;j--){
		    if(temp) next[j%n][c]=(temp-j-1)%n+1;
		    if(s.at(j)==c) temp=j;
		}
	}
	long ans;
	rep(i,0,n)if(s.at(i)==t.at(0)){ ans=i;break; }
	rep(i,1,t.size()){
		ans+=next[ans%n][t.at(i)];
	}cout<<ans+1<<endl;
}
