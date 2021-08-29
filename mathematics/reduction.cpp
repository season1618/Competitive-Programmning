void reduction(vector<vector<bool>> &A, vector<vector<bool>> &P){
    int n = A.size();
    int m = A[0].size(); int l = P[0].size();
    int r = 0;
    for(int k = 0; k < m; k++){
        int i = r;
        for(; i < n; i++){
            if(A[i][k]){
                for(int j = k; j < m; j++) swap(A[r][j], A[i][j]);
              	for(int j = 0; j < l; j++) swap(P[r][j], P[i][j]);
                break;
            }
        }
        if(i == n) continue;
        for(int i = 0; i < n; i++){
            if(i == r) continue;
            if(A[i][k]){
              	for(int j = k; j < m; j++) A[i][j] = A[i][j] ^ A[r][j];
              	for(int j = 0; j < l; j++) P[i][j] = P[i][j] ^ P[r][j];
            }
        }
        r++;
    }
  	int s = r;
  	for(int i = r; i < n; i++){
      	for(int j = 0; j < l; j++){
          	if(P[i][j]) s = i + 1;
        }
    }
  	if(r < s) cout<<0<<endl;
  	else{
        long mod = 998244353;
        long ans = 1;
        rep(i,0,m-r) (ans *= 2) %= mod;
        cout<<ans<<endl;
    }//pprint(A,,n,m);pprint(P,,n,l);
}