namespace number_theory{
	vector<ll> get_divisor(ll x)
	{
		vector<ll> res;
		set<ll> ans;
		for(ll i=1;i*i<=x;i+=1){
			if(x%i == 0){
				ans.insert(i);
				ans.insert(x/i);
			}
		}
		for(auto & val:ans) res.pb(val);
		return res;
	}

	map<ll,ll> get_prime_factor_freq(ll x)
	{ // sqrt x, can improve using seive 
		map<ll,ll> freq;
		for(ll i=2;i*i<=x;i+=1){
			ll count = 0;
			while(x % i == 0){
				x /= i;
				count += 1;
			}
			if(count) freq[i] = count;
		}
		if(x != 1) freq[x] += 1;
		return freq;	
	}
	
	/*map<ll,ll> factorize(ll n)
	{ // same as get_prime_factor_freq but uses seive. 
 	   	map<ll,ll>ans;
    		while (n != 1){
			ll fact = f[n];
        		ll cnt = 0;
        		while (n % fact == 0){
            			cnt++;
            			n /= fact;
        		}
        		ans[fact] = cnt;
    		}
    		return ans;
	}*/

	bool isprime(ll n) 
	{
	  	if (n <= 1) return false;
	  	if (n <= 3) return true;

	  	if (n % 2 == 0 || n % 3 == 0) return false;

	  	for (ll i = 5; i * i <= n; i += 6)
			if (n % i == 0 || n % (i+2) == 0)
		 	 return false;

	  	return true;
	}

	ll pw(ll a, ll p)
	{ // mod_inv == pw(a,mod-2)
		ll res = 1;
        	while(p){
                	if(p & 1){
                	        res = a * res % mod;
                	}
                	a = a * a % mod;
                	p >>= 1;
        	}
        	return res;
	}

	vt<ll> number_of_subsequences_with_gcd(map<ll,ll> & freq, int mx) // mobius inversion
	{ // res[x] gives subsequences with gcd = x   (mx)*lg(mx) preprocess O(1) queries
		mx += 1;
		vector<ll> res(mx,0); // [1,mx]
		for(ll i=mx-1;i>0;i-=1){
			int j = 2;
			while(i*j < mx){
				res[i] = mod_add(res[i],-res[i*j]);
				j += 1;
			}
			int c = 0;
			j = 1;
			while(i*j < mx){
				if(freq.count(i*j)){
					c += freq[i*j];
				}
				j += 1;		
			}
			ll pwans = pw(2,c)-1;
			res[i] = mod_add(res[i],pwans);
		}
		return res;	
	}

}

using namespace number_theory;
