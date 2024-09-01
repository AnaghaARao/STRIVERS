// Given an integer array nums that may contain duplicates, return all possible 
// subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

#include<bits/stdc++.h>
using namespace std;

void func(vector<int>& arr, int index, vector<int>ds, vector<vector<int>>& res){
    res.push_back(ds);

    for(int i = index ; i < arr.size() ; i++){
        if(i>index && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        func(arr, i+1, ds,res);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // very important
    vector<int> ds;
    vector<vector<int>> res;
    func(nums,0,ds,res);
    return res;
}