****Grid Unique Paths****
Link : https://www.geeksforgeeks.org/dsa/count-possible-paths-top-left-bottom-right-nxm-matrix/

**Recursive & Memoised Code**

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. This is because we are filling up a 2D DP array of size m x n, and each cell takes constant time to compute.

Space Complexity: O(m * n), due to the storage of the DP array which keeps track of the number of unique paths to each cell in the grid.
````
#include <iostream>
#include <vector>
using namespace std;

int solve(int m, int n, vector<vector<int>> memo){
    if(m == 0 && n == 0)
        return 1;
    if(memo[m][n] != -1) return memo[m][n];
    int up = 0;
    int left = 0;
    if(m > 0){
        up = solve(m - 1, n, memo);
    }
    if(n > 0){
        left = solve(m, n - 1, memo);
    }
    return memo[m][n] = up + left;
}

int main()
{
    int m = 3, n = 3;
    vector<vector<int>> memo(m, vector<int>(n, -1));
    cout<<solve(m - 1, n - 1, memo);
    return 0;
}
````

**Tabulation Solution(Bottom Up DP)**

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. This is because we are filling up a 2D DP array of size m x n, and each cell takes constant time to compute.

Space Complexity: O(m * n), as we are using a 2D array to store the results of subproblems. However, we can optimize this to O(n) by using a 1D array and updating it in place.
````
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m = 3, n = 3;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) 
                continue;
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
    cout<<dp[m - 1][n -1];

    return 0;
}
````

**Tabulation + Space optimised DP**

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. This is because we are iterating through each cell in the grid once.

Space Complexity: O(n), as we are using two arrays of size n to store the current and previous rows. This is an optimization from the previous approaches that used a 2D array.

````
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m = 3, n = 3;
    vector<int> prev(n, 1);
    for(int i = 1; i < m; i++){
        vector<int> curr(n);
        for(int j = 0; j < n; j++){
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
````
