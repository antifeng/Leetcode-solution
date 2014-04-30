class Solution {
public:
    //Note: the input array is orderless, to improve 
    //the performance, we need to sort it first
    //then get two number whose sum equal to the target
    //finally get the index from the original array
    //The whole complexity is nlog(n)
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> res(2);
    	if (numbers.empty() || numbers.size() < 2)
			return res;
		
        vector<int> TmpVec(numbers);
        sort(TmpVec.begin(), TmpVec.end());
        
	for (int j=0, k=numbers.size()-1; j<k;) {
		int nSum = TmpVec[j]+TmpVec[k];
		if ( nSum < target)
			j++;
		else if ( nSum > target)
			k--;
		else {
		//get the original index of those numbers
			res[0] = TmpVec[j];
			res[1] = TmpVec[k];
			auto first = find_first_of(numbers.begin(), numbers.end(), res.begin(), res.end());
			auto second = find_first_of(first+1, numbers.end(), res.begin(), res.end());
			res[0] = 1 + first-numbers.begin();
			res[1] = 1 + second-numbers.begin();
			return res;
		}
	} //end for
        return res;
   }
};
