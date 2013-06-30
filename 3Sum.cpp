class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if (num.empty() || num.size() < 3)
			return res;

		sort(num.begin(), num.end());

		for (int i=0; i<num.size()-2; i++)
		{
			int j, k;
			j = i+1;
			k = num.size()-1;
			

			while (j<k)
			{
				if (num[i]+num[j]+num[k] > 0)
					k--;
				else if (num[i]+num[j]+num[k] < 0)
					j++;
				else
				{
					vector<int> temp(3);
					temp[0] = num[i];
					temp[1] = num[j];
					temp[2] = num[k];
					sort(temp.begin(), temp.end());
					res.push_back(temp);
					j++;
					k--;
				}
			}
		}// end for
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
    }
};
