package main

import (
	"fmt"
)

func sumArray(arr [5]int) int {
	sum := 0
	for _, value := range arr {
		sum += value
	}
	return sum
}

func averageArray(arr [5]int) float64 {
	sum := sumArray(arr)
	return float64(sum) / float64(len(arr))
}

func main() {
	var numbers [5]int

	fmt.Println("Enter 5 numbers:")
	for i := 0; i < 5; i++ {
		fmt.Printf("Enter number %d: ", i+1)
		fmt.Scanln(&numbers[i])
	}

	sum := sumArray(numbers)
	avg := averageArray(numbers)

	fmt.Println("Sum of array:", sum)
	fmt.Println("Average of array:", avg)
}
