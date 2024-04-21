package decodeways

import "strconv"

func numDecodings(s string) int {
	if s[0] == '0' {
		return 0
	}

	prevDecodings := 1
	prevPrevDecodings := 1
	currentNumber := 0
	currentDecodings := 0

	for i := 1; i < len(s); i++ {
		currentNumber, _ = strconv.Atoi(s[i : i+1])

		if currentNumber != 0 {
			currentDecodings = prevDecodings
		}

		currentNumber, _ = strconv.Atoi(s[i-1 : i+1])

		if currentNumber >= 10 && currentNumber <= 26 {
			currentDecodings += prevPrevDecodings
		}

		if currentDecodings == 0 {
			return 0
		}

		prevPrevDecodings = prevDecodings
		prevDecodings = currentDecodings
		currentDecodings = 0
	}

	return prevDecodings
}
