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