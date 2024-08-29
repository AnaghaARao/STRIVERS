#include<bits/stdc++.h>
using namespace std;

void func(vector<int>arr, int index, vector<int>& res){
    if(index >= arr.size()){
        // print(res)
        if(res.size() == 0){
            cout<<"{}"<<endl;
        }else{
            for(auto ele : res) cout<<ele<<" ";
            cout<<endl;
        }
        return;
    }

    // case 1: element added to the subsequence
    res.push_back(arr[index]);
    func(arr, index+1, res);
    // case 2: element not added to the subsequence
    res.pop_back();
    func(arr, index+1, res);
}

// time complexity:
// for generating sub sequence using recursive call: 2^n
// printing each subsequence: n
// time complexity = 2^n * n

// space complexity:
// height of recursive tree: n ( no. of elements)
// stack space => O(n)