class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec = [x1, y1, x2, y2]
        // Check if one rectangle is to the left, right, above, or below the other
        return !(rec1[2] <= rec2[0] || // rec1 is to the left of rec2
                 rec1[0] >= rec2[2] || // rec1 is to the right of rec2
                 rec1[3] <= rec2[1] || // rec1 is below rec2
                 rec1[1] >= rec2[3]);   // rec1 is above rec2
    }
};