ll pw(ll a, ll p){
	int res = 1;
	while(p){
		if(p & 1){
			res = a * res % mod;
		}
		a = a * a % mod;
		p >>= 1;
	}
	return res;
}
