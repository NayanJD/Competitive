package climbingstairs

import (
	"fmt"
	"log/slog"
	"testing"
)

func TestNumberOfWays(t *testing.T) {
	slog.SetLogLoggerLevel(slog.LevelDebug)

	type test struct {
		inputN int
		want   int
	}

	testcases := []test{
		{inputN: 45, want: 1836311903},
		{inputN: 3, want: 3},
		{inputN: 2, want: 2},
	}

	for _, tc := range testcases {
		t.Run(fmt.Sprintf("n: %v", tc.inputN), func(t *testing.T) {
			got := climbStairs(tc.inputN)

			if got != tc.want {
				t.Errorf("got: %v, want: %v", got, tc.want)
			}
		})
	}
}
