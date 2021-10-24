#include<bits/stdc++.h>
using namespace std;
class suffix_array {
public:
    int n;
    string s;
    vector<int> sa, rank;
    suffix_array(string s){
        this->n = s.size();
        this->s = s + "$";
        sa.resize(n+1);
        rank.resize(n+1);
        for(int i = 0; i < n; i++){
            sa[i] = i;
        }
        construct();
    }

private:
    void construct(){ // O(nlog^2n)
        int len = 0;
        int m = n;
        while(m > 0){ m /= 2; len++; }
        int vec[len][n+1];
        for(int i = 0; i <= n; i++) vec[0][i] = s[i] - 'a';
        for(int k = 0; k < len-1; k++){
            map<pair<int,int>,int> mp;
            for(int i = 0; i <= n; i++) mp[{vec[k][i], vec[k][(i + (1<<k)) % (n+1)]}] = 1;
            int j = 0;
            for(auto [p, r] : mp) mp[p] = j++;
            for(int i = 0; i <= n; i++) vec[k+1][i] = mp[{vec[k][i], vec[k][(i + (1<<k)) % (n+1)]}];
        }
        pair<int,int> vp[n+1];
        for(int i = 0; i <= n; i++) vp[i].second = i;
        int sum = 0;
        for(int k = 0; k < len; k++){
            if((n + 1) & (1 << k)){
                sum += (1 << k);
                for(int i = 0; i <= n; i++){
                    int j = vp[i].second;
                    vp[i].first = vec[k][j+n+1-sum];
                }
                sort(vp,vp+n+1);
            }
        }
        for(int i = 0; i <= n; i++){
            int j = vp[i].second;
            sa[i] = j;
            rank[j] = i;
        }
    }
};
int main(){
    string s = "hello";
    suffix_array sa(s);
}