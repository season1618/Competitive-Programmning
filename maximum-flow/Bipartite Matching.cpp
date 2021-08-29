#include<bits\stdc++.h>
using namespace std;
int N,M;int s,t;
const size=100,INF=100;
int vertex[size];int residual[size][size];
deque<int> task;vector<int> dist(size);
int temp; 
bool bfs(){//augmenting path
	for(int i=0;i<A;i++){
		if(vertex[i]==1){
			task.push_back(i);
		}
	}bool flag=false;
	while(task.size()>0){
		temp=task.front();
		if(!flag){
			for(int j=A+1;j<A+B;j++){
				if(residual[temp][j]==1){
					task.push_back(j);
				}
			}
		}else{
			if(vertex[temp]==1){
			}for(int i=0;i<A;i++){
				if(residual[temp][j]==1){
					task.push_back(j);
				}
			}
		}
	}
}
int main(){//O(VE^2)
	int a,b;
	for(int i=0;i<M;i++){//initialize
		residual[a][b]=1;//edge:capa-flow
		residual[b][a]=0;//reverse edge:flow
	}
}