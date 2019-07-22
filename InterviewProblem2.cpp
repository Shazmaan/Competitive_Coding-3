//
// Created by shazm on 7/22/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>

//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> retVec;
        for(int i = 0; i<numRows;i++){
            vector<int> vec;
            for(int j = 0; j<i+1; j++){
                if(j==0 || j==i){
                    vec.push_back(1);
                }else{
                    vec.push_back(retVec[i-1][j-1]+retVec[i-1][j]);
                }
            }
            retVec.push_back(vec);
        }
        return retVec;
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec = s.generate(5);
    for(int i = 0; i<vec.size(); i++){
        for(int j =0; j<vec[i].size(); j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}