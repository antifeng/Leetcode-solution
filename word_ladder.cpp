class Solution {
public:
    /**
      * The key idea is to apply BFS to enumerate all morph words from inner core to outer ring
      * To erase valid morph word from dict is also important to reduct running time
      * To take the advantage of unordered_set::find in O(1) rather than iterate all ele in dict is also cretical 
      * to reduce running time
      * in queue, pop() will remove the front() ele
      * in vector, pop_back() will remove back() ele
    */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<string> CurRingVec;
        queue<string> NextRingVec;
        int idist = 1;
        unordered_set<string>::iterator itorend = dict.end();
    
    	CurRingVec.push(start);
        
    	while(!CurRingVec.empty()) {
    		string strSrch = CurRingVec.front();
    		int len = strSrch.length();
    		string strmorph;
    		for (int i=0; i<len; i++) {
                strmorph = strSrch;
    			for (char ch='a'; ch <= 'z'; ch++) {
    				strmorph[i] = ch;
    				if ( strmorph==end )
    					return idist+1;
    				if (strmorph !=strSrch && dict.find(strmorph)!=itorend){
    					NextRingVec.push(strmorph);
                        dict.erase(strmorph);
    				}
    			}
    		}
    		
    		CurRingVec.pop();
    		if (CurRingVec.empty() && (!NextRingVec.empty())) {
    			idist++;
                queue<string> tmp;
                tmp = CurRingVec;
                CurRingVec = NextRingVec;
                NextRingVec = tmp;
    		}
    	}//out of while
        return 0;
    }
};
