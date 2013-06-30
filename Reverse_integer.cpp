class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool isNeg = (x < 0);
        
        if (isNeg)
            x = -x;
        int ret = 0;
        while (x > 0) {
                        
            ret = (x % 10)  + ret * 10;
            x = x / 10;
        }
        
         if (isNeg)
            ret = -ret;
        return ret;
    }
};
