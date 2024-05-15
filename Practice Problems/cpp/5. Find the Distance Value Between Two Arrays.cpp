#include <iostream>
#include <vector>

using namespace std;

// GENERIC TEMPLATE
bool condition(int midVal, int target) {
    // Implement the condition based on the problem requirements
    return midVal < target;
}

bool checkIfThisIsDistanceValue(int index, vector<int>& arr, int d, int val){  // 1, 8, 9, 10
    if(index == 0){
        if(arr[index]-val <= d)
            return false;
        return true;
    }
    if(index == arr.size()){
        if(val-arr[index-1] <= d)
            return false;
        return true;
    }
    if(arr[index]-val <= d || val-arr[index-1] <= d){
        return false;
    }
    return true;
}

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int count = 0;
    sort(arr2.begin(), arr2.end());
    
    for (int i = 0; i < arr1.size(); i++) {
        int target = arr1[i];
        int left = 0;
        int right = arr2.size() - 1;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (condition(arr2[mid], target)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if( checkIfThisIsDistanceValue(ans+1, arr2, d, arr1[i]) ){
            count++;
        }
    }
    
    return count;
}
