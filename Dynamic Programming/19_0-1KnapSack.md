****0-1 KNAPSACK****

Problem Link : https://www.geeksforgeeks.org/dsa/0-1-knapsack-problem-dp-10/

**Recursive & Memoised Code**

TC : O(2^n)

SC : O(n)

```c++
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &profit, vector<int> &weight, int W, int n, vector<vector<int>> &memo){
    if(n == 0){
        if(W - weight[0] >= 0) return profit[0];
        return 0;
    }
    if(memo[n][W] != -1) return memo[n][W];
    int take = 0;
    int notTake = 0;
    if(W- weight[n] >= 0){
        take = profit[n] + solve(profit, weight, W - weight[n], n - 1, memo);
    }
    notTake = solve(profit, weight, W, n - 1, memo);
    return memo[n][W] = max(take, notTake);
}

int main()
{
    vector<int> profit = {1, 2, 3};
    vector<int> weight = {4, 5, 6};
    int W = 3;
    int n = profit.size();
    vector<vector<int>> memo(n, vector<int>(W + 1, -1));
    
    cout<<solve(profit, weight, W, n - 1, memo);

    return 0;
}
```

**Tabulation Approach**

TC : N * W

SC : O(N * W) stack space is eliminated

```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> profit = {1, 2, 3};
    vector<int> weight = {4, 5, 1};
    int W = 4;
    int n = profit.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    
    for(int j = 0; j <= W; j++){
        if(j - weight[0] >= 0){
            dp[0][j] = profit[0];
        }
        else{
            dp[0][j] = 0;
        }
    }
    
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= W; j++){
            int take = -1e9;
            int notTake = 0;
            if(j - weight[i] >= 0){
                take = profit[i] + dp[i - 1][j - weight[i]];
            }
            notTake = dp[i - 1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    cout<<dp[n - 1][W];

    return 0;
}
```

**Tabulation & Space Optimised Approach**

TC : O(N * W)

SC : O(W) external array of size 'W + 1' used

```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> profit = {1, 2, 3};
    vector<int> weight = {4, 5, 6};
    int W = 4;
    int n = profit.size();
    vector<int> prev(W + 1, -1);
    vector<int> curr(W + 1, -1);
    
    for(int j = 0; j <= W; j++){
        if(j - weight[0] >= 0){
            prev[j] = profit[0];
        }
        else{
            prev[j] = 0;
        }
    }
    
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= W; j++){
            int take = -1e9;
            int notTake = 0;
            if(j - weight[i] >= 0){
                take = profit[i] + prev[j - weight[i]];
            }
            notTake = prev[j];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    cout<<prev[W];

    return 0;
}
```