// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(vector<int> arr, int index, int target, vector<int> ds, vector<vector<int>>& res){
        // base case:
        if(target == 0){
            res.push_back(ds);
            return;
        }

        for(int i = index ; i < arr.size() ; i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            func(arr,i+1,target-arr[i],ds,res);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int>ds;
        func(candidates,0,target,ds,res);
        return res;        
    }
};