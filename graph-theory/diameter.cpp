#include <bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(),(x).end()
int N;
vector<int> g[size];//g is a tree
vector<int> dist(int u){
	vector<int> d(N,-1);//distance between u and x
	vector<int> c={u};//node in order to close to u
	d[u]=0;
	for(int i=0;i<c.size();i++){
		int x=c[i];
		for(int y:g[x]){
			if(d[y]==-1){
				d[y]=d[x]+1;
				c.push_back(y);
			}
		}
	}return d;
}
int main(){
	cin>>N;
	int a,b;
	for(int i=0;i<N-1;i++){
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> temp;
	temp=dist(0);
	int v=max_element(range(temp))-temp.begin();//bottom
	temp=dist(v);
	int diam=*max_element(range(temp));//diameter
}