class Solution {
public:
    // Note case: +00131204 or "   +123"
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!str)
            return 0;
        
        //Skip the prefix space 
        while ( *str == ' ')
        {   str++;  }
        
        bool isNeg = ( '-' == *str );
        if ('-' == *str || *str == '+')
            str++;
        
        long long retVal = 0;
        /*
         Note these overflow cases
         The max of positive int is 0x7fffffff
         The min of negative int is 0x80000000
         To check whether overflow or not, using long long to represent the intrger value
         */
        
        while ( *str != '\0' && *str != '.' && *str >= '0' && *str <= '9') {
            long long tmp = retVal * 10 + (int (*str) - '0');
            
            if (tmp > 0x7fffffff ) {
                
                if (!isNeg)
                    retVal = 0x7fffffff;
                else
                    retVal = 0x80000000;
                return retVal;
            }
            else
                retVal = tmp;
            str++;
        }
        
        if (isNeg)
            retVal = -retVal;
        
        return retVal;
    }
};
