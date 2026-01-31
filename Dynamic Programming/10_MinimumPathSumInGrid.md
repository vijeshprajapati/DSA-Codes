****Minimum Path sum in Grid****

Problem Statement: Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.


**Recursive & Memoised Code**

Time Complexity: O(N*M), at max, there will be N*M calls of recursion..
Space Complexity: O(M+N) + O(N*M), additional space for recursion stack and memo table.


```c++
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &memo){
    if(i == 0 && j == 0){
        return arr[0][0];
    }
    if(memo[i][j] != -1) return memo[i][j];
    int up = 1e9;
    int left = 1e9;
    if(i > 0){
        up = arr[i][j] + solve(arr, i - 1, j, memo);
    }
    if(j > 0){
        left = arr[i][j] + solve(arr, i, j - 1, memo);
    }
    return memo[i][j] = min(up, left);
}

int main()
{
    vector<vector<int>> arr{
        {5, 9, 6},
        {11, 5, 2}
    };
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    cout<<solve(arr, m - 1, n - 1, memo);
}
```

**Tabulation Solution(Bottom Up DP)**

Time Complexity: O(N*M), entire grid is visited atleast once.
Space Complexity: O(N*M), space used for DP array.

```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr{
        {5, 9, 6},
        {11, 5, 2}
    };
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = arr[0][0];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                continue;
            }
            int up = 1e9;
            int left = 1e9;
            if(i > 0){
                up = arr[i][j] + dp[i - 1][j];
            }
            if(j > 0){
                left = arr[i][j] + dp[i][j - 1];
            }
            dp[i][j] = min(up, left);
        }
    }
    cout<<dp[m - 1][n - 1];
}
```

**Tabulation + Space optimised DP**
Time Complexity: O(N*M), every element of grid is visited atleast once.
Space Complexity: O(N), we only use one array for storing rows.



```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr{
        {5, 9, 6},
        {11, 5, 2}
    };
    int m = arr.size();
    int n = arr[0].size();
    vector<int> prev(n, -1);
    prev[0] = arr[0][0];
    for(int j = 1; j < n ; j++){
        prev[j] = prev[j - 1] + arr[0][j];
    }
    for(int i = 1; i < m; i++){
        vector<int> curr(n);
        for(int j = 0; j < n; j++){
            int up = 1e9;
            int left = 1e9;
            if(i > 0){
                up = arr[i][j] + prev[j];
            }
            if(j > 0){
                left = arr[i][j] + curr[j - 1];
            }
            curr[j] = min(up, left);
        }
        prev = curr;
    }
    cout<<prev[n - 1];
}
```
