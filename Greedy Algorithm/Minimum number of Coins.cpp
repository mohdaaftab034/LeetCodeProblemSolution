// GFG Link - https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1


// Solution --->
class Solution {
  public:
    int findMin(int n) {
        
        
        int currency[] = {10, 5, 2, 1};
        int i = 0;
        int notes = 0;
        int count = 0;
        
        while(n) {
            notes = n / currency[i];
            
            while(notes--) {
                count++;
            }
            
            n %= currency[i];
            i++;
        }
        
        return count;
    }
};
