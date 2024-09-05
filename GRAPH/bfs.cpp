#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[], int n){
    int vis[n] = {0};
    vis[V] = 1;
    queue<int> q;
    q.push(V);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto ele : adj[node]){
            if(!vis[ele]){
                vis[ele] = 1;
                q.push(ele);
            }
        }
    }
    return bfs;
}

// time complexity = O