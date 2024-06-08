// This programe is used to find the number of islands in a given grid via dfs.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j) {
        // skip all zeroes and useless cases
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') return;
        
        // Mark the visited land as '0'
        grid[i][j] = '0'; 

        // Explore neighbor cells in all four directions
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        // initialize m, the number of rows in the grid
        int m = grid.size();

        // initialize n, the number of columns
        int n = grid[0].size();
        
        // Initialize the count of islands to 0
        int count = 0;
        
        // Iterate through the grid
        // We increment i at the end because we want to start from the next row
        for (int i = 0; i < m; i++) {
            // We increment j at the start of the loop because we want to start from the first column
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j); // Mark the whole island as visited
                    count++; // Found a new island
                }
            }
        }
        return count;
    }

    // This function is used to test the logging for the solution to Number of Islands
    void logging(int s){
        // Logic for printing count in log
        cout << "Count: " << s << endl;
    }


};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '1'}
    };
    int count1 = solution.numIslands(grid1);
    cout << "Number of islands (Test case 1): " <<   count1 << endl;

    solution.logging(count1);

    // Test case 2
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    int count2 = solution.numIslands(grid2);
    cout << "Number of Islands (Test Case 2): " << count2 << endl;
    solution.logging(count2);

    // Test case 3
    vector<vector<char>> grid3 = {
        {'1', '1', '1', '1', '1' },
        {'1', '0', '1', '0', '0' },
        {'0', '0', '1', '1', '1' },
        };
    int count3 = solution.numIslands(grid3);
    cout << "Number of Islands (Test Case 3): " << count3 << endl;
    solution.logging(count3);
}
