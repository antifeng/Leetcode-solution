class Solution {
public:
    const int Max_bit = 34;
    
    /**
     * The idea is to decompsite n into seq of pow of 2
     * Be careful when x==0, x==1, Overflow
     * 
     */
    
	double pow(double x, int n) {
		double ret = 1;
		int d = ( n>0 ) ? n : -n;

		if (n==0.0 || x==1.0)
			return 1;
		else if (x==-1.0)
			return ((d%2)==0) ? 1 : -1 ;

		int idx = 2;
		double midRet[Max_bit];
		int times[Max_bit];
		midRet[0] = 1;
		midRet[1] = x;
		times[0] = 0;
		times[1] = 1;
		for(int i=2; i<d; i=i*2) {
			times[idx] = i;
			midRet[idx] =  midRet[idx-1] * midRet[idx-1];
			if ( midRet[idx]<0.000001f)  //handle the neg overflow
				return 0;
			idx++;
		}

		int left = d - times[idx-1];
		ret = midRet[idx-1];
		int k = idx - 1;
		while (left>0) {
			while(times[k] > left)
				k--;
			left = left - times[k];
			ret = ret * midRet[k];
		}

		if (n<0)
			ret = 1.0/ret;
		return ret;
	}
};
