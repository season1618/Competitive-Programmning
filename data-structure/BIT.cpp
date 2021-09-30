#include<bits/stdc++.h>
using namespace std;

template<typename T> class bit{
	int n;
	vector<T> node;
public:
	bit(int n){
		this->n = n;
		node.resize(n, -1);
	}
	int lsb(int v){ // Least Signifiant Bit
		return v & (-v);
	}
	void update(int i, T v){ // O(log n) a[i] += v;
		while(i < n){
			node[i] += v;
			i += lsb(i + 1);
		}
		return;
	}
	T acm(int i){ // O(log n) a[0] + ... + a[i-1]
		i--;
		T ret = 0;
		while(i >= 0){
			ret += node[i];
			i -= lsb(i + 1);
		}
		return ret;
	}
};