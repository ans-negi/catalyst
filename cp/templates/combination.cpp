vector<vector<ll>> dp;

dp.assign(N+1,vt<ll>(R+1,0));
dp[0][0] = 1;
for(ll i=0;i<N;i+=1){
	for(int j=0;j<=R;j+=1){
		if(j!=R) dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%mod;
		dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
	}
}
// pascal identity nCr = (n-1)C(r-1) + (n-1)Cr 

ll choose(ll n, ll r)
{
	return dp[n][r];
}
