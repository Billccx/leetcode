#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    int rectangleArea(vector<vector<int>> &rectangles)
    {
        long long ans = 0;
        int len = rectangles.size();
        vector<int> height;
        vector<vector<int>> width;
        unordered_map<int, int> ump;
        for (int i = 0; i < len; i++)
        {
            if (!ump.count(rectangles[i][1]))
            {
                ump[rectangles[i][1]] = 1;
                height.push_back(rectangles[i][1]);
            }
            if (!ump.count(rectangles[i][3]))
            {
                ump[rectangles[i][3]] = 1;
                height.push_back(rectangles[i][3]);
            }
        }

        sort(height.begin(), height.end());

        for (int i = 0; i < len; i++)
        {
            vector<int> temp = {rectangles[i][0], i, 1};
            vector<int> temp2 = {rectangles[i][2], i, -1};
            width.push_back(temp);
            width.push_back(temp2);
        }
        sort(width.begin(), width.end(), cmp);

        vector<int> height_count(height.size() - 1);
        cout<<width.size()<<endl<<endl;
        for (int i = 0; i < width.size(); )
        {
            int r = i;
            while (r < width.size() && width[i][0] == width[r][0])
            {
                r++;
            }
            if (r == width.size())
                break;

            for (int t = i; t < r; t++){
                int low = rectangles[width[t][1]][1];
                int high = rectangles[width[t][1]][3];
                int change = width[t][2];
                for (int j = 0; j < height.size() - 1; j++){
                    if (height[j] >= low && height[j] < high){
                        height_count[j] += change;
                    }
                }
            }

            long long temp=0;
            for (int j = 0; j < height_count.size(); j++){
                if (height_count[j] > 0){
                    cout << "j+1:" << height[j + 1] << " j:" << height[j] << endl;
                    cout << "i+1:" << width[r][0] << " i:" << width[i][0] << endl;
                    cout << (long long int)(height[j + 1] - height[j]) * (long long int)(width[r][0] - width[i][0])<<endl;
                    temp += (long long int)(height[j + 1] - height[j]);
                }
            }
            //cout << ans << endl;
            ans += temp * (long long int)(width[r][0] - width[i][0]);
            i = r;
            cout<<"i="<<width[i][0]<<endl<<endl<<endl;
        }

        return ans % static_cast<long long int>(1e9 + 7);
    }
};

int main()
{
    vector<vector<int>> v = {{0,0,2,2},{1,0,2,3},{1,0,3,1}};
    Solution s;
    int ans = s.rectangleArea(v);
    cout << ans << endl;
}