package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var titles [100]string
	var authors [100]string
	var ids [100]int
	var count int
	reader := bufio.NewReader(os.Stdin)

	for {
		fmt.Println("\n--- Library Inventory ---")
		fmt.Println("1. Add Book")
		fmt.Println("2. View Books")
		fmt.Println("3. Search by Title")
		fmt.Println("4. Delete by ID")
		fmt.Println("5. Exit")
		fmt.Print("Enter choice: ")

		var choice int
		fmt.Scanln(&choice)

		switch choice {
		case 1:
			if count >= 100 {
				fmt.Println("Inventory Full.")
				continue
			}
			fmt.Print("Enter Book ID: ")
			fmt.Scanln(&ids[count])
			fmt.Print("Enter Book Title: ")
			title, _ := reader.ReadString('\n')
			titles[count] = strings.TrimSpace(title)
			fmt.Print("Enter Author: ")
			author, _ := reader.ReadString('\n')
			authors[count] = strings.TrimSpace(author)
			count++
			fmt.Println("Book Added.")

		case 2:
			fmt.Println("Books in Library:")
			for i := 0; i < count; i++ {
				fmt.Printf("ID: %d | Title: %s | Author: %s\n", ids[i], titles[i], authors[i])
			}

		case 3:
			fmt.Print("Enter title to search: ")
			query, _ := reader.ReadString('\n')
			query = strings.TrimSpace(query)
			found := false
			for i := 0; i < count; i++ {
				if strings.EqualFold(titles[i], query) {
					fmt.Printf("Found: ID=%d, Title=%s, Author=%s\n", ids[i], titles[i], authors[i])
					found = true
					break
				}
			}
			if !found {
				fmt.Println("Book not found.")
			}

		case 4:
			fmt.Print("Enter ID to delete: ")
			var delID int
			fmt.Scanln(&delID)
			index := -1
			for i := 0; i < count; i++ {
				if ids[i] == delID {
					index = i
					break
				}
			}
			if index == -1 {
				fmt.Println("Book ID not found.")
			} else {
				for i := index; i < count-1; i++ {
					ids[i] = ids[i+1]
					titles[i] = titles[i+1]
					authors[i] = authors[i+1]
				}
				count--
				fmt.Println("Book deleted.")
			}

		case 5:
			fmt.Println("Goodbye!")
			return
		default:
			fmt.Println("Invalid choice.")
		}
	}
}
