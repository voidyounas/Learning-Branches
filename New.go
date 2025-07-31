package main

import (
	"fmt"
)

func add(a int, b int) int {
	return a + b
}

func greet(name string) {
	fmt.Println("Hello,", name)
}

func calculate(x int, y int) (int, int) {
	sum := x + y
	product := x * y
	return sum, product
}

func main() {
	result := add(10, 5)
	fmt.Println("Sum:", result)

	greet("Alpha")

	sum, product := calculate(4, 3)
	fmt.Println("Sum is:", sum)
	fmt.Println("Product is:", product)
}
