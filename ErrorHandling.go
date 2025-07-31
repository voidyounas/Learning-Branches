package main

import (
	"fmt"
	"strconv"
)

func main() {
	defer handlePanic()

	var arr [5]int
	fmt.Println("Enter 5 numbers to store in the array:")

	for i := 0; i < len(arr); i++ {
		var input string
		fmt.Printf("Enter number %d: ", i+1)
		fmt.Scanln(&input)

		num, err := strconv.Atoi(input)
		if err != nil {
			panic("Invalid input! Please enter only integers.")
		}
		arr[i] = num
	}

	fmt.Println("Your array is:", arr)

	fmt.Println("Accessing 10th element to simulate error:")
	fmt.Println(arr[9])
}

func handlePanic() {
	if r := recover(); r != nil {
		fmt.Println("Recovered from panic:", r)
	}
}
