#include<bits/stdc++.h>
using namespace std;

void func(vector<int>& arr, int n, int index, vector<int>& res, int sum){
    if(index == n) {
        res.push_back(sum);
    }

    func(arr,n,index+1,res,sum+arr[index]); // pick activity
    func(arr, n, index+1, res,sum); // not pick activity
}

int main(){
    vector<int> arr = {3,1,2};
    int n = arr.size();
    int index = 0;
    vector<int> res;
    func(arr,n,index,res,0);
}