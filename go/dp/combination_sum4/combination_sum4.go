package combinationsum4

func combinationSum4(nums []int, target int) int {
	n := len(nums)

	dp := make([]uint32, target+1)

	dp[0] = 1

	for i := 1; i < target+1; i++ {
		for j := 0; j < n; j++ {
			if nums[j] <= i {
				dp[i] += dp[i-nums[j]]
			}
		}
	}

	return int(dp[target])
}
