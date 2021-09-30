#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(int)(x);i<(int)(y);i++)
#define print(A,x,n) {rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;}
#define pprint(A,y,m,n) {rep(J,0,m){print(A[J],y,n);}}
class segtree{
private:
    int n;
    pair<int,int> e = {1e9, 0};
public:
    vector<pair<int,int>> node;
    void set(int siz){
        n = 1;
        while(n < siz) n *= 2;
        node.resize(2*n-1, e); // tanigen
        // parent:(i-1)/2 children:2i+1,2i+2
    }
    pair<int,int> at(int v){
        return node[v+n-1];
    }
    void update(){
        for(int v = n-2; v >= 0; v--){
            node[v] = min(node[2*v+1], node[2*v+2]);
        }
    }
    pair<int,int> query(int l, int r, int v = 0, int a = 0, int b = -1){ // [l,r)
        if(b == -1) b = n;
        if(b <= l || r <= a) return e;
        else if(l <= a && b <= r) return node[v];
        else{
            pair<int,int> s = query(l, r, 2*v+1, a, (a+b)/2);
            pair<int,int> t = query(l, r, 2*v+2, (a+b)/2, b);
            return min(s, t);
        }
    }
};

class euler_tour{ // vertex
public:
    int n;
    vector<vector<tuple<int,int,int>>> node;
    vector<int> euler; // 2*n-1
    vector<pair<int,int>> id;
  
    vector<int> id_color[100000];
    tuple<int,int,int> edge_color[100000];

    vector<int> depth;
    segtree st;

    euler_tour(int n){
        this->n = n;
        node.resize(n);
        id.resize(n);
        depth.resize(n); depth[0] = 0;
        st.set(2*n-1);
    }

private:
    int cnt[100000] = {};
    int len[100000] = {};

    void dfs(int v = 0, int p = -1){
        euler.push_back(v);
        id[v].first = euler.size() - 1;
        st.at(euler.size()-1) = {depth[v], v};
        for(auto [u, c, d] : node[v]){
            if(u == p) continue;
            cnt[c]++;
            len[c] += d;
            edge_color[u] = {c, cnt[c], len[c]};
            depth[u] = depth[v] + d;
            dfs(u, v);
            euler.push_back(v);
        }
        id[v].second = euler.size() - 1;
    }
public:
    void calc(){
        dfs();
        st.update();
    }
    int lca(int v, int u){ // Lowest Common Ancestor O(logN)
        return st.query(id[v].second, id[u].first + 1).second;
    }
    int dist_from_root(int v, int x, int y){
        if(v == 0) return 0;
        int r = *lower_bound(id_color[x].begin(),id_color[x].end(),id[v].first);
        int u = euler[r];
        int cnt = get<1>(edge_color[u]);
        int len = get<2>(edge_color[u]);
        return depth[v] - len + cnt * y;
    }
    int dist(int v, int u, int x, int y){
        return dist_from_root(v, x, y) + dist_from_root(u, x, y) - 2*dist_from_root(lca(v, u), x, y);
    }
};

int main(){
    int N,Q; cin>>N>>Q;
    euler_tour et(N);
    int a,b,c,d;
    rep(i,0,N-1){
        cin>>a>>b>>c>>d; a--; b--;
        et.node[a].push_back({b, c, d});
        et.node[b].push_back({a, c, d});
    }
  	et.calc();

    rep(i,1,N) et.id_color[i].push_back(0);
    rep(i,1,et.euler.size()-1){
        int v = et.euler[i];
        int c = get<0>(et.edge_color[v]);
        et.id_color[c].push_back(i);
    }
    rep(i,1,N) et.id_color[i].push_back(et.euler.size()-1);

    int x,y,u,v;
    rep(i,0,Q){
        cin>>x>>y>>u>>v; u--; v--;
        cout<<et.dist(u, v, x, y)<<endl;
    }
}