#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
using namespace std;
using std::vector;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        int maxSequence = 1;
        int temp = 1;
        for (int i = nums.size() - 2;i >= 0;i--) {
            temp = 1;
            for (int j = i + 1;j < nums.size();j++) {
                if (nums[j] > nums[i]) {
                    temp = max(temp, 1 + dp[j]);
                }
            }
            dp[i] = temp;
            if (temp > maxSequence) {
                maxSequence = temp;
            }
        }
        return maxSequence;
    }
};



int main(int argc, char** argv){
    Solution* lis = new Solution();
    int sequence_length ,element;
    cin >> sequence_length;

    vector<int> nums;

    for (int i = 0; i < sequence_length; i++) {
        cin >> element;
        nums.push_back(element);

    }

    cout<<lis->lengthOfLIS(nums);

}