#include<bits\stdc++.h>
using namespace std;
int N,M;int s,t;
const size=100,INF=100;
int residual[size][size];
deque<int> task;vector<int> dist(size);
bool bfs(){//augmenting path
	bool flag=false;int temp;
	while(task.size()>0){
		for(int i=0;i<N;i++){
			temp=task.front();
	        if(residual[temp][i]>0){
		        task.push_back(i);
		        dist[i]=min(dist[temp]+1,dist[i]);
		        if(i==t){
		        	flag=true;
		        	task.clear(); dist.clear();
		        	return flag;
		        }
	        }
		}task.pop_front();
	}
}
int main(){//O(VE^2)
	int a,b,c;
	for(int i=0;i<M;i++){//initialize
		cin>>a>>b>>c;
		residual[a][b]=c;//edge:capa-flow
		residual[b][a]=0;//reverse edge:flow
	}do{
		task.push_back(s);
		for(int i=0;i<N;i++){
			dist(i)=INF;
		}dist(s)=0;
	}while(bfs())
}