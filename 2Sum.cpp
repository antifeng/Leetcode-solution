class Solution {
public:
    //My first attemp is to sort the number, then I found the return value is the original index which dismiss my prev thought
    //Note: do not initilize the vector with specific size since if so the vector will be filled with n element unless you know how much ele will be set
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> res(2);
    	if (numbers.empty() || numbers.size() < 2)
			return res;
		int len = numbers.size();

		for (int j=0; j<len-1; j++)
		{
			for (int k=len-1; k>j; k--) {
				if (numbers[j]+numbers[k] == target){
					res[0] = j+1;
                    res[1] = k+1;
					return res;
				}
			}
		}
        return res;
	}
};
