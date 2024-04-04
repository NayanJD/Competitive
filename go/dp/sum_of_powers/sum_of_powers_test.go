package sumofpowers

import (
	"fmt"
	"log/slog"
	"testing"
)

func TestNumberOfWays(t *testing.T) {
	slog.SetLogLoggerLevel(slog.LevelDebug)

	type test struct {
		inputN int
		inputX int
		want   int
	}

	testcases := []test{
		{inputN: 10, inputX: 2, want: 1},
		{inputN: 4, inputX: 1, want: 2},
		{inputN: 213, inputX: 1, want: 55852583},
	}

	for _, tc := range testcases {
		t.Run(fmt.Sprintf("n: %v, x:%v", tc.inputN, tc.inputX), func(t *testing.T) {
			got := numberOfWays(tc.inputN, tc.inputX)

			if got != tc.want {
				t.Errorf("got: %v, want: %v", got, tc.want)
			}
		})
	}
}
