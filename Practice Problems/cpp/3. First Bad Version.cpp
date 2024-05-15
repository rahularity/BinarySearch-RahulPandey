#include<iostream>
#include<vector>

using namespace std;
int firstBadVersion(int n) {
    // lookslike -> F,F,F,F,F,F,F,F,T,T,T  (sort of situation)
    // implement lowerBound -> find the first occurance of T in the array

    int left = 1;
    int right = n;
    int ans = -1;   // can be -1 also according to question what if there is no bad version

    while(left <= right){
        int mid = left + (right-left)/2;

        if(isBadVersion(mid)){
            ans = mid;
            right = mid-1; 
        }
        else{
            // if false answer can only lie in the right side
            left = mid+1;
        }
    }

    return ans;
}