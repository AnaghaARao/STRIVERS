#include<bits/stdc++.h>
using namespace std;

void func(vector<int>& nums, int index, vector<vector<int>>& res){
    if(index == nums.size()){
        res.push_back(nums);
        return ;
    }

    for(int i = index ; i < nums.size() ; i++){
        swap(nums[i],nums[index]);
        func(nums,index+1,res);
        swap(nums[i],nums[index]);
    }
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res;
    func(nums,0,res);
    return 0;
}