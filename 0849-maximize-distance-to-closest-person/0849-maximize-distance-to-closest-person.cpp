
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();

        int prev = -1;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (seats[i] == 1) {

                // First occupied seat
                if (prev == -1) {
                    ans = i;
                }
                else {
                    // Maximum distance between occupied seats
                    ans = max(ans, (i - prev) / 2);
                }

                prev = i;
            }
        }

        // Trailing empty seats
        ans = max(ans, n - 1 - prev);

        return ans;
    }
};
