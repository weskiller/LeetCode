//https://leetcode.com/problems/perfect-rectangle
class Solution {
private:
    struct point {
        int x;
        int y;
        point(int X = 0,int Y = 0) :x(X),y(Y) {}
        bool operator<(const point & p) const {
            if( p.x + p.y > x + y)
                return true;
            else if (p.x + p.y < x + y)
                return false;
            else {
                if (p.x > x)
                    return true;
                else
                    return false;
            }
        }
        bool operator==(const point &p) const { return p.x == x && p.y == y; }
    };
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<point,int> c;
        point botom_left(rectangles[0][0],rectangles[0][1]),top_right(rectangles[0][2],rectangles[0][3]);
        int area = 0;
        for (vector<int> & x : rectangles ) {
            c[point(x[0],x[1])]++;
            c[point(x[2],x[3])]++;
            c[point(x[0],x[3])]++;
            c[point(x[2],x[1])]++;
            if (x[0] + x[1] < botom_left.x + botom_left.y ) {
                botom_left.x = x[0];
                botom_left.y = x[1];
            }
            if (x[2] + x[3] > top_right.x + top_right.y) {
                top_right.x = x[2];
                top_right.y = x[3];
            }
            area += (x[2] - x[0]) * (x[3] - x[1]);
        }
        int count=0;
        vector<point> vertex;
        for (auto x : c) {
            if (x.second == 1) {
                count++;
                vertex.push_back(x.first);
            }
            else if (x.second % 2 != 0)
                return false;
        }
        if (count != 4 )
            return false;
        if ((top_right.y - botom_left.y) * (top_right.x - botom_left.x) == area && botom_left == vertex[0] && top_right == vertex[3])
            return true;
        return false;
    }
};