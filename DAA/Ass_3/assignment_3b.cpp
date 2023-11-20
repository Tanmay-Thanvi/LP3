// 0-1 KnapSack Problem 

#include<iostream>
using namespace std;

int main(){
    int capacity = 8;
    int items = 4;
    int price[5] = {0, 1, 2, 5, 6}; // items + 1
    int wt[5] = {0, 2, 3, 4, 5}; // items + 1
    int dp[items + 1][capacity + 1];

    // Tabulation Method 
    for(int i = 0; i <= items; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0){
                //There's nothing to add to Knapsack
                dp[i][j] = 0;
            }
            else if(wt[i] <= j){
                //Choose previously maximum or value of current item + value of remaining weight
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            }
            else{
                //Add previously added item to knapsack
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
	

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
    return 0;
}

/*
    0/1 Knapsack :
    Time Complexity: O(N*W). 
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W). 
    The use of 2-D array of size ‘N*W’.
*/