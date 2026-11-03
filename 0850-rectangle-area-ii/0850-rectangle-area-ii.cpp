class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        // Collect all unique x-coordinates
        vector<long long> x;
        for (auto& rect : rectangles) {
            x.push_back(rect[0]);
            x.push_back(rect[2]);
        }
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());

        long long totalArea = 0;
        long long MOD = 1e9 + 7;

        for (size_t i = 0; i < x.size() - 1; ++i) {
            long long x1 = x[i], x2 = x[i + 1];
            long long width = x2 - x1;
            if (width == 0) continue;

            // Find all vertical intervals [y1, y2] overlapping with the current horizontal interval [x1, x2]
            vector<pair<long long, long long>> intervals;
            for (auto& rect : rectangles) {
                if (rect[0] <= x1 && rect[2] >= x2) {
                    intervals.push_back({rect[1], rect[3]});
                }
            }

            if (intervals.empty()) continue;

            // Merge intervals to calculate total height
            sort(intervals.begin(), intervals.end());
            long long totalHeight = 0;
            long long currY1 = intervals[0].first;
            long long currY2 = intervals[0].second;

            for (size_t j = 1; j < intervals.size(); ++j) {
                if (intervals[j].first < currY2) {
                    currY2 = max(currY2, intervals[j].second);
                } else {
                    totalHeight += currY2 - currY1;
                    currY1 = intervals[j].first;
                    currY2 = intervals[j].second;
                }
            }
            totalHeight += currY2 - currY1;

            totalArea = (totalArea + width * totalHeight) % MOD;
        }

        return totalArea;
    }
};