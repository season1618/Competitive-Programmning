#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e2;
const int inf=1e9;
int N;
double X[50],Y[50];
double dist(double a,double b,double c,double d){
	return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}
bool obtuse(double a,double b,double c){
	return (a*a > b*b + c*c || b*b > c*c + a*a || c*c > a*a + b*b);
}
pair<pair<double,double>,double> excenter(int i,int j,int k){
	double a = dist(X[j],Y[j],X[k],Y[k]);
	double b = dist(X[k],Y[k],X[i],Y[i]);
	double c = dist(X[i],Y[i],X[j],Y[j]);
	double det = - (X[i] - X[j])*(Y[k] - Y[i]) + (Y[i] - Y[j])*(X[k] - X[i]);
    double A = X[i]*X[i] + Y[i]*Y[i];
    double B = X[j]*X[j] + Y[j]*Y[j];
    double C = X[k]*X[k] + Y[k]*Y[k];
    x = (Y[j] - Y[k])*A + (Y[k] - Y[i])*B + (Y[i] - Y[j])*C;
    y = (X[j] - X[k])*A + (X[k] - X[i])*B + (X[i] - X[j])*C;
    x /= 2*det;
    y /= 2*det;
    return {{x , y} , dist(X[i],Y[i],x,y)};
}
int main(){
	cin>>N;
	rep(i,0,N) cin>>X[i]>>Y[i];
	double x = X[0];
	double y = Y[0];
	double r = 0;
	rep(i,1,N){
		if(dist(X[i],Y[i],x,y) <= r) continue;
		x = (X[i] + X[0])/2;
		y = (Y[i] + Y[0])/2;
		r = dist(X[i],Y[i],X[0],Y[0])/2;
		rep(j,1,i){
			if(dist(X[j],Y[j],x,y) <= r) continue;
			pair<pair<double,double>,double> temp = excenter(i,j,0);
			x = temp.first.first;
			y = temp.first.second;
			r = temp.second;
			rep(k,1,j){
				if(dist(X[k],Y[k],x,y) <= r) continue;
				else{
					temp = excenter(i,j,k);
					x = temp.first.first;
					y = temp.first.second;
					r = temp.second;
				}
			}
		}
	}pair<pair<double,double>,double> temp=excenter(0,1,2);
    cout<<temp.first.first<<" "<<temp.first.second<<endl;
	cout.precision(10);
	cout<<fixed<<r<<endl;
}