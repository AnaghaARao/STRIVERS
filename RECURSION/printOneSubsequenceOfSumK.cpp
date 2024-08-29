#include<bits/stdc++.h>
using namespace std;

bool func(vector<int> arr, int n, int k, int index, vector<int>& res, int& sum){
    if(index==n){
        if(sum == k){
            for(auto ele: res) cout<<ele<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }

    res.push_back(arr[index]);
    sum += arr[index];
    if(func(arr,n,k,index+1,res,sum)) return true;

    res.pop_back();
    sum-=arr[index];
    if(func(arr,n,k,index+1,res,sum)) return true;
    return false;
}

// problem modification:
// return the number of subsequence whose sum = k:
// modification:  return int
// in base case: if(sum==k) return 1, else return 0
// remaining statements are the same => only we are not returning bool values but instead int values & definetely calling each combination

int func1(vector<int> arr, int n, int k, int index, vector<int>& res, int& sum){
    if(index==n){
        if(sum == k) return 1;
        else return 0;
    }

    // pick the element
    res.push_back(arr[index]);
    sum += arr[index];
    int l = func1(arr,n,k,index+1,res,sum);

    // dont pick the element
    res.pop_back();
    sum-=arr[index];
    int r = func1(arr,n,k,index+1,res,sum);

    return l+r;
}