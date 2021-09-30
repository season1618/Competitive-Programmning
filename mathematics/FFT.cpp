#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(int)(x);i<(int)(y);i++)
#define print(A,x,n) {rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;}
#define pprint(A,y,m,n) {rep(J,0,m){print(A[J],y,n);}}
const double pi = 3.14159265358979;
// Discrete Fourier Transformation
void dft(complex<double>* f, int n){
	complex<double> F[n] = {};
	rep(i,0,n){
		complex<double> zeta = { cos(2*pi*i/n) , sin(2*pi*i/n) };
		complex<double> pz = 1;
		rep(j,0,n){
			F[i] += f[j] * pz;
			pz *= zeta;
		}
	}
	rep(i,0,n) f[i] = F[i];
}

// Fast Fourier Transformation
void fft(complex<double>* f, int n){//n : power of 2, O(nlogn)
	if(n==1) return;
	complex<double> f0[n/2], f1[n/2];
	rep(i,0,n){
		if(i%2==0) f0[i/2] = f[i];
		else f1[i/2] = f[i];
	}
	fft(f0,n/2);
	fft(f1,n/2);
	complex<double> zeta = { cos(2*pi/n) , sin(2*pi/n) };
	complex<double> pz = 1;
	rep(i,0,n){
		f[i] = f0[i % (n/2)] + pz * f1[i % (n/2)];
		pz *= zeta;
	}
}

void ifft(complex<double>* f, int n){
	reverse(f+1, f+n);
    fft(f, n);
    rep(i,0,n) f[i] /= n;
}

void convolution(complex<double>* A, complex<double>* B, complex<double>* C, int n){
	fft(A,n);
	fft(B,n);
	rep(i,0,n) C[i] = A[i] * B[i];
	ifft(C,n);
}

int main(){
	int N; cin>>N;
	int n = 1;
	while(n < 2*N-1) n <<= 1;
	complex<double> A[n], B[n], C[n];
	rep(i,0,N){
		double x,y; cin>>x>>y;
		A[i] = x;
		B[i] = y;
	}
	rep(i,N,n) A[i] = B[i] =0;
	convolution(A,B,C,n);
    cout<<0<<endl;
	rep(i,0,2*N-1){
		cout<<(int)(C[i].real() + 0.1)<<endl;
	}
}