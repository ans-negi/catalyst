#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string; // yay python!

#define send 			{ios_base::sync_with_stdio(false);}
#define help 			{cin.tie(NULL);}
#define all(x) 			x.begin(), x.end()
#define rev_all(x) 		x.rbegin(), x.rend()
#define umap 			unordered_map
#define uset 			unordered_set
#define MIN(v) 			*min_element(all(v))
#define MAX(v) 			*max_element(all(v))
#define pb			push_back
#define ar			array
#define vt 			vector

template<class T> void re(T& x){cin >> x;}
template<class H, class... T> void re(H& h, T&... t) {re(h);re(t...);}
template<class A> void re(vector<A>& x) {for(auto & v:x) re(v);}
template<class T> void print(T& x){cout << x <<" ";}
template<class A> void print(vector<A>& x) {for(auto & v:x){print(v);}cout<<"\n";}

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define log(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

const ll INF = 1e18;
const ll mod = 1e9+7;
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

/* stuff you should look for
	* overflows, correct data type, negative mod, res%res==0
	* read constraints properly, question might be much easier. Try fixing smaller constraints.
	* write down states, cases N<=6, see if there's a pattern. Write every obs.
	* try making into an equation and play around it. Write what remains fixed
	* DON'T GET STUCK ON ONE APPROACH/IMPLEMENTATION 
*/

