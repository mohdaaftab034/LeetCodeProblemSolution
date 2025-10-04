// LeetCode Link - "https://leetcode.com/problems/buy-two-chocolates/description"



// Approach - 1

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        sort(prices.begin(), prices.end());

        if(money >= (prices[0] + prices[1])) {
            return money - (prices[0] + prices[1]);
        }

        return money;
    }
};


// Approach - 2

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();

        int smallest = INT_MAX;
        int sec_smallest = INT_MAX;

        for(int price : prices) {
            
            if(price < smallest) {
                sec_smallest = smallest;
                smallest = price;
            } else {
                sec_smallest = min(sec_smallest, price);
            }
        }

        if((smallest + sec_smallest) > money){
            return money;
        }

        return money - (smallest + sec_smallest);
        
    }
};
