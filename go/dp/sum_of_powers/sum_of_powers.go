package sumofpowers

import "math"

func numberOfWays(n int, x int) int {
	dp := make([]int, n+1)
	prevDp := make([]int, n+1)

	dp[0] = 1
	prevDp[0] = 1

	currentNum := 1
	exponent := 1

	for exponent <= n {
		for i := exponent; i <= n; i++ {
			dp[i] = (dp[i] + prevDp[i-exponent]) % (1e9 + 7)
		}

		currentNum++
		exponent = int(math.Pow(float64(currentNum), float64(x)))

		for i := 1; i <= n; i++ {
			prevDp[i] = dp[i]
		}
	}

	return dp[n]
}
