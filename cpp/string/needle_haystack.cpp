#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        // to initialize all elements with 0
        int lps[m];

        int len = 0, j = 1;

        lps[len] = 0;
        while(j < m) {
            // printf("len: %d, j: %d\n", len, j);
            if(needle[len] == needle[j]){
                // printf("Saving to j++\n");
                len++;
                lps[j++] = len;
            } else {
                if(len == 0){
                    lps[j++] = 0;
                } else {
                    len = lps[len - 1];
                }
            }
        }

        // for(int item: lps){
        //     printf("%d ", item);
        // }
        // printf("\n");

        int i = 0;
        j = 0;

        while(j < n){
            if(i == m){
                // printf("Return %d\n", j);
                return j - m; 
            }

            // printf("i: %d, j: %d\n", i, j);
            if(needle[i] == haystack[j]){
                i++;
                j++;
            } else {
                if(i == 0){
                    j++;
                } else {
                    i = lps[i - 1];
                }
            }
        }

        if(i == m){
            return j - m;
        } else {
            return -1;
        }
    }
};

// Worst case: O(n^2)
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
        
//         int n = haystack.size();
//         int m = needle.size();


//         if(m == 0){
//             return 0;
//         }

//         int index = -1;
//         for(int i = 0, j = 0; i < n; i++){
//             if(haystack[i] == needle[j]){
//                 if(j == 0){
//                     index = i;
//                 }

//                 if(j == m - 1){
//                     return index;
//                 }

//                 j++;
//             } else {
//                 if(index != -1){
//                     i = index;
//                 }

//                 index = -1;
//                 j = 0;
//             }

//             if(i == n - 1){
//                 return -1;
//             }
//         }

//         return index;
//     }
// };

int main(){

    Solution sol;

    // printf("%d", sol.strStr("hello", "ll"));
    // printf("%d", sol.strStr("aaaaa", "aaaaaa"));
    // printf("%d", sol.strStr("mississippi", "issip"));
    // printf("%d", sol.strStr("mississippi", "pi"));
    // printf("%d", sol.strStr("aabaaabaaac", "aabaaac"));



    return 0;
}