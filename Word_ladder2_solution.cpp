class Solution {
public:
    bool isNeighbor(string src, string dest) {
        if (src.empty() || dest.empty())
            return false;
        int len = src.length();
      int diff = 0;
    	for (int i=0; i< len; i++) {
    		if (src[i] != dest[i])
    			diff++;
    	}
    	return (diff == 1);
	}
    
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		typedef list<std::vector<string>> vecList;
		vector<string> CurRingVec;
		vector<string> NextRingVec;
		vector<vector<string>> retVec;
		vecList ladderList;
		int idist = 1;
		int maxdist = 0;
		CurRingVec.push_back(start);

		while(!CurRingVec.empty()) {
			string strSrch = CurRingVec.back();
			int len = strSrch.length();
            int refcont = 0;
			string strmorph;

			for (int i=0; i<len; i++) {
				strmorph = strSrch;
				for (char ch='a'; ch <= 'z'; ch++) {
					strmorph[i] = ch;

					//find one path
					if (strmorph == end) {
						if (maxdist==0)
							maxdist = idist;
						if (idist>maxdist && maxdist!=0)
							return retVec;
                        
                        vector<string> pathVec;
						vecList::reverse_iterator ritor = ladderList.rbegin();
                        
						while(ritor!=ladderList.rend()) {
							for (vector<string>::iterator itorStr = ritor->begin(); itorStr!=ritor->end(); itorStr++) {
								if (isNeighbor(*itorStr, strmorph)) {
									pathVec.insert(pathVec.begin(), *itorStr);
									strmorph = *itorStr;
                                    
                                    if (ritor->size()>1)
                                        ritor->erase(itorStr);
									break;
								}
							}
							ritor++;
						}//end inner while
                        pathVec.insert(pathVec.begin(), start);
                        pathVec.push_back(end);
                        retVec.push_back(pathVec);
					}

					if (strmorph !=strSrch && dict.count(strmorph)>0){
						NextRingVec.push_back(strmorph);
                        refcont++;	//dict.erase(strmorph);
					}
				}
			}    
			CurRingVec.pop_back();
        
			if (CurRingVec.empty() && (!NextRingVec.empty())) {
                if ((!ladderList.empty()) && (refcont>1)) {
                    vecList::iterator itlist = ladderList.begin();
                    itlist->push_back(string(strSrch));
                }
				idist++;
				ladderList.push_back(NextRingVec);
				vector<string> tmp;
				CurRingVec = NextRingVec;
				NextRingVec = tmp;
			}
		}//out of while
		return retVec;
	}
};
