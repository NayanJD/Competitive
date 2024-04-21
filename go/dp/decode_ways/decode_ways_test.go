package decodeways

import (
	"fmt"
	"log/slog"
	"testing"
)

func TestNumberOfWays(t *testing.T) {
	slog.SetLogLoggerLevel(slog.LevelDebug)

	type test struct {
		inputN string
		want   int
	}

	testcases := []test{
		{inputN: "12", want: 2},
		{inputN: "226", want: 3},
		{inputN: "06", want: 0},
		{inputN: "106", want: 1},
	}

	for _, tc := range testcases {
		t.Run(fmt.Sprintf("n: %v", tc.inputN), func(t *testing.T) {
			got := numDecodings(tc.inputN)

			if got != tc.want {
				t.Errorf("got: %v, want: %v", got, tc.want)
			}
		})
	}
}
