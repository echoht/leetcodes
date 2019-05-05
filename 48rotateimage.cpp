#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>

using namespace std;

int swap(vector<vector<int> >& matrix, int toput, int x2, int y2){
    int tmp = matrix[x2][y2];
    matrix[x2][y2] = toput;
    return tmp;
}

void rotate(vector<vector<int> >& matrix) {
    int m = 0;
    int n = matrix.size();
    if(n <= 1){
        return;
    } 
    int max_m = n/2 - 1; // the largest m, m start from 0
    while(m <= max_m ){
        int x = m;
        int tmp ;
        int nx,ny;
        for(int y = m; y < n-m-1; y++){
            tmp = matrix[x][y];
            nx = x+y-m;
            ny = n-m-1;
            std::cout<< tmp << "(" << x<<","<< y << ")";
            std::cout<< " put into (" << nx <<","<<ny<<")" <<std::endl;
            tmp = swap(matrix, tmp, nx, ny);
            std::cout<< tmp << "(" << nx<<","<< ny << ")";
            ny = ny-nx+m;
            nx = n-m-1;
            std::cout<< " put into (" << nx <<","<<ny<<")" << std::endl ;
            tmp = swap(matrix, tmp, nx, ny);
            std::cout<< tmp << "(" << nx<<","<< ny << ")";
            nx = nx+ny-(n-m-1);
            ny = m;
            std::cout<< " put into (" << nx <<","<<ny<<")" << std::endl ;
            tmp = swap(matrix, tmp, nx, ny);
            std::cout<< tmp << "(" << nx<<","<< ny << ")";
            ny = ny-nx+(n-m-1);
            nx=m;
            std::cout<< " put into (" << nx <<","<<ny<<")" << std::endl ;
            tmp = swap(matrix, tmp, nx, ny);
        }
        m++;
    }    
}

int main(){
    int n = 3;
    vector<vector<int> > a;
    int x = 0;
    for(int i = 0; i < n; i++){
        vector<int> tmp;
        for(int j = 0; j < n; j++){
            tmp.push_back(++x);
        }
        a.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout<<a[i][j] << ",";
        }
        std::cout<<std::endl;
    }
    rotate(a);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout<<a[i][j] << ",";
        }
        std::cout<<std::endl;
    }
}
