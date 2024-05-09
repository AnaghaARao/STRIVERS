/* 
    Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
    Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
    Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
*/

#include<bits/stdc++.h>
using namespace std;

// Approach for variation 1:
// First, we will consider r-1 as n and c-1 as r.
// After that, we will simply calculate the value of the combination using a loop. 
// The loop will run from 0 to r. And in each iteration, we will multiply (n-i) with the result and divide the result by (i+1).
// Finally, the calculated value of the combination will be our answer.

long long nCr(int n, int r){
    // we need to find (row-1)C(col-1)
    long long ans = 1;
    for(int i = 0 ; i < r ; i++){
        ans = ans*(n-i);
        ans = ans/(i+1);
    }
    return ans;
}

// Approach fo variation 2:
// First, we will print the 1st element i.e. 1 manually.
// After that, we will use a loop(say i) that runs from 1 to n-1. It will print the rest of the elements.
// Inside the loop, we will use the above-said formula to print the element. We will multiply the previous answer by (n-i) and then divide it by i itself.
// Thus, the entire row will be printed.

vector<int> pascalsTriangle2(int n){
    // r-th row will contain r elements
    vector<int> res;
    long long ans = 1;
    res.push_back(ans);
    for(int i = 1 ; i <= n ; i++){
        ans = ans*(n-i);
        ans = ans/i;
        res.push_back(ans);
    }
    return res;
}

// Approach for variation 3:
// The steps are as follows:
// First, we will run a loop(say row) from 1 to n.
// Inside the loop, we will call a generateRow() function and add the returned list to our final answer. Inside the function we will do the following:
// First, we will store the 1st element i.e. 1 manually.
// After that, we will use a loop(say col) that runs from 1 to n-1. It will store the rest of the elements.
// Inside the loop, we will use the specified formula to print the element. We will multiply the previous answer by (row-col) and then divide it by col itself.
// Thus, the entire row will be stored and returned.
// Finally, we will return the answer list.

vector<vector<int>> pascalsTriangle3(int n){
    vector<vector<int>> res;
    for(int i = 1 ; i <= n ; i++){
        res.push_back(pascalsTriangle2(i));
    }
    return res;
}