// Given an integer array nums of unique elements, return all possible 
// subsets(the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

#include<bits/stdc++.h>
using namespace std;

void func(vector<int>& arr, int n, int index, vector<int> ds, vector<vector<int>>& res){
    if(index == n){
        res.push_back(ds);
        return;
    }

    ds.push_back(arr[index]);
    func(arr,n,index+1,ds,res);
    ds.pop_back();
    func(arr,n,index+1,ds,res);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> ds;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    func(nums,nums.size(), 0, ds, res);
    return res;        
}