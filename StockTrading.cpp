
class Solution1 {
public:
    //idea is to use the min to get the max diff
    //
    int maxProfit(vector<int> &prices) {
    
    int size = prices.size();
	if (prices.empty() || size==1)
		return 0;
	
	int maxProfit = 0;
	int minIdx = 0;
    
	for(int i=1; i<size; i++) {
		if (prices[minIdx]> prices[i])
			minIdx = i;
		int  curProfit = prices[i] - prices[minIdx];
		if ( curProfit > maxProfit)
			maxProfit = curProfit;
	}
	return maxProfit;
    }
};

class Solution2 {
public:
    //idea is to find the index of max and min element
    //Then divide the array into three parts.
 	//Divide and conque
int getmaxProfit(vector<int> &prices, int s, int t) {
    
    if (s >= t)
		return 0;
    int minIdx, maxIdx;
	minIdx = s;
	maxIdx = t;
    
	for(int i=s; i<=t; i++) {
		if (prices[minIdx]> prices[i])
			minIdx = i;
		else if (prices[maxIdx] < prices[i])
			maxIdx = i;
	}
	if (minIdx < maxIdx) 
		return prices[maxIdx] - prices[minIdx];
	else {
        int left = getmaxProfit(prices, s, maxIdx);
        int right = getmaxProfit(prices, minIdx, t);
        int mid = getmaxProfit(prices, maxIdx+1, minIdx-1); 
        
        return left > right ? ( mid > left ?  mid : left) : ( mid > right ?  mid : right);
	}
}

int maxProfit(vector<int> &prices) {
    
    int size = prices.size();
	if (prices.empty() || size==1)
		return 0;
	
	return getmaxProfit(prices, 0, size-1);
    }
};
