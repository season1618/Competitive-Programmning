#include<bits/stdc++.h>
using namespace std;
class suffix_array {
public:
    int n;
    string s;
    vector<int> sa, rank;
    suffix_array(stirng s){
        this->n = s.size();
        this->s = s + "$";
        sa.resize(n+1);
        rank.resize(n+1);
        for(int i = 0; i < n; i++){
            sa[i] = i;
        }
    }

private:
    int compare1(int i, int j, int lgt){
        if(lgt == 0) return 0;
        if(lgt == 1){
            if(s[i] > s[j]) return -1;
            else if(s[i] == s[j]) return 0;
            else return 1;
        }
        for(int k = 25; k >= 0; k--){
            if((lgt >> k) ^ 1) continue;
            int t = (1 << k);
            switch(compare(i, j, t)){
                case -1:
                    return -1;
                case 0:
                    return compare((i+t) % (n+1), (j+t) % (n+1), lgt-t);
                case 1:
                    return 1;
            }
        }
    }
    bool compare2(int i, int j){
        return compare1(i, j, n) + 1;
    }
    void construct(){
        sort()
    }
};