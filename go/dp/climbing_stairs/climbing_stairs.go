package climbingstairs

func climbStairs(n int) int {
	return nthFibonacciNumber(n)
}

func nthFibonacciNumber(n int) int {
	var result [2][2]int

	// Making result a identity matrix
	result[0][0] = 1
	result[1][1] = 1

	// (a^n)[0][0] would be the nth fibonacci number
	var a [2][2]int

	a[0][0] = 1
	a[0][1] = 1
	a[1][0] = 1

	// Eg. We want to calculate a^7. It can be broken
	// down into:
	//
	// a^(2^2 + 2^1 + 2^0) = a^(2^2) X a^(2^1) X a^(2^0)
	//
	// Power of a is down by line 34 and the multiplication is done by
	// line 30
	for n > 0 {
		if (n & 1) == 1 {
			result = matrixMultiply2x2(result, a)
		}

		n >>= 1

		a = matrixMultiply2x2(a, a)
	}

	return result[0][0]
}

func matrixMultiply2x2(a, b [2][2]int) [2][2]int {
	var result [2][2]int

	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			result[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j]
		}
	}

	return result
}
