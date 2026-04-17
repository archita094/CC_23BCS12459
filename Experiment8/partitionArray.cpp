class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int maxSum = INT_MIN;
            int mx = INT_MIN;
            
            for (int j = i; j <min(n, i + k); j++) {
                mx =max(mx, arr[j]);             
                int sum = (mx * (j - i + 1)) + dp[j + 1];
                maxSum=max(sum,maxSum);
            }
            dp[i] = maxSum;
        }

        return dp[0];
    }
};