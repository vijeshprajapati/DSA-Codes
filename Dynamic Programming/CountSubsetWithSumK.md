****Count subsets with sum K****

Problem Link : https://www.geeksforgeeks.org/dsa/count-of-subsets-with-sum-equal-to-x/

**Recursive & Memoised Code**

TC : O(n * target)

SC : O(n * target) + O(n)

```c++
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int solve(vector<int> &arr, int target, int n, vector<vector<int>> &memo){
    if(target == 0) return 1;
    if(n == 0){
        return arr[0] == target;
    }
    if(memo[n][target] != -1) return memo[n][target];
    int take = 0;
    if(arr[n] <= target){
        take = solve(arr, target - arr[n], n - 1, memo);
    }
    int notTake = solve(arr, target, n - 1, memo);
    return memo[n][target] = take + notTake;
}

int main(){
    vector<int> arr = {1, 1, 1, 1};
    int target = 1;
    int n = arr.size();
    vector<vector<int>> memo(n, vector<int>(target + 1, -1));
    cout<<solve(arr, target, n - 1, memo);
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

int main(){
    vector<int> arr = {1, 2, 3, 3};
    int target = 6;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= target){
        dp[0][arr[0]] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= target; j++){
            int take = 0;
            if(arr[i] <= j){
                take = dp[i - 1][j - arr[i]];
            }
            int notTake = dp[i - 1][j];
            dp[i][j] = take + notTake;
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

int main(){
    vector<int> arr = {1, 1, 1, 1};
    int target = 1;
    int n = arr.size();
    vector<int> prev(target + 1, 0);
    
    prev[0] = 1;
    
    if(arr[0] <= target){
        prev[arr[0]] = 1;
    }
    for(int i = 1; i < n; i++){
        vector<int> curr(target + 1, 0);
        curr[0] = 1;
        for(int j = 1; j <= target; j++){
            int take = 0;
            if(arr[i] <= j){
                take = prev[j - arr[i]];
            }
            int notTake = prev[j];
            curr[j] = take + notTake;
        }
        prev = curr;
    }
    cout<<prev[target];
    
    return 0;
}
```