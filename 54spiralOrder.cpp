class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m <= 0){
            return res;
        }
        int n = matrix[0].size();
        if(n <= 0){
            return res;
        }
        int cicle = m > n ? n : m;
        if(cicle % 2 == 0){
            cicle = cicle/2;
        }else{
            cicle = cicle/2 + 1;
        }
        for(int i = 0; i < cicle; i++){
            //->
            int x, y;
            x = i;
            for(y = i; y < n-i; y++){
                res.push_back(matrix[x][y]);
            }
            //|
            y = n-i-1;
            for(x = i+1; x < m-i; x++){
                res.push_back(matrix[x][y]);
            }
            //<-
            x = m-i-1;
            if(x != i){
                for(y = n-i-2; y >= i;  y--){
                    res.push_back(matrix[x][y]);
                }
            }
            //|
            y = i;
            if( y != n-i-1)
            {
                for(x = m-i-2; x > i; x--){
                    res.push_back(matrix[x][y]);
                }    
            }
               
        }
        return res;
    }
};
