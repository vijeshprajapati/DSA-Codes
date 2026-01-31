****Minimum/Maximum Falling Path Sum (DP-12)****

Problem Statement 

Given a 2D array called matrix consisting of integer values return the maximum path sum that can be obtained by starting at any cell in the first row and ending at any cell in the last row.

Movement is allowed only to the bottom, bottom-right, or bottom-left cell of the current cell.

**Recursive & Memoised code**

Time Complexity: O(N*M), we call our recursive function for every element in the grid.
Space Complexity: O(N*M) + O(N), space used to store memo table and recursive stack space.

```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int solve(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &memo){
    if(j < 0 || j >= arr[0].size()){
        return -1e9;
    }
    if(i == 0){
        return arr[0][j];
    }
    if(memo[i][j] != -1) return memo[i][j];

    int up = arr[i][j] + solve(arr, i - 1, j, memo);
    int left = arr[i][j] + solve(arr, i - 1, j - 1, memo);
    int right = arr[i][j] + solve(arr, i - 1, j + 1, memo);
    
    return memo[i][j] = max({up, left, right});

}

int main()
{
    vector<vector<int>> arr = {
        {10, 10, 2, 0, 20, 4},
        {1, 0, 0, 30, 2, 5},
        {0, 10, 4, 0, 2, 0},
        {1, 0, 2, 20, 0, 4}
    };
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    int maxi = INT_MIN;
    for(int j = 0; j < n; j++){
        maxi = max(maxi, solve(arr, m - 1, j, memo));
    }
    cout<<maxi;

    return 0;
}
```

**Tabulation Approach**

Time Complexity: O(N*M), we call our recursive function for every element in the grid.
Space Complexity: O(N*M) , space used to store the 2D DP array.

```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    vector<vector<int>> arr = {
        {10, 10, 2, 0, 20, 4},
        {1, 0, 0, 30, 2, 5},
        {0, 10, 4, 0, 2, 0},
        {1, 0, 2, 20, 0, 4}
    };
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int j = 0; j < n; j++){
        dp[0][j] = arr[0][j];
    }
    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            int up = arr[i][j] + dp[i - 1][j];
            int left = arr[i][j];
            if(j > 0) left += dp[i - 1][j - 1];
            else left = -1e9;
            int right = arr[i][j]; 
            if(j < n - 1) right += dp[i - 1][j + 1];
            else right = -1e9;
            dp[i][j] = max({up,left, right});
        }
    }
    int maxi = -1e9;
    for(int j = 0; j < n; j++){
        maxi = max(maxi, dp[m - 1][j]);
    }
    cout<<maxi;
    return 0;
}
```

**Tabulation+ Space Optimization**

Time Complexity: O(N*M), we call our recursive function for every element in the grid.
Space Complexity: O(N) , space used to store the 2 arrays having values of current and previous rows.

```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    vector<vector<int>> arr = {
        {10, 10, 2, 0, 20, 4},
        {1, 0, 0, 30, 2, 5},
        {0, 10, 4, 0, 2, 0},
        {1, 0, 2, 20, 0, 4}
    };
    int m = arr.size();
    int n = arr[0].size();
    vector<int> prev(n, 0);
    for(int j = 0; j < n; j++){
        prev[j] = arr[0][j];
    }
    for(int i = 1; i < m; i++){
        vector<int> curr(n);
        for(int j = 0; j < n; j++){
            int up = arr[i][j] + prev[j];
            int left = arr[i][j];
            if(j > 0) left += prev[j - 1];
            else left = -1e9;
            int right = arr[i][j]; 
            if(j < n - 1) right += prev[j + 1];
            else right = -1e9;
            curr[j] = max({up,left, right});
        }
        prev = curr;
    }
    int maxi = -1e9;
    for(int j = 0; j < n; j++){
        maxi = max(maxi, prev[j]);
    }
    cout<<maxi;
    return 0;
}
```