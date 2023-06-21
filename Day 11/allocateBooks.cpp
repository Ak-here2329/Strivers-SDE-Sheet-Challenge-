//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossibleSolution(int a[], int n, int m, int barrier){
        int studalloc = 1, pages = 0;
        for(int i=0; i<n; i++){
            
            if(a[i] > barrier)
                return false;
            
            if(pages + a[i] > barrier){
                studalloc++;
                pages = a[i];
            }else
                pages += a[i];
        }
        
        
        return studalloc <= m;
    }
    int findPages(int A[], int N, int M){
        //code here
        if(M > N)
            return -1;
        int s = INT_MAX, e = 0, ans = -1;
        for(int i=0; i<N; i++)
            e += A[i], s = min(s, A[i]);
        
        
        while(s <= e){
            int page = s + (e - s) / 2;
            if(isPossibleSolution(A, N, M, page)){
                ans = page;
                e = page - 1;
            }else
                s = page + 1;
            
        }
        
        
        return ans;
    }
};
