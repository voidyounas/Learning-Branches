package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
)

type Task struct {
	Title     string `json:"title"`
	Completed bool   `json:"completed"`
}

var tasks []Task

const fileName = "tasks.json"

func main() {
	loadTasks()
	scanner := bufio.NewScanner(os.Stdin)

	for {
		fmt.Println("\n1. Add Task\n2. View Tasks\n3. Complete Task\n4. Delete Task\n5. Exit")
		fmt.Print("Choose: ")
		scanner.Scan()
		choice := scanner.Text()

		switch choice {
		case "1":
			fmt.Print("Enter task: ")
			scanner.Scan()
			title := scanner.Text()
			tasks = append(tasks, Task{Title: title})
			saveTasks()
		case "2":
			fmt.Println("\nYour Tasks:")
			for i, t := range tasks {
				status := "Not Done"
				if t.Completed {
					status = "Done"
				}
				fmt.Printf("%d. %s [%s]\n", i+1, t.Title, status)
			}
		case "3":
			fmt.Print("Enter task number to mark complete: ")
			scanner.Scan()
			var num int
			fmt.Sscanf(scanner.Text(), "%d", &num)
			if num >= 1 && num <= len(tasks) {
				tasks[num-1].Completed = true
				saveTasks()
			}
		case "4":
			fmt.Print("Enter task number to delete: ")
			scanner.Scan()
			var num int
			fmt.Sscanf(scanner.Text(), "%d", &num)
			if num >= 1 && num <= len(tasks) {
				tasks = append(tasks[:num-1], tasks[num:]...)
				saveTasks()
			}
		case "5":
			return
		default:
			fmt.Println("Invalid choice")
		}
	}
}

func saveTasks() {
	file, _ := os.Create(fileName)
	defer file.Close()
	json.NewEncoder(file).Encode(tasks)
}

func loadTasks() {
	file, err := os.Open(fileName)
	if err != nil {
		return
	}
	defer file.Close()
	json.NewDecoder(file).Decode(&tasks)
}
