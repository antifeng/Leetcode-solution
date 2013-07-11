class Solution {
public:

/**
 * f(n) = number of ways you can climb to the nth step.
 *To reach to the nth step, you have only two choices:
 * (1)Advance one step from the n-1th step.
 * (2)Advance two steps from the n-2th step.
 *   Therefore, f(n) = f(n-1) + f(n-2), which is the 
 * exact same recurrence formula defined by the 
 * Fibonacci sequence (with different base cases, though).
 * using DP to solve it
*/
    int climbStairs(int n) {
        int* dp = new int[n+1];
    	
		dp[0] = 1;
		dp[1]= 1;
		
		for (int k=2; k <= n; k++)
			dp[k] = dp[k-1] + dp[k-2];
		return dp[n];
    }
};
