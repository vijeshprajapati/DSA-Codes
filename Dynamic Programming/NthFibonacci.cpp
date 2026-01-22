#include<bits/stdc++.h>
using namespace std;
/*
----------Recursive Solution-----------
TC ----> O(2^n)
SC ----> Auxiliary Space O(n)
*/
int fibRecursive(int n){
    if(n == 0 || n == 1) 
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

/*
----------Recursive Memoized Solution-----------
----------------Top Down DP---------------------
TC ----> O(n)
SC ----> Memo Table O(n)
*/
int fibWithMemo(int n, vector<int> &memo){
    if(n == 0 || n == 1) 
        return n;
    if(memo[n] != -1) 
        return memo[n];

    return memo[n] = fibWithMemo(n - 1, memo) + fibWithMemo(n - 2, memo);
}


int main(){
    int n = 5;

    // cout<<fibRecursive(n);
    // vector<int> memo(n + 1, -1);
    // cout<<fibWithMemo(n, memo);

/*
----------Tabulation Solution-------------------
---------------Bottom Up DP---------------------
TC ----> O(n) Loop from 2 -> n
SC ----> Dp Table O(n)


    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout<<dp[n];
------------------------------------------------
*/

/*
----------Tabulation Solution(Space Optimised)-------------------
---------------Bottom Up DP---------------------
TC ----> O(n) Loop from 2 -> n
SC ----> O(1)
*/

    int curr = 0;

    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2; i <= n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout<<prev1;


    return 0;
}