bool valid(int matrix[9][9], int i, int j, int val){

    for(int k=0; k<9; k++){
        if(matrix[i][k] == val)
            return false;
        if(matrix[k][j] == val)
            return false;
        if(matrix[3*(i/3) + k/3][3*(j/3) + k%3] == val)
            return false;
    }

    return true;
}


bool isItSudoku(int matrix[9][9]) {
    // Write your code here.

    int n = 9;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                for(int val=1; val<=n; val++){
                    if(valid(matrix, i, j, val)){
                        matrix[i][j] = val;
                        if(isItSudoku(matrix))
                            return true;
                        else
                            matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }

    return true;
}
