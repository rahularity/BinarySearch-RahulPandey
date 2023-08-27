#include<iostream>
#include<vector>

using namespace std;

bool condition(int midVal, int target){
    return midVal >= target;
}

int lowerBound(vector<int>& arr, int target){

    int n = arr.size();
    int left = 0;
    int right = n-1;

    int ans = -1; // if everything is F, then return initialized value

    while (left <= right){

        int mid = left + (right-left)/2;

        if( condition(arr[mid], target) ){
            ans = mid;
            right = mid-1; // left = mid+1
        }
        else {
            left = mid + 1; // right = mid-1;
        }

    }

    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {

    // lowerBound -> first index of the element >= target
    // upperBound -> first index of the element > target

    // firstOccurance = lowerBound(target)
    // lastOcccurance = upperBound(target) - 1

    // upperBound(target) = lowerBound(target+1)

    // nums = [5,7,7,8,8,10], target = 8
    // lb(8) = 3
    // lb(9) = 5 = up(8)

    int n = nums.size();
    int start = lowerBound(nums, target);
    int end = lowerBound(nums, target+1);

    // check if target does not exist
    if(start == -1 || nums[start] != target){
        return {-1,-1};
    }

    // [5,7,7,8,8,8], target=8
    if(end == -1){
        return {start, n-1};
    }

    return {start, end-1};

}


int main(){

    vector<int> arr = {5,7,7,8,8,8};
    vector<int> ans = searchRange(arr, 8);

    cout << "first occurance is : " << ans[0] << "\nlast occurance is : " << ans[1];

}