ll pw(ll a, ll p=mod-2){
	// p = mod-2 for mod inverse
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
