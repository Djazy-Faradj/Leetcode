/*
Author: Djazy Faradj
Problem: 121. Best Time to Buy and Sell
Description: 
 - You are given an array prices where prices[i] is the price of a given stock on the ith day.
 - You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 - Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Note: No notes
Time Complexity: ?
Space Complexity: ?

Relevent Topics: Array, Dynamic Programming
*/

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