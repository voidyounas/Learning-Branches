package main

import (
	"fmt"
)

var balance float64 = 1000.0
var username = "user"
var password = "pass"

func main() {
	var inputUser, inputPass string

	fmt.Print("Enter username: ")
	fmt.Scanln(&inputUser)

	fmt.Print("Enter password: ")
	fmt.Scanln(&inputPass)

	if inputUser == username && inputPass == password {
		atmMenu()
	} else {
		fmt.Println("Invalid credentials. Access denied.")
	}
}

func atmMenu() {
	for {
		fmt.Println("\nATM Menu")
		fmt.Println("1. Check Balance")
		fmt.Println("2. Deposit")
		fmt.Println("3. Withdraw")
		fmt.Println("4. Exit")
		fmt.Print("Choose an option: ")

		var choice int
		fmt.Scanln(&choice)

		switch choice {
		case 1:
			checkBalance()
		case 2:
			deposit()
		case 3:
			withdraw()
		case 4:
			fmt.Println("Exiting...")
			return
		default:
			fmt.Println("Invalid choice.")
		}
	}
}

func checkBalance() {
	fmt.Printf("Current balance: %.2f\n", balance)
}

func deposit() {
	var amount float64
	fmt.Print("Enter amount to deposit: ")
	fmt.Scanln(&amount)
	if amount > 0 {
		balance += amount
		fmt.Printf("Deposited: %.2f\n", amount)
		fmt.Printf("New balance: %.2f\n", balance)
	} else {
		fmt.Println("Invalid amount.")
	}
}

func withdraw() {
	var amount float64
	fmt.Print("Enter amount to withdraw: ")
	fmt.Scanln(&amount)
	if amount > 0 && amount <= balance {
		balance -= amount
		fmt.Printf("Withdrawn: %.2f\n", amount)
		fmt.Printf("New balance: %.2f\n", balance)
	} else {
		fmt.Println("Invalid or insufficient amount.")
	}
}
