****Partition Equal Subset Sum****

Problem Link : https://leetcode.com/problems/partition-equal-subset-sum/description/

**Recursive & Memoised Code**

TC : O(n * target)

SC : O(n * target) + O(n)

```c++
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool solve(vector<int> &arr, int target, int n, vector<vector<int>> &memo){
    if(target == 0) return true;
    if(n == 0){
        return arr[0] == target;
    }
    if(memo[n][target] != -1) return memo[n][target];
    int take = 0;
    if(arr[n] <= target){
        take = solve(arr, target - arr[n], n - 1, memo);
    }
    int notTake = solve(arr, target, n - 1, memo);
    return memo[n][target] = take || notTake;
}

int main()
{
    vector<int> arr = {1,5,11,5};
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int target = sum / 2;
    vector<vector<int>> memo(n, vector<int>(target + 1, -1));
    if(sum % 2 == 0)
        cout<<solve(arr, target, n - 1, memo);
    else
        cout<<false;
    return 0;
}
```

**Tabulation Approach**

TC : O(n * target)

SC : O(n * target),  Recursion stack space is eliminated

```c++
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> arr = {1,5,11,5};
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    
    if(sum % 2 != 0){
        cout<<false;
        return 0;
    }
    
    int target = sum / 2;
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }
    if (arr[0] <= target) {
        dp[0][arr[0]] = true;
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= target; j++){
            bool take = false;
            if(arr[i] <= j){
                take = dp[i - 1][j - arr[i]];
            }
            bool notTake = dp[i - 1][j];
            dp[i][j] = take || notTake;
        }
    }

    cout<<dp[n - 1][target];
    return 0;
}
```

**Tabulation & Space Optimised Approach**

TC : O(n * target)

SC : O(target) , Only two arrays used for calculation

```c++
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,5};
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    
    if(sum % 2 != 0){
        cout<<false;
        return 0;
    }
    
    int target = sum / 2;
    vector<bool> prev(target + 1, false);
    
    prev[0] = true;
    
    if (arr[0] <= target) {
        prev[arr[0]] = true;
    }
    for(int i = 1; i < n; i++){
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for(int j = 1; j <= target; j++){
            bool take = false;
            if(arr[i] <= j){
                take = prev[j - arr[i]];
            }
            bool notTake = prev[j];
            curr[j] = take || notTake;
        }
        prev = curr;
    }
    cout<<prev[target];
    return 0;
}
```