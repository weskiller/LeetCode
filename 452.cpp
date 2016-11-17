//Subject: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
class Solution {
public:
    static bool pointsort(pair<int,int>& a,pair<int,int>& b)
    {
        return a.second < b.second;
    }
    int findMinArrowShots(vector<pair<int, int>>& points) 
    {
        int count = 0, shots = INT_MAX;
        sort(points.begin(),points.end(),pointsort);
        for(int i = 0;i < points.size(); i++)
        {
            if (shots != INT_MAX && points[i].first <= shots)
            {
                continue;
            }
            else
            {
                shots = points[i].second;
                count += 1;
            }
        }
        return count;
    }
};
