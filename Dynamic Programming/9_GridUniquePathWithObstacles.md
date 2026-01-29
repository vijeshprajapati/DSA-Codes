****Grid Unique Paths With Obstacles****

Link : https://www.geeksforgeeks.org/dsa/unique-paths-in-a-grid-with-obstacles/

**Recursive & Memoised Code**

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. This is because we are filling up a 2D DP array of size m x n, and each cell takes constant time to compute.

Space Complexity: O((N-1)+(M-1)) + O(M*N) We are using a recursion stack space: O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and an external DP Array of size ‘M*N’.

```c++
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &memo){
    if(arr[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;

    if(memo[i][j] != -1) return memo[i][j];

    int up = 0;
    int left = 0;
    if(i > 0){
        up = solve(arr, i - 1, j, memo);
    }
    if(j > 0){
        left = solve(arr, i, j - 1, memo);
    }
    return memo[i][j] = up + left;
}

int main()
{
    vector<vector<int>> arr{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    cout<<solve(arr, m - 1, n - 1, memo);
    return 0;
}
```

**Tabulation Solution(Bottom Up DP)**

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. This is because we are filling up a 2D DP array of size m x n, and each cell takes constant time to compute.

Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. This is due to the use of a 2D DP array to store intermediate results.

```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int m = arr.size();
    int n = arr[0].size();
    
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1){
                dp[i][j] = 0;
                continue;
            }
            if(i == 0 && j == 0){ 
                dp[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if(i > 0){
                up = dp[i - 1][j];
            }
            if(j > 0){
                left = dp[i][j - 1];
            }
            dp[i][j] = up + left;
        }
    }
    cout<<dp[m - 1][n - 1];

    return 0;
}
```

**Tabulation + Space optimised DP**

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. This is because we are filling up a 2D DP array of size m x n, and each cell takes constant time to compute.

Space Complexity: O(n), where n is the number of columns in the matrix. This is due to the use of two 1D arrays to store intermediate results, instead of a full 2D DP array.


```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int m = arr.size();
    int n = arr[0].size();
    
    vector<int> prev(n, 0);

    for(int i = 0; i < m; i++){
        vector<int> curr(n);
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1){
                curr[j] = 0;
                continue;
            }
            if(i == 0 && j == 0){ 
                curr[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if(i > 0){
                up = prev[j];
            }
            if(j > 0){
                left = curr[j - 1];
            }
            curr[j] = up + left;
        }
        prev = curr;
    }
    cout<<prev[n - 1];

    return 0;
}
```
