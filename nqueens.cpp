class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>ops;
        vector <int> temp;
        vector<bool>col(n,false);
        helper (ops,temp, 0,col, n);
        string row;
        for (int i = 0; i < n; i++){
            row.push_back('.');
        }
        vector<vector<string>> result
            ((short)ops.size(),vector<string>(n,row));
        for (int i = 0; i < (short)ops.size(); i++){
            for (int j = 0; j < n; j++){
                result[i][j][ops[i][j]] = 'Q';
            }
        }
        if (n == 1){
            return vector<vector<string>>(1, vector<string>(1,"Q"));
        }
        return result;
    }
    void helper(vector<vector<int>>&o, vector<int> temp, int row, vector<bool> col, int n
               ){
        if (row == n && d_valid(temp,n)){
            o.push_back(temp);
            return;
        }
        if (row == n && !d_valid(temp,n)){
            return;
        }
        
        // if statement to try all cols of first row
        // need recursive call to following rows and decrement remaining queen count, as well as obeying the column rule per row
        if (row < n){
            for (int i = 0; i < n; i++){
                if (col[i] == false){
                    vector<bool> ctemp = col;
                    ctemp[i] = true;
                    vector<int> ntemp = temp;
                    ntemp.push_back(i);
                    helper(o, ntemp, row+1, ctemp, n );
                }
            }
        }
        return;
        
        
        
        
    }
    bool d_valid(vector<int>v,int n){
        int a,b,c;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if ( j == i){
                    continue;
                }
                a = abs(i - j);
                b = abs(v[j] - v[i]);
                c = a-b;
                if (c == 0 && j!= i){
                    return false;
                }
            }
        }
        return true;
    }
};
