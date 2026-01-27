/*
Gfg link : https://www.geeksforgeeks.org/dsa/count-ways-reach-nth-stair/
Problem Statement: 
There are n stairs, and a person standing at the bottom wants to climb stairs to reach the top. 
The person can climb either 1 stair or 2 stairs at a time, the task is to count the number of 
ways that a person can reach at the top.

--------------------------------------------------------
Only recursive approach is written here
Check the Nth Fibonacci question for all the Dp approaches

*/

#include <iostream>
using namespace std;

int noOfWaysRecursive(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return noOfWaysRecursive(n - 1) + noOfWaysRecursive(n - 2);
}

int main()
{
    int n = 4;
    cout<<noOfWaysRecursive(n);
    return 0;
}