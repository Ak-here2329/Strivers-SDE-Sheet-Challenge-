
bool check(vector<vector<int>> &grid, int x, int y){
    //col check
    int n = grid.size();
    for(int i=0; i<n; i++){
        if(i == x)
            continue;
        if(grid[i][y] == 1)
            return false;
    }

    //left diag
    for(int i=x-1, j = y-1; i>=0 && j>=0; i--, j--){
        if(grid[i][j] == 1)
            return false;
    }
    //right diag
    for(int i=x-1, j = y+1; i>=0 && j<n; i--, j++){
        if(grid[i][j] == 1)
            return false;
    }
    return true;
}


void solve(vector<vector<int>> &grid, int idx, vector<vector<int>> &ans){
    //base case
    if(idx >= grid.size()){
        vector<int> curr;
        for(auto i : grid){
            for(auto j : i)
                curr.push_back(j);
        }
        if(curr.size())
            ans.push_back(curr);
        return;
    }
    
    
    //rec soln

    for(int j=0; j<grid.size(); j++){
        if(check(grid, idx, j)){
            grid[idx][j] = 1;
            solve(grid, idx + 1, ans);
            grid[idx][j] = 0;
        }
    }
    
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(grid, 0, ans);
    return ans;
}
