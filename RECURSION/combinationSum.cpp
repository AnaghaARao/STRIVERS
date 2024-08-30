// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.The same number may be chosen from candidates an unlimited number of times. 
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// inputs:
// arr = [2,3,6,7]
// target = 7
// result = [[2,2,3],[7]]

#include<bits/stdc++.h>
using namespace std;

void func(vector<int> arr, int n, int index, int target, vector<int> ds, vector<vector<int>>& res){
    if(index == n){
        if(target == 0) res.push_back(ds);
        return;
    }

    // check if pick is possible and pick actions
    if(arr[index] <= target){
        ds.push_back(arr[index]);
        func(arr, n, index, target-arr[index],ds,res);
        ds.pop_back(); // should pop_back only if element is entered into the list =>  VERY IMPORTANT
    }

    // not pick actions
    func(arr,n,index+1,target,ds,res);
}

int main(){
    vector<int>arr = {2,3,6,7};
    int target = 7;
    int n = 4;
    vector<int> ds;
    vector<vector<int>> res;
    func(arr,n,0,target,ds,res);
    for(auto r : res){
        for(auto ele : r) cout<<ele<<" ";
        cout<<endl;
    }
    return 0;
}