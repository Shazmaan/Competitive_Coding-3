//
// Created by shazm on 7/22/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()<2){return 0;} //[1,1,3,4,5]
        sort(nums.begin(),nums.end());
        int count = 0; int slow = 0; int fast = 1;
        for(int x =0; x<nums.size()-1; x++){
            if(abs(nums[slow]-nums[fast])>k){
                int temp = nums[slow];
                while(slow<nums.size() && temp==nums[slow]){
                    slow++;
                }
                if(slow==fast){fast++;}
            }else if(abs(nums[slow]-nums[fast])<k){
                int temp = nums[fast];
                while(fast<nums.size() && temp==nums[fast]){
                    fast++;
                }
            }else{
                count++;
                int temp = nums[slow];
                while(slow<nums.size() && temp==nums[slow] && slow<=fast){
                    slow++;
                }
                temp = nums[fast];
                while(fast<nums.size() && temp==nums[fast] && slow<=fast){
                    fast++;
                }
            }
            if(slow>=nums.size() || fast>=nums.size()){
                break;
            }
            cout<<slow<<" slow "<<fast<<" fast\n";
        }
        return count;
    }
};