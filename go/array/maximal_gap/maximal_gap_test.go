package maximalgap

import (
	"fmt"
	"log/slog"
	"testing"
)

func TestMaximalGap(t *testing.T) {
	slog.SetLogLoggerLevel(slog.LevelDebug)

	type test struct {
		input []int
		want  int
	}

	testcases := []test{
		{input: []int{3, 6, 9, 1}, want: 3},
		{input: []int{1, 1, 1, 1}, want: 0},
	}

	for _, tc := range testcases {
		t.Run(fmt.Sprintf("Array: %#v", tc.input), func(t *testing.T) {
			got := maximumGap(tc.input)

			if got != tc.want {
				t.Errorf("got: %v, want: %v", got, tc.want)
			}
		})
	}
}
