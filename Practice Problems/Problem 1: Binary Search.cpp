#include<iostream>
#include<vector>
using namespace std;

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target);
    }

    int binarySearch(vector<int>& arr, int target){

        int left = 0;
        int right = arr.size()-1;  // arr.size()

        while( left <= right ){
            int mid = (left + right) / 2;

            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        return -1;

    }

int main(){

    vector<int> arr = {-1,0,3,5,9,12};
    cout << search(arr, 2);
}
