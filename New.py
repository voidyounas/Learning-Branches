todo_list = []

def show_menu():
    print("\nTO-DO LIST MENU")
    print("1. Add Task")
    print("2. View Tasks")
    print("3. Mark Task as Done")
    print("4. Delete Task")
    print("5. Exit")

def add_task():
    task = input("Enter a new task: ")
    todo_list.append({"task": task, "done": False})
    print(f"Task added: {task}")

def view_tasks():
    if not todo_list:
        print("No tasks in the list.")
        return
    print("\nYour Tasks:")
    for i, t in enumerate(todo_list, 1):
        status = "Done" if t["done"] else "Pending"
        print(f"{i}. {t['task']} [{status}]")

def mark_done():
    view_tasks()
    if not todo_list:
        return
    try:
        idx = int(input("Enter task number to mark as done: "))
        todo_list[idx - 1]["done"] = True
        print(f"Marked task {idx} as done.")
    except (ValueError, IndexError):
        print("Invalid task number.")

def delete_task():
    view_tasks()
    if not todo_list:
        return
    try:
        idx = int(input("Enter task number to delete: "))
        removed = todo_list.pop(idx - 1)
        print(f"Deleted task: {removed['task']}")
    except (ValueError, IndexError):
        print("Invalid task number.")

while True:
    show_menu()
    choice = input("Choose an option (1-5): ")

    if choice == "1":
        add_task()
    elif choice == "2":
        view_tasks()
    elif choice == "3":
        mark_done()
    elif choice == "4":
        delete_task()
    elif choice == "5":
        print("Exiting To-Do List.")
        break
    else:
        print("Invalid option. Try again.")
