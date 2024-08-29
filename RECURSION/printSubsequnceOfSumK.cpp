#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(auto ele : v){
        cout<<ele<<" ";
    }
    if(v.size() == 0) cout<<"{}";
    cout<<endl;
}

void func(vector<int> arr, int k, int n, int i, vector<int>& res, int& sum){
    if(i==n){
        if(sum==k) print(res); // must print only if i==n not before this condition is met
        return;
    }

    // picking the element
    sum += arr[i];
    res.push_back(arr[i]);
    func(arr,k,n,i+1,res,sum);

    // not picking the element
    sum -= arr[i];
    res.pop_back();
    func(arr,k,n,i+1,res,sum);
}