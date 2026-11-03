class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        int a = (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
        int b = (p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]);
        int c = (p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1]);
        int d = (p3[0]-p2[0])*(p3[0]-p2[0]) + (p3[1]-p2[1])*(p3[1]-p2[1]);
        int e = (p4[0]-p2[0])*(p4[0]-p2[0]) + (p4[1]-p2[1])*(p4[1]-p2[1]);
        int f = (p4[0]-p3[0])*(p4[0]-p3[0]) + (p4[1]-p3[1])*(p4[1]-p3[1]);

        vector<int> len = {a,b,c,d,e,f};
        sort(len.begin(), len.end());

        if(len[0]!=0 && len[0]==len[1] && len[1]==len[2] && len[2]==len[3] && len[4]==len[5]) {
            if(len[5] == 2*len[0]) {
                return true;
            }
        }
        // for()
        return false;
    }
};