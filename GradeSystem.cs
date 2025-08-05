using System;
using System.Collections.Generic;

class Student
{
    public string Name;
    public int[] Marks = new int[3];
    public int Total;
    public double Average;
    public char Grade;

    public void CalculateResults()
    {
        Total = Marks[0] + Marks[1] + Marks[2];
        Average = Total / 3.0;

        if (Average >= 90)
            Grade = 'A';
        else if (Average >= 80)
            Grade = 'B';
        else if (Average >= 70)
            Grade = 'C';
        else if (Average >= 60)
            Grade = 'D';
        else
            Grade = 'F';
    }

    public void Display()
    {
        Console.WriteLine($"\nName     : {Name}");
        Console.WriteLine($"Total    : {Total}");
        Console.WriteLine($"Average  : {Average:F2}");
        Console.WriteLine($"Grade    : {Grade}");
    }
}

class Program
{
    static List<Student> students = new List<Student>();

    static void Main(string[] args)
    {
        int choice;

        do
        {
            Console.WriteLine("\n===== Student Grade Management System =====");
            Console.WriteLine("1. Add Student");
            Console.WriteLine("2. Show All Students");
            Console.WriteLine("3. Exit");
            Console.Write("Choose an option: ");
            choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    AddStudent();
                    break;
                case 2:
                    ShowAllStudents();
                    break;
                case 3:
                    Console.WriteLine("Exiting program...");
                    break;
                default:
                    Console.WriteLine("Invalid option. Try again.");
                    break;
            }
        } while (choice != 3);
    }

    static void AddStudent()
    {
        Student student = new Student();

        Console.Write("\nEnter Student Name: ");
        student.Name = Console.ReadLine();

        for (int i = 0; i < 3; i++)
        {
            Console.Write($"Enter marks for Subject {i + 1}: ");
            student.Marks[i] = Convert.ToInt32(Console.ReadLine());
        }

        student.CalculateResults();
        students.Add(student);

        Console.WriteLine("Student added successfully!");
    }

    static void ShowAllStudents()
    {
        if (students.Count == 0)
        {
            Console.WriteLine("No students to display.");
            return;
        }

        Console.WriteLine("\n=== Student Reports ===");
        foreach (Student s in students)
        {
            s.Display();
        }
    }
}
