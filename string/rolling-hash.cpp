#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(int)(x);i<(int)(y);i++)
#define print(A,x,n) {rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;}
#define pprint(A,y,m,n) {rep(J,0,m){print(A[J],y,n);}}
class rolling_hash {
    const long mod = 1e9 + 7;
    vector<long> hs, pw;
public:
    rolling_hash(string& s, long base = 10007){
        int n = s.size();
        hs.resize(n + 1);
        pw.resize(n + 1);
        hs[0] = 0; pw[0] = 1;
        for(int i = 0; i < n; i++){
            pw[i+1] = (pw[i] * base) % mod;
            hs[i+1] = (hs[i] * base + s[i]) % mod;
        }
    }
    long hash(int l, int r){
        return (hs[r] - hs[l] * pw[r-l] % mod + mod) % mod;
    }
    bool match(rolling_hash& b, int l1, int r1, int l2, int r2){
        return r1 - l1 == r2 - l2 && hash(l1, r1) == b.hash(l2, r2);
    }
    int lcp(rolling_hash& rh, int l1, int r1, int l2, int r2){ // Longest Common Prefix
        int a = 0, b = min(r1 - l1, r2 - l2) + 1;
        while(b - a > 1){
            int m = (a + b) / 2;
            if(hash(l1, l1 + m) == rh.hash(l2, l2 + m)) a = m;
            else b = m;
        }
        return a;
    }
};