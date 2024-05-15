#include<iostream>
#include<vector>

using namespace std;

bool isGreaterThan(char midValue, char target){
    return midValue > target;
}

int upperBound(vector<char>& letters, char target){

    int left = 0;
    int right = letters.size()-1;
    char ans = letters[0];

    while(left <= right){
        int mid = left + (right-left)/2;

        if (isGreaterThan(letters[mid], target)) {
            ans = letters[mid];
            right = mid-1;
        } else {
            left = mid+1;
        }
    }

    return ans;

}

char nextGreatestLetter(vector<char>& letters, char target) {
    
    // LowerBound -> first index of element greater than or equal to target (>=)
    // UpperBound -> first index of element greater than the target (>)

    // Here we require strictly greater than

    return upperBound(letters, target);
}