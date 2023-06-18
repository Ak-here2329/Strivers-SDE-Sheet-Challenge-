#include <bits/stdc++.h> 

bool safe(vector<vector<int>> &mat, int m, int node, vector<int> &vis, int col){
    for(int i=0; i<mat.size(); i++){
        if(i == node)   
            continue;
        if(mat[node][i] && vis[i] == col)
            return false;
    }
    return true;
}

bool dfs(vector<vector<int>> &mat, int m, int node, vector<int> &vis){
    if(node == mat.size())
        return true;

    for(int i=1; i<=m; i++){
        if (safe(mat, m, node, vis, i)) {
            vis[node] = i;
            if(dfs(mat, m, node + 1, vis))
                return true;
            vis[node] = 0;
        }
    }
    return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int> vis(n, 0);
   
    if(!dfs(mat, m, 0, vis))
        return "NO";
    
    return "YES";
}
