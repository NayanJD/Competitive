// https://leetcode.com/problems/uncrossed-lines/

// You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.
// 
// We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
// 
// nums1[i] == nums2[j], and
// the line we draw does not intersect any other connecting (non-horizontal) line.
// Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).
// 
// Return the maximum number of connecting lines we can draw in this way.
// 
// Example 1:
// 
// Input: nums1 = [1,4,2], nums2 = [1,2,4]
// Output: 2
// Explanation: We can draw 2 uncrossed lines as in the diagram.
// We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.
// Example 2:
// 
// Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
// Output: 3
// Example 3:
// 
// Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
// Output: 2
//  
// 
// Constraints:
// 
// 1 <= nums1.length, nums2.length <= 500
// 1 <= nums1[i], nums2[j] <= 2000
// 

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();

		int dp[n+1][m+1];

		// for(int i = 0; i < n + 1; i++){
		// 	for(int j = 0; j < m + 1; j++){
		// 		dp[i][j] = 0;
		// 	}
		// }
		//
		for(int i = 0; i < n + 1; i++){
			dp[i][0] = 0;
		}

		for(int j = 0; j < m + 1; j++){
			dp[0][j] = 0;
		}

		int maxUncrossedLines = 0;

		for(int i= 1; i < n + 1; i++){
			for(int j = 1; j < m + 1; j++){
				dp[i][j] = (nums1[i-1] == nums2[j-1]); 
				
				dp[i][j] = max({dp[i][j],dp[i][j-1], dp[i-1][j], dp[i][j] + dp[i-1][j-1]});
				maxUncrossedLines = max(maxUncrossedLines, dp[i][j]);
			}
		}
		
		// for(int i = 0; i < n + 1; i++){
		// 	for(int j = 0; j < m + 1; j++){
		// 		cout << dp[i][j] << ", ";
		// 	}
		// 	cout << endl;
		// }

		// cout << endl << endl;

		return maxUncrossedLines;
    }
};

int main(){

	Solution sol;

	// vector<int> num1 = {1,4,2};
	// vector<int> num2 = {1,4,2,2,2,2};

	// vector<int> num1 = {2,5,1,2,5,2,2};
	// vector<int> num2 = {10,5,2,1,5,2,2};
	
	// vector<int> num1 = {3};
	// vector<int> num2 = {3,3,2};
	
	// vector<int> num1 = {2,1,3};
	// vector<int> num2 = {2,1,2,3,1};

	vector<int> num1 = {1,1,3,5,3,3,5,5,1,1};
	vector<int> num2 = {2,3,2,1,3,5,3,2,2,1};

	printf("Max uncrossed lines: %d\n", sol.maxUncrossedLines(num1, num2));
}
