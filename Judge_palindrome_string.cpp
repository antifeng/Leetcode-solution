#include <algorithm>

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (s.empty() || s.length() == 1)
			return true;
        
        std::transform(s.begin(), s.end(), s.begin(), ::toupper); 
        string::iterator riter = s.end()-1;
        string::iterator liter = s.begin();
        
		int lval, rval;
	while (liter < riter) {
            	lval = rval = -1;
    	
		if ((*liter >= 'A' && *liter <= 'Z') || (*liter >= '0' && *liter <= '9'))
			lval = *liter;
		else 
			liter++;

			if ((*riter >= 'A' && *riter <= 'Z') || (*riter >= '0' && *riter <= '9'))
    			rval = *riter;
			else
				riter--;

			if ( lval == rval && lval!= -1){
				liter++;
				riter--;
			}
			else if (lval!=-1 && rval!= -1)
				return false;
		}

		return true;
    }
};
