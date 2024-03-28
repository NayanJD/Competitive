package maximalgap

import (
	"fmt"
	"log/slog"
	"math"
	"slices"
)

type Bucket struct {
	maxElement int
	minElement int
	isUsed     bool
}

func NewBucket() *Bucket {
	return &Bucket{
		maxElement: math.MinInt,
		minElement: math.MaxInt,
		isUsed:     false,
	}
}

func maximumGap(nums []int) int {
	n := len(nums)

	if n == 1 {
		return 0
	}

	minElement := slices.Min(nums)

	maxElement := slices.Max(nums)

	b := int(math.Ceil(float64(maxElement-minElement) / float64(n-1)))

	slog.Debug(fmt.Sprintf("b: %v", b))

	if b == 0 {
		return 0
	}

	k := ((maxElement - minElement) / b) + 1

	slog.Debug(fmt.Sprintf("k: %v", k))

	buckets := make([]*Bucket, k)

	for i := 0; i < k; i++ {
		buckets[i] = NewBucket()
	}

	var bucketIndex int

	for i := 0; i < n; i++ {
		bucketIndex = (nums[i] - minElement) / b

		buckets[bucketIndex].maxElement = max(buckets[bucketIndex].maxElement, nums[i])
		buckets[bucketIndex].minElement = min(buckets[bucketIndex].minElement, nums[i])
		buckets[bucketIndex].isUsed = true
	}

	var maxGap int

	var prevBucket *Bucket
	for i := 0; i < k; i++ {
		if !buckets[i].isUsed {
			continue
		}

		if prevBucket == nil {
			prevBucket = buckets[i]
		} else {
			maxGap = max(maxGap, buckets[i].minElement-prevBucket.maxElement)
			prevBucket = buckets[i]
		}
	}

	return maxGap
}
