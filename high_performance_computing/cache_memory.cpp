// on x86/x64 cache line size is 64 bytes to optimise lookup
// each primitive type is placed at address which is multiple of its size
// if not possible extra padding is added
// ontop struct adds padding to make total size multiple for its largest element

#include <iostream>

using namespace std;

struct g
{
	int i; // 4 byte
	char c; // 1 byte
	short x; // 2 byte
	int8_t t; // 1 byte
};

struct f
{
	int i; // 4 byte
	char c; // 1 byte
	int8_t t; // 1 byte
	short x; // 2 byte
};


int main() {
	cout<<"Size of g: "<<sizeof(g)<<"\n"; // 12 bytes
	cout<<"Size of f: "<<sizeof(f)<<"\n"; // 8 bytes
	
	return 0;
}
