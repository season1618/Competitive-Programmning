template<class T> T power(T x, T exp){
	T ret = 1;
	while(exp){
		if(exp % 2) (ret *= x) %= mod;
		x = (x * x) % mod;
		exp /= 2;
	}
	return ret;
}
long modpow(long x, int exp, long mod){
	long ret = 1;
	while(exp){
		if(exp % 2) (ret *= x) %= mod;
		x = (x * x) % mod;
		exp /= 2;
	}
	return ret;
}