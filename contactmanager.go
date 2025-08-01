package main

import (
	"fmt"
	"strings"
)

var names []string
var phones []string
var emails []string

func main() {
	for {
		fmt.Println("\nContact Management System")
		fmt.Println("1. Add Contact")
		fmt.Println("2. View All Contacts")
		fmt.Println("3. Search Contact")
		fmt.Println("4. Delete Contact")
		fmt.Println("5. Exit")
		fmt.Print("Choose an option: ")

		var choice int
		fmt.Scanln(&choice)

		switch choice {
		case 1:
			addContact()
		case 2:
			viewContacts()
		case 3:
			searchContact()
		case 4:
			deleteContact()
		case 5:
			fmt.Println("Exiting...")
			return
		default:
			fmt.Println("Invalid choice.")
		}
	}
}

func addContact() {
	var name, phone, email string
	fmt.Print("Enter name: ")
	fmt.Scanln(&name)
	fmt.Print("Enter phone: ")
	fmt.Scanln(&phone)
	fmt.Print("Enter email: ")
	fmt.Scanln(&email)

	nameLower := strings.ToLower(name)
	for _, existingName := range names {
		if strings.ToLower(existingName) == nameLower {
			fmt.Println("Contact already exists.")
			return
		}
	}

	names = append(names, name)
	phones = append(phones, phone)
	emails = append(emails, email)

	fmt.Println("Contact added.")
}

func viewContacts() {
	if len(names) == 0 {
		fmt.Println("No contacts found.")
		return
	}

	for i := 0; i < len(names); i++ {
		fmt.Printf("Name: %s, Phone: %s, Email: %s\n", names[i], phones[i], emails[i])
	}
}

func searchContact() {
	var search string
	fmt.Print("Enter name to search: ")
	fmt.Scanln(&search)

	found := false
	for i := 0; i < len(names); i++ {
		if strings.ToLower(names[i]) == strings.ToLower(search) {
			fmt.Printf("Found - Name: %s, Phone: %s, Email: %s\n", names[i], phones[i], emails[i])
			found = true
			break
		}
	}

	if !found {
		fmt.Println("Contact not found.")
	}
}

func deleteContact() {
	var delName string
	fmt.Print("Enter name to delete: ")
	fmt.Scanln(&delName)

	index := -1
	for i := 0; i < len(names); i++ {
		if strings.ToLower(names[i]) == strings.ToLower(delName) {
			index = i
			break
		}
	}

	if index == -1 {
		fmt.Println("Contact not found.")
		return
	}

	names = append(names[:index], names[index+1:]...)
	phones = append(phones[:index], phones[index+1:]...)
	emails = append(emails[:index], emails[index+1:]...)

	fmt.Println("Contact deleted.")
}
