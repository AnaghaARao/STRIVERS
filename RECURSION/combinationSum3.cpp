// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// 1. Only numbers 1 through 9 are used.
// 2. Each number is used at most once.
// Return a list of all possible valid combinations. 
// The list must not contain the same combination twice, and the combinations may be returned in any order.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(int num, int target, int k, vector<int> ds, vector<vector<int>>& res){
        if(k==0){
            if(target==0){
                res.push_back(ds);
            }
            return;
        }

        if(num>target || num>9) return;

        // pick
        ds.push_back(num);
        func(num+1, target-num, k-1, ds, res);
        
        // not pick
        ds.pop_back();
        func(num+1,target,k,ds,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> res;
        func(1,n,k,ds,res);
        return res;
    }
};