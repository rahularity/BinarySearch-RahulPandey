#include<iostream>
#include<vector>

using namespace std;

// GENERIC TEMPLATE
bool condition(int midVal, int target){
    return midVal < target;
}

int BinarySearch(vector<int>& arr, int target){

    int n = arr.size();
    int left = 0;
    int right = n-1;

    int ans = -1; // if everything is F, then return initialized value

    while (left <= right){

        int mid = left + (right-left)/2;

        if( condition(arr[mid], target) ){
            ans = mid;
            left = mid + 1; // right = mid-1;
        }
        else {
            right = mid - 1; // left = mid+1
        }

    }

    return ans;
}

int searchInsert(vector<int>& nums, int target) {
    int index = BinarySearch(nums, target);
    return index == -1 ? 0 : index + 1;
}

int main() {
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Input: nums = [1,3,5,6], target = 5\nOutput: " << searchInsert(nums1, target1) << endl;

    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Input: nums = [1,3,5,6], target = 2\nOutput: " << searchInsert(nums2, target2) << endl;

    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Input: nums = [1,3,5,6], target = 7\nOutput: " << searchInsert(nums3, target3) << endl;

    return 0;
}
