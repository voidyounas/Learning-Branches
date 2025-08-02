#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student
{
    string name;
    int roll;
    float marks[5];
    float average;
    char grade;
};

void calculateGrade(Student &s)
{
    float sum = 0;
    for (int i = 0; i < 5; i++)
        sum += s.marks[i];
    s.average = sum / 5.0;

    if (s.average >= 90)
        s.grade = 'A';
    else if (s.average >= 80)
        s.grade = 'B';
    else if (s.average >= 70)
        s.grade = 'C';
    else if (s.average >= 60)
        s.grade = 'D';
    else
        s.grade = 'F';
}

void addStudent(Student students[], int &count)
{
    if (count >= MAX_STUDENTS)
    {
        cout << "Limit reached.\n";
        return;
    }

    Student s;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter roll number: ";
    cin >> s.roll;
    cout << "Enter marks in 5 subjects:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Subject " << i + 1 << ": ";
        cin >> s.marks[i];
    }

    calculateGrade(s);
    students[count++] = s;

    cout << "Student added.\n";
}

void displayAll(const Student students[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "\nName: " << students[i].name
             << "\nRoll: " << students[i].roll
             << "\nAverage: " << students[i].average
             << "\nGrade: " << students[i].grade << "\n";
    }
}

void saveToFile(const Student students[], int count)
{
    ofstream file("students.txt");
    for (int i = 0; i < count; i++)
    {
        file << students[i].name << "\n"
             << students[i].roll << "\n";
        for (int j = 0; j < 5; j++)
        {
            file << students[i].marks[j] << " ";
        }
        file << "\n"
             << students[i].average << "\n"
             << students[i].grade << "\n";
    }
    file.close();
    cout << "Data saved to file.\n";
}

void loadFromFile(Student students[], int &count)
{
    ifstream file("students.txt");
    count = 0;
    while (!file.eof())
    {
        Student s;
        getline(file, s.name);
        if (s.name.empty())
            break;
        file >> s.roll;
        for (int i = 0; i < 5; i++)
        {
            file >> s.marks[i];
        }
        file >> s.average >> s.grade;
        file.ignore();
        students[count++] = s;
    }
    file.close();
    cout << "Data loaded from file.\n";
}

int main()
{
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do
    {
        cout << "\n1. Add Student\n2. Display All\n3. Save to File\n4. Load from File\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent(students, count);
            break;
        case 2:
            displayAll(students, count);
            break;
        case 3:
            saveToFile(students, count);
            break;
        case 4:
            loadFromFile(students, count);
            break;
        case 0:
            break;
        default:
            cout << "Invalid.\n";
        }

    } while (choice != 0);

    return 0;
}
