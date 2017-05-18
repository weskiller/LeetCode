//https://leetcode.com/problems/01-matrix
class Solution {
private:
    int MAX = 0x0FFFFFFF;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
	int height = matrix.size(),width = matrix[0].size();
	int thelt0 = MAX;
	vector<vector<int>> result{height,vector<int>(width,0)};
        for(int i = 0;i < matrix.size();i++) {
            for(int j = 0;j < matrix[i].size();j++) {
                if (matrix[i][j] == 0 && i + j < thelt0)
                    thelt0 = i + j;
                if (i == 0 && j  == 0) {
                    result[i][j] = matrix[i][j];
                continue;
        		}
        		int left = MAX,up = MAX;
        		if(j>0) left = result[i][j-1];
                if (i>0) up = result[i-1][j];
                int min = left < up?left + 1:up + 1;
                result[i][j] = matrix[i][j]?min:0;
            }
        }
        for(int i = height - 1;i >= 0;i--) {
            for (int j = width - 1;j >= 0; j--) {
                if (i == height - 1 && j == width - 1) {
		        result[i][j] = matrix[i][j]?result[i][j]:matrix[i][j];
                    continue;
        		}
        		int right = MAX,down = MAX;
                if (width - j > 1) right = result[i][j+1];
                if (height - i > 1) down = result[i+1][j];
                int min = right<down?right + 1:down + 1;
                result[i][j] = result[i][j]<min?result[i][j]:min;
                if (thelt0 > i + j && matrix[i][j] == 1 && result[i][j] < min)
                        result[i][j] = min;
            }
        }
        return result;
    }
};