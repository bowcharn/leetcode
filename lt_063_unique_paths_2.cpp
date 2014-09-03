/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique 
paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

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