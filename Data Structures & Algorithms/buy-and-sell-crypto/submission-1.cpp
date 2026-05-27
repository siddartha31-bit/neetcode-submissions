class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int maxP = 0;

        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                maxP = max(maxP, prices[right] - prices[left]);
            } else {
                left = right;
            }
            right++;
        }
        return maxP;
    }
};
