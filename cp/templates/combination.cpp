// pascal identity nCr = (n-1)C(r-1) + (n-1)Cr 
vector<vector<ll>> dp;
dp.assign(N+1,vt<ll>(R+1,0));
dp[0][0] = 1;
for(ll i=0;i<N;i+=1){
	for(int j=0;j<=R;j+=1){
		if(j!=R) dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%mod;
		dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
	}
}

ll choose(ll n, ll r)
{
	return dp[n][r];
}

// without pascal 
int mx = 4e5+1;
vt<ll> fact(mx+1,0), inv(mx+1,0);

fact[0] = 1;
FOR(i,1,mx+1) fact[i] = fact[i - 1] * i % mod;
inv[mx] = pw(fact[mx]);
FOR(i,mx-1,-1,-1) inv[i] = inv[i+1]*(i+1)%mod;

auto f = [](ll n, ll k){
    	if(k > n || n < 0 || k < 0)return 0LL;
	return fact[n]*inv[k]%mod*inv[n-k]%mod;
};

