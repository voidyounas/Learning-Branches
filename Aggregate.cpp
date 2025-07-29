#include <iostream>
using namespace std;

int main()
{
    float subject1, subject2, subject3;
    float totalMarks, percentage;

    cout << "Enter marks for Subject 1: ";
    cin >> subject1;
    cout << "Enter marks for Subject 2: ";
    cin >> subject2;
    cout << "Enter marks for Subject 3: ";
    cin >> subject3;

    totalMarks = subject1 + subject2 + subject3;
    percentage = (totalMarks / 300.0) * 100;

    cout << "Total Marks: " << totalMarks << endl;
    cout << "Percentage: " << percentage << "%" << endl;

    if (percentage >= 85)
        cout << "Grade: A" << endl;
    else if (percentage >= 70)
        cout << "Grade: B" << endl;
    else if (percentage >= 60)
        cout << "Grade: C" << endl;
    else if (percentage >= 50)
        cout << "Grade: D" << endl;
    else
        cout << "Grade: F" << endl;

    return 0;
}
