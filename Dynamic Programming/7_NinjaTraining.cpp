/*
Gfg link : https://www.geeksforgeeks.org/dsa/maximizing-merit-points-in-training-program/
Problem statement: 
Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D matrix mat[][], where mat[i][0], mat[i][1], and mat[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .
*/

#include <iostream>
#include <vector>
using namespace std;
//---------------------------------------
// Recursive & Memoised solution
/*
Time Complexity: O(n × 4 × 3) = O(n)
There are n days and 4 possible values for last (0, 1, 2, 3).
For each state, we loop through 3 possible activities.

Space Complexity: O(n × 4) + O(n) for recursion stack
O(n × 4) for the DP table
O(n) for recursion call stack in the worst case
*/
int solve(vector<vector<int>> &arr, int n, int last, vector<vector<int>> &memo){
    if(n == 0){
        int maxi = INT_MIN;
        for(int i = 0; i < 3; i++){
            if(i != last){
                maxi = max(maxi, arr[n][i]);
            }
        }
        return maxi;
    }
    if(memo[n][last] != -1) return memo[n][last];
    int maxi = INT_MIN;
    for(int i = 0; i < 3; i++){
        if(i != last){
            maxi = max(maxi, arr[n][i] + solve(arr, n - 1, i, memo));
        }
    }
    return memo[n][last] = maxi;
}
//-----------------------------------

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };
    int n = arr.size();
    //last 0 -> Running, 1-> Fighting, 2-> Learning, 3-> no activity
    // Initially keeping last as 3
    int last = 3;
    vector<vector<int>> memo(n, vector<int>(4, -1));
    cout<<solve(arr, n - 1, last, memo);
    // -----------------------------------------




    // --------Tabulation approach--------------
    /*
    Time Complexity: O(n × 4 × 3) = O(n)
    For each day, we loop through 4 values of last and 3 values of task.
    
    Space Complexity: O(n × 4)
    DP table of size n × 4 is maintained to store intermediate results.
    */
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(max(arr[0][0], arr[0][1]), arr[0][2]);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 4; j++){
            dp[i][j] = INT_MIN;
            for(int task = 0; task < 3; task++){
                if(task != j){
                    dp[i][j] = max(dp[i][j], arr[i][task] + dp[i - 1][task]);
                }
            }
        }
    }
    cout<<dp[n - 1][3];
    // --------------------------------------------------------




    // -- Tabulation + space optimised--
    /*
    Time Complexity: O(n × 4 × 3) = O(n)
    For each day (n), we loop through 4 values of last and for each last, try 3 task options.

    Space Complexity: O(4) = O(1)
    Only two arrays of size 4 are used (prev and temp), making it constant space.
    */
    vector<int> dp(4, -1);
    dp[0] = max(arr[0][1], arr[0][2]);
    dp[1] = max(arr[0][0], arr[0][2]);
    dp[2] = max(arr[0][0], arr[0][1]);
    dp[3] = max(max(arr[0][0], arr[0][1]), arr[0][2]);

    for(int i = 1; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < 4; j++){
            temp[j] = INT_MIN;
            for(int task = 0; task < 3; task++){
                if(task != j){
                    temp[j] = max(temp[j], arr[i][task] + dp[task]);
                }
            }
        }
        dp = temp;
    }
    cout<<dp[3];
    //---------------------------------------------------------

    return 0;
}