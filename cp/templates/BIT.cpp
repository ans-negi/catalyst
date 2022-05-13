// update a pt and new psum in lgN
namespace BIT{
    void upd(vector<int>& tree,int i,int val) { // in range(1,N)
        for (; i<size(tree); i+=i&(-i)) tree[i]+=val;
    }

    int get_sum(vector<int>& tree,int i) { // sum in range [1,i]
        int sum = 0;
	    for(; i>0; i-=i&(-i)) sum += tree[i];
	    return sum;
    }
}
using namespace BIT;

vt<int> tree(N+1,0);
