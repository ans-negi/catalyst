namespace equations{
	int gcd(int a, int b, int& x, int& y) { // reverse euclid
    		if (b == 0) {
        		x = 1;
        		y = 0;
        		return a;
    		}
    		int x1, y1;
    		int d = gcd(b, a % b, x1, y1);
    		x = y1;
    		y = x1 - y1 * (a / b);
    		return d;
	}
	
	// eq must be of form ax+by=gcd(a,b) else no solution acc. bezout theorem
	bool diophantine_solution(int a, int b, int c, int &x0, int &y0, int &g) { 
		// a=0, b=0 ignored case
		g = gcd(abs(a), abs(b), x0, y0);
    		if (c % g) {
        		return false;
    		}

    		x0 *= c / g;
    		y0 *= c / g;
    		if (a < 0) x0 = -x0;
    		if (b < 0) y0 = -y0;
    		return true;
	} // get other solution by x = x_old + k*(b/g) , y = y_old - k*(a/g)
	


}

using namespace equations;
