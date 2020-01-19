#include <bits/stdc++.h>
using namespace std;
string comp(string a,string b){
	if(a.size()>b.size()){
		return a;
	}else if(a.size()<b.size()){
		return b;
	}else{
		int c,d;
		for(int i=0;i<a.size();i++){
			c=a.at(i)-'0';
			d=b.at(i)-'0';
			if(c>d){
				return a;
			}else if(c<d){
				return b;
			}
		}
	}return a;
}
int main(){
}