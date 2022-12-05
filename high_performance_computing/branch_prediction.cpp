// save time when an event is highly or unlikley

#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

#define likely(x)      __builtin_expect(x, 1)
#define unlikely(x)      __builtin_expect(x, 0)

using namespace std;

double f(vector<int> & a, int & P)
{
	volatile int res = 0;
	
	auto rng = std::default_random_engine {};
	shuffle(a.begin(), a.end(), rng);
	
	auto t_start = std::chrono::high_resolution_clock::now();
	for(auto & v:a) if (unlikely(v < P)) res += 1;
	
	auto t_end = chrono::high_resolution_clock::now();
	double elapsed_time_ms = chrono::duration<double, std::milli>(t_end-t_start).count();
	return elapsed_time_ms;
}

int main() {
	const int N = 1e5;
	vector<int> a(N);
	for (int i = 0; i < N; i++) a[i] = rand() % 100;
	
	int P = 10; // defining probability
	int count = 0;
	for(auto & v:a) if(v < P) count += 1;
	cout<<count<<" ";
	
	double res = 0;
	for(int i=0;i<3;i+=1) res += f(a,P);
	cout<<res/3<<"\n";
	
	return 0;
}
