namespace graph{
        void floyd_warshall(vt<vt<ll>> & d)
        { // all pair shortest path O(N^3) if any d[i][j] == -INF negative cycle exist
                ll N = size(d);
                for(ll i=0;i<N;i+=1) d[i][i] = 0LL;
                for(ll k=0;k<N;k+=1) for(ll i=0;i<N;i+=1) for(ll j=0;j<N;j+=1){
                        if(d[i][k] != INF and d[k][j] != INF){
                                auto new_dist = max(d[i][k]+d[k][j],-INF);
                                d[i][j] = min(d[i][j],new_dist);
                        }
                }
                for(ll k=0;k<N;k+=1){
                        if(d[k][k] < 0) for(ll i=0;i<N;i+=1) for(ll j=0;j<N;j+=1){
                                if(d[i][k] != INF and d[k][j] != INF){
                                        d[i][j] = -INF;
                                }
                        }
                }
        }
}
using namespace graph;

