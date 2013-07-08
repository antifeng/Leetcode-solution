#include <vector>
#include <map>
#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

class Solution {
public:
    bool isNeighbor(string src, string dest) {
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
        unordered_set<string>::iterator itend = dict.end();
		vecList ladderList;
		int idist = 1;
		int maxdist = 0;
        int pathcont = 0;
        bool isContinue = true;
		CurRingVec.push_back(start);
        
		while(!CurRingVec.empty() && isContinue) {
			string strSrch = CurRingVec.back();
			int len = strSrch.length();
			int refcont = 0;
			string strmorph;

			for (int i=0; i<len ; i++) {
				strmorph = strSrch;
				for (char ch='a'; ch <= 'z'; ch++) {
					strmorph[i] = ch;

					//find one path
					if (strmorph == end) {
						if (maxdist==0)
							maxdist = idist;
						else if (idist>maxdist && maxdist!=0){
    					    isContinue = false;////
                            break;
						}
                        pathcont++;
					}
					else if (strmorph !=strSrch && (dict.find(strmorph)!=itend ) && isNeighbor(strSrch, strmorph)){
						NextRingVec.push_back(string(strmorph));
						refcont++;
                        //
					}
				}
			}    
			CurRingVec.pop_back();
            //dict.erase(strSrch);
			if (CurRingVec.empty() && (!NextRingVec.empty()) && (maxdist != idist)) {
				if ((!ladderList.empty()) && (refcont>1)) {
					vecList::iterator itlist = ladderList.begin();
					itlist->push_back(string(strSrch));
				}
				idist++;
				ladderList.push_back(NextRingVec);
                for (vector<string>::iterator itorStr = NextRingVec.begin(); itorStr!=NextRingVec.end(); itorStr++) 
                    dict.erase(*itorStr);
                    
				vector<string> tmp;
				CurRingVec = NextRingVec;
				NextRingVec = tmp;
			}
		}//out of while
        
        for (int i=0; i<pathcont; i++) {
            vector<string> pathVec;
            string strPath = end;
        	vecList::reverse_iterator ritor = ladderList.rbegin();
    
            while(ritor!=ladderList.rend()) {
                for (vector<string>::iterator itorStr = ritor->begin(); itorStr!=ritor->end(); itorStr++) {
            		if (isNeighbor(*itorStr, strPath)) {
            			pathVec.insert(pathVec.begin(), *itorStr);
            			strPath = *itorStr;
            			ritor->erase(itorStr);
            			break;
            		}
            	}
            	ritor++;
            }//end inner while
            pathVec.insert(pathVec.begin(), start);
            pathVec.push_back(end);
            retVec.push_back(pathVec);
            pathVec.clear();
        }
		return retVec;
	}
};
