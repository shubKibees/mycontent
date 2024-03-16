// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

#include<iostream>
#include<vector>

using namespace std;


class Solution {
    vector<vector<int>> memory;

public:
    int totalUniquePath(int m, int n, vector<vector<int>>& obstacleGrid) {
        memory[1][1] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for (int x = 2; x <= m; x++) {
            memory[x][1] = obstacleGrid[x - 1][0] == 1 ? 0 : memory[x - 1][1];
        }

        for (int y = 2; y <= n; y++) {
            memory[1][y] = obstacleGrid[0][y - 1] == 1 ? 0 : memory[1][y - 1];
        }

        for (int y = 2; y <= m; y++) {
            for (int x = 2; x <= n; x++) {
                if (obstacleGrid[y - 1][x - 1] != 1) {
                    memory[y][x] = memory[y - 1][x] + memory[y][x - 1];
                } else {
                    memory[y][x] = 0;
                }
            }
        }
        return memory[m][n];
    }

    // initialize the memory
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memory.resize(m + 1, vector<int>(n + 1, 0));
        return totalUniquePath(m, n, obstacleGrid);
    }
};