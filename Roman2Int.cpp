class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty())
            return 0;
        int len = s.length();
        int retVal = 0;
        char cp = ' ';
        
        //Note: check logic before you run it
        for (int i=0; i<len; i++) {
            
            if (s[i] == 'M' ) {
                if ( cp == 'C')
                    retVal += 800;
                else
                    retVal += 1000;
            }
            else if(s[i] == 'D' ) {
                if ( cp == 'C')
                    retVal += 300;
                else
                    retVal += 500;
            }
            else if(s[i] == 'C' ) {
                if ( cp == 'X')
                    retVal += 80;
                else
                    retVal += 100;
            }
            else if(s[i] == 'L' ) {
                if ( cp == 'X')
                    retVal += 30;
                else
                    retVal += 50;
            }
            else if(s[i] == 'X' ) {
                if ( cp == 'I')
                    retVal += 8;
                else
                    retVal += 10;
            }
            else if(s[i] == 'V' ) {
                if ( cp == 'I')
                    retVal += 3;
                else
                    retVal += 5;
            }
            else
                retVal += 1;
            cp = s[i];
        }
        return retVal;
    }
};
