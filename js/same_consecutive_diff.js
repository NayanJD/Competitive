// https://leetcode.com/problems/numbers-with-same-consecutive-differences/
/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
 var numsSameConsecDiff = function(n, k) {
    let result = new Set();

    for(let i = 1; i <= 9; i++){
        findNumbersRecursively(result, 0, i, 0, n , k);
    }

    

    return Array.from(result);
};

function findNumbersRecursively(result, currNumTillNow, num, level, n, k) {
    let currNum = currNumTillNow * 10 + num;
    if(level == n-1){
        result.add(currNum);
    } else {
        if(num + k <=9){
            findNumbersRecursively(result, currNum, num + k, level + 1, n, k);
        }

        if(num - k >= 0){
            findNumbersRecursively(result, currNum, num - k, level + 1, n, k);
        }
    }
}

let result = numsSameConsecDiff(3, 7);

console.log(result);