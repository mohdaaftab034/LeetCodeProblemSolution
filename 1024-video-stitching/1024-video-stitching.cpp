class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // Sort clips primarily by start time, and secondarily by end time
        sort(clips.begin(), clips.end());
        
        int count = 0;
        int i = 0;
        int n = clips.size();
        int currEnd = 0;
        int nextEnd = 0;
        
        while (i < n && clips[i][0] <= currEnd) {
            // Find the furthest reaching clip among those that start within our current reachable range
            while (i < n && clips[i][0] <= currEnd) {
                nextEnd = max(nextEnd, clips[i][1]);
                i++;
            }
            
            // We picked a clip, increment our count
            count++;
            currEnd = nextEnd;
            
            // If our current reach covers or exceeds the target time, we are done
            if (currEnd >= time) {
                return count;
            }
        }
        
        return -1; // If we cannot reach the target time
    }
};