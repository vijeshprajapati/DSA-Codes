****Subset sum problem****

Problem Link : https://www.geeksforgeeks.org/dsa/subset-sum-problem-dp-25/

**Recursive & Memoised Code**

TC : O(n * target)

SC : O(n * target) + O(n)

```c++
#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int> &arr, int target, int n, vector<vector<int>> &memo){
    if(target == 0){
        return true;
    }
    if(n == 0){
        if(arr[0] == target) return true;
        return false;
    }
    if(memo[n][target] != -1) return memo[n][target];
    bool notTaken = solve(arr, target, n - 1, memo);
    bool taken = false;
    if(arr[n] <= target){
        taken = solve(arr, target - arr[n], n - 1, memo);
    }
    return memo[n][target] = taken || notTaken;
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 30;
    int n = arr.size();
    
    vector<vector<int>> memo(n, vector<int>(target + 1, -1));
    
    cout<<solve(arr, target, n - 1, memo);

    return 0;
}
```

**Tabulation Approach**

TC : 

SC : 

```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 30;
    int n = arr.size();
    
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }
    for(int j = 0; j <= target; j++){
        dp[0][j] = (arr[0] == j);
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= target; j++){
            bool notTaken = dp[i - 1][j];
            bool taken = false;
            if(arr[i] <= j){
                taken = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = taken || notTaken;
        }
    }
    cout<<dp[n - 1][target];
    return 0;
}
```

**Tabulation & Space Optimised Approach**

TC :

SC : 

```c++

```