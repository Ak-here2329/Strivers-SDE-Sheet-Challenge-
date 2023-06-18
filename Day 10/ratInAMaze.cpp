#include <bits/stdc++.h> 

bool check(int i, int j, int n){
    if(i < 0 || j < 0 || i >= n || j >= n)
        return false;
    return true;
}

void solveMaze(vector<vector<int>> &maze, vector<vector<int>> &curr, vector<vector<int>> &ans, int x,int y){
    int n = maze.size();
    
    if(x == n-1 && y == n-1){
        vector<int> temp;
        for(auto i : curr)
            for(auto j : i)
                temp.push_back(j);
        ans.push_back(temp);
        return;
    }    

    int dx[] = {1, 0, 0, -1}, dy[] = {0, 1, -1, 0};
    for(int i=0; i<4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(check(nx, ny, n) && maze[nx][ny] && !curr[nx][ny]){
            curr[nx][ny] = 1;
            solveMaze(maze, curr, ans, nx, ny);
            curr[nx][ny] = 0; 
        }
    }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    // Write your code here.
    vector<vector<int>> ans, curr(n, vector<int>(n, 0));
    if (maze[0][0]) {
        curr[0][0] = 1;
        solveMaze(maze, curr, ans, 0, 0);
    }

    return ans;
}
