// do consider global var states

ll mx = 2e5;
vector<vector<ll>> graph(mx);
vector<ll> label(mx,0), sz(mx,1); // curr component and sz

vector<ll> nedges(mx,0); //undirected edges in a component

void relabel(ll v, ll target)
{
        if(label[v] == target){return;}
        label[v] = target;
        for(auto & node:graph[v]){
                relabel(node,target);
        }
}

void merge(ll u, ll v)
{
        graph[u].push_back(v);
        graph[v].push_back(u);
        ll comp_u = label[u], comp_v = label[v];
        nedges[comp_u] += 1; // joining edge

        if(comp_u == comp_v){return;}

        if(sz[comp_u] > sz[comp_v]){
                swap(comp_u,comp_v);
                swap(u,v);
        }
        // assume comp_u <= comp_v
        relabel(u,comp_v);
        sz[comp_v] += sz[comp_u];
        nedges[comp_v] += nedges[comp_u];
}

for(ll i=0;i<N;i+=1){
        label[i] = i; // unique starting label
}

for(ll i=0;i<M;i+=1){
	ll u,v;
        cin>>u>>v;
        u -= 1;
        v -= 1;
        merge(u,v);
}

