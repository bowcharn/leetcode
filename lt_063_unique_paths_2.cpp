#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if(obstacleGrid[0][0] == 1)
			return 0;
		vector<int> paths(n+1, 0);
		paths[1] = 1;
		
		for(int i = 0; i < m; i++)
			for(int j = 1; j <= n; j++){
				if(obstacleGrid[i][j-1] == 0)
					paths[j] += paths[j-1];
				else
					paths[j] = 0;
			}

		return paths[n];
    }
};

int main()
{
	vector<vector<int> > obstacleGrid = {
										{0, 0, 0, 0},
										{0, 1, 0, 0},
										{0, 0, 0, 0},
										{0, 0, 1, 0},
										{0, 0, 0, 0}
										};
	std::cout<<Solution().uniquePathsWithObstacles(obstacleGrid)<<std::endl;
	return 0;
}