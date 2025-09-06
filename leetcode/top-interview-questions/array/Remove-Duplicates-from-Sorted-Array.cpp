#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int j = 0, i = 1;
        while (i < nums.size()) {
            while (i < nums.size() && nums[i] == nums[j])
                i++;
            j++;
            if (i < nums.size()) {
                nums[j] = nums[i];
            }
        }
        return max(j, 1);
    }
};

int main()
{
    Solution solution;
    vector<int> nums = { 1, 1, 1, 1, 1, 1 };

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int newLength = solution.removeDuplicates(nums);

    cout << "New length after removing duplicates: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}