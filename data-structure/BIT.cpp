#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BIT:public vector<T>{
public:
	int length;
	BIT(int length):vector<T>(length, 0){
		this->length = length;
	}
	int LSB(int n){ // Least Signifiant Bit
		return n & (-n);
	}
	T acm(int i){ // O(log n) a[0] + ... + a[i-1]
		i--;
		T ret = 0;
		while(i >= 0){
			ret += (*this)[i];
			i -= LSB(i + 1);
		}
		return ret;
	}
	void update(int i, T v){ // O(log n) a[i] += v;
		while(i < length){
			(*this)[i] += v;
			i += LSB(i + 1);
		}
		return;
	}
};