class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int cnt = 0;
        
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> ump;
            for (int j = 0; j < points.size(); j++) {
                int dis = getDis(points[i][0], points[i][1], points[j][0], points[j][1]);
                ump[dis]++;
            }
            for (auto it = ump.begin(); it != ump.end(); it++) {
                cnt += it->second * (it->second - 1);
            }
        }

        

        return cnt;
    }

    int getDis(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
};