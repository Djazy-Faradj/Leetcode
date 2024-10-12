class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyIndex;
        int sellIndex;
        int profit = 0;
        bool firstPass = true;
    
        for (int i = 0; i < prices.size()-1; i++)
        {   
            if (prices[i+1]-prices[i] > 0)
            {
                if (firstPass == true)
                {
                    buyIndex = i;
                    sellIndex = i+1;
                    firstPass = false;
                }
                if (prices[i+1] > prices[sellIndex]) sellIndex = i+1;
                if (prices[i] < prices[buyIndex])
                {
                    for (int j = i+1; j < prices.size(); j++)
                    {
                        if (prices[j]-prices[i] > profit)
                        {
                            sellIndex = j;
                            buyIndex = i;
                            profit = prices[sellIndex]-prices[buyIndex];
                        }
                    }
                }
                profit = prices[sellIndex]-prices[buyIndex];
            }
        }
        return profit;
    }
};