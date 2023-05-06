// https://leetcode.com/problems/split-array-largest-sum
//
// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.
// 
// A subarray is a contiguous part of the array.
// 
//  
// 
// Example 1:
// 
// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// Example 2:
// 
// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 106
// 1 <= k <= min(50, nums.length)


#include<iostream>
#include<vector>

using namespace std;

void printDp(int** dp, int m, int n) {
	for(int i = 0; i < m; i++){
		for(int j = 0; i < n; j++){
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}
}

class Solution {
public:
	int splitArray(vector<int>& nums, int k) {
		int sum = 0, largest = (int) -10e6, n = nums.size();

		for(const int& num: nums) {
			sum += num;
			largest = max(largest, num);
		}

		int lo = largest, hi = sum, mid = 0, div = 0;

		while(lo < hi) {
			mid = (lo + hi) / 2;

			div = isPossible(nums, k, mid);

			
			//printf("hi: %d, lo: %d, mid: %d, div: %d, k: %d\n", hi, lo, mid, div, k);

			if(div < k) {
				hi = mid - 1;
			} else if (div > k) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}

		return lo;	
	}

	int isPossible(vector<int>& nums, int k, int& val) {
		int remainingParts{1001}, parts{0}, sum{0}, count{0}, n = nums.size();

		for(const int& num: nums){
			if(sum + num > val) {
				parts++;
				sum = num;
				count = 1;
			} else if (sum + num == val) {
				count++;
				remainingParts = max(remainingParts, n - count);
				parts++;
				count = 0;
				sum = 0;

			}
			else {
				sum += num;
				count++;
			}
		}

		if(sum > 0) {
			parts++;
		} 


		if(parts <= k) {
			if(remainingParts >= k - 1){
				return k;
			} else {
				return k - 1;
			}
		} else {
			return parts;
		}

	}

    //int splitArray(vector<int>& nums, int k) {
    //    int n = nums.size(), inf = (int) 10e6;

	//	int dp[k][n];

	//	for(int i = 0; i < k; i++){
	//		for(int j = 0; j < n;  j++) {
	//			dp[i][j] = inf;
	//		}
	//	}
	//	
	//	int sum = 0;
	//	for(int i = n - 1; i >= 0; i--){
	//		sum += nums[i];
	//		dp[0][i] = sum;
	//	}
	//	
	//	if(k == 1) {
	//		return dp[0][0];
	//	}
	//	
	//	int smallest = inf;
	//	for(int i = 1; i < k; i++){
	//		for(int j = n - i - 1; j >= 0; j--) {
	//			smallest = inf;
	//			for(int k = j; k < n - i ; k++){
	//				smallest = min(max(dp[0][j] - dp[0][k + 1], dp[i - 1][k + 1]), smallest);
	//			}
	//			dp[i][j] = smallest;
	//		}
	//	}
	//	
//	//	for(int i = 0; i < k; i++){
//	//		for(int j = 0; j < n; j++){
//	//			printf("%d\t", dp[i][j]);
//	//		}
//	//		printf("\n");
//	//	}
//
	//	

	//	return dp[k-1][0];
    //}
};

int main(){
	Solution sol;

	vector<int> arr = {7,2,5,10,8};
	int k = 2;

	printf("Minimized largest sum: %d\n", sol.splitArray(arr,k));

	arr = {1,2,3,4,5};
	k = 2;


	printf("Minimized largest sum: %d\n", sol.splitArray(arr,k));

	arr = {2,3,1,1,1,1,1};
	k = 5;


	printf("Minimized largest sum: %d\n", sol.splitArray(arr,k));

	arr = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
	k =20;


	printf("Minimized largest sum: %d\n", sol.splitArray(arr,k));
}
