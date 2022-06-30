// N log N preprocess and lg N queries
const int mx = 1e7;
vt<int> f(mx+1,0);
vt<int> primes;

void seive(){
        f[1] = 1;
        for(int i=2;i<=mx; i+=1){
                if(not f[i]){
                        primes.push_back(i);
                        f[i] = i;
                }
                for(int j=0;j<primes.size() and i*primes[j]<=mx;j+=1){
                        f[i*primes[j]] = primes[j];
                        if(i%primes[j] == 0) break;
                }
        }
}

