namespace string_ops{

	string get_diff(str str1, str str2)
	{
		// str1 value >= str2 value and strings are non empty
		str res = "";
 
		int n1 = str1.length(), n2 = str2.length();
    		int diff = n1 - n2;
    		int carry = 0;
 
    		FOR(i,n2-1,-1,-1){    
        		int sub = ((str1[i + diff] - '0') - (str2[i] - '0')- carry);
        		if (sub < 0) {
            			sub = sub + 10;
            			carry = 1;
        		}else {
            			carry = 0;
 			}
 	       		res.push_back(sub + '0');
    		}
 
        	FOR(i,n1-n2-1,-1,-1){
	    		if (str1[i] == '0' && carry) {
            			res.push_back('9');
            			continue;
        		}
        		int sub = ((str1[i] - '0') - carry);
        		if (i > 0 || sub > 0) res.push_back(sub + '0');
        		carry = 0;
    		}
    		reverse(all(res));
 		return res;
	}
}
using namespace string_ops;
