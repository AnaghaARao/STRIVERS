// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

#include<bits/stdc++.h>
using namespace std;

void func(vector<int>& nums, vector<bool>& map, vector<int> ds, vector<vector<int>>& res){
    if(ds.size()==nums.size()){
        res.push_back(ds);
        return;
    }

    for(int i = 0 ; i < nums.size() ; i++){
        if(!map[i]){
            ds.push_back(nums[i]);
            map[i] = true;
            func(nums,map,ds,res);
            map[i] = false;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<int>ds;
    vector<bool>map(nums.size(),false);
    vector<vector<int>> res;
    func(nums,map,ds,res);
    return res;
}