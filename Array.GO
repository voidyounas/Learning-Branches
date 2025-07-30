package main

import (
	"fmt"
)

func main() {
	var numbers [5]int

	fmt.Println("Enter 5 numbers:")
	for i := 0; i < 5; i++ {
		fmt.Print("Enter number ", i+1, ": ")
		fmt.Scanln(&numbers[i])
	}

	fmt.Println("You entered:")
	for i := 0; i < 5; i++ {
		fmt.Println("Element", i, "=", numbers[i])
	}
}
