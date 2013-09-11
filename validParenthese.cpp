class Solution {
    private:
    bool isInPair(char left, char right) {
        if ( (left=='(' && right==')') 
            || (left=='[' && right==']') 
            || (left=='{' && right=='}') )
        return true;
        
        return false;
    }
public:
	//The idea is to use the feature of stack
	//for each char in the string try to match the top element in the stack
	//if matched, pop it, else push into. If it is valid, it will be empth finally
    bool isValid(string s) {
        
        if (s.empty())
            return true;
            
        std::stack<char> st;
        int len = s.length();
        
        for (int i=0; i<len; i++) {
            if (st.empty()) {
                st.push(s[i]);
            }
            
            else {
                char topch = st.top();
                if (isInPair(topch, s[i]))
                    st.pop();
                else
                    st.push(s[i]);
            }
        } //end for
        
        if (st.empty())
            return true;
        return false;
    }
};
