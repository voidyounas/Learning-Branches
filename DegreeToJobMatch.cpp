#include <iostream>
#include <string>
using namespace std;

const int MAX_QUESTIONS = 15;

void toLowerCase(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
}

void displayInstructions()
{
    cout << "Degree-to-Job Match Quiz\n";
    cout << "Answer with 'yes' if the job matches the degree, 'no' if it does not.\n";
    cout << "----------------------------\n";
}

void loadQuestions(string degrees[], string jobs[], string correctAnswers[], int &size)
{
    degrees[0] = "Computer Science";
    jobs[0] = "Software Engineer";
    correctAnswers[0] = "yes";
    degrees[1] = "English Literature";
    jobs[1] = "Data Scientist";
    correctAnswers[1] = "no";
    degrees[2] = "Mechanical Engineering";
    jobs[2] = "Automobile Designer";
    correctAnswers[2] = "yes";
    degrees[3] = "Business Administration";
    jobs[3] = "Graphic Designer";
    correctAnswers[3] = "no";
    degrees[4] = "Medicine";
    jobs[4] = "Surgeon";
    correctAnswers[4] = "yes";
    degrees[5] = "Physics";
    jobs[5] = "Astronomer";
    correctAnswers[5] = "yes";
    degrees[6] = "Fine Arts";
    jobs[6] = "Web Developer";
    correctAnswers[6] = "no";
    degrees[7] = "Psychology";
    jobs[7] = "Therapist";
    correctAnswers[7] = "yes";
    degrees[8] = "Political Science";
    jobs[8] = "Policy Analyst";
    correctAnswers[8] = "yes";
    degrees[9] = "Civil Engineering";
    jobs[9] = "Bridge Designer";
    correctAnswers[9] = "yes";
    degrees[10] = "Accounting";
    jobs[10] = "Tax Consultant";
    correctAnswers[10] = "yes";
    degrees[11] = "History";
    jobs[11] = "Backend Developer";
    correctAnswers[11] = "no";
    degrees[12] = "Computer Science";
    jobs[12] = "Cybersecurity Analyst";
    correctAnswers[12] = "yes";
    degrees[13] = "Economics";
    jobs[13] = "Data Analyst";
    correctAnswers[13] = "yes";
    degrees[14] = "English Literature";
    jobs[14] = "Technical Writer";
    correctAnswers[14] = "yes";

    size = 15;
}

int runQuiz(string degrees[], string jobs[], string correctAnswers[], int size)
{
    string userAnswer;
    int score = 0;

    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << degrees[i] << " -> " << jobs[i] << ": ";
        cin >> userAnswer;
        toLowerCase(userAnswer);
        if (userAnswer == correctAnswers[i])
        {
            score++;
        }
    }

    return score;
}

void displayResults(int score, int total)
{
    double percent = (double)score / total * 100.0;
    cout << "\nYour Score: " << score << "/" << total << endl;
    cout << "Percentage: " << percent << "%\n";

    if (percent == 100)
        cout << "Outstanding performance!\n";
    else if (percent >= 80)
        cout << "Great job!\n";
    else if (percent >= 60)
        cout << "Good effort.\n";
    else
        cout << "Needs improvement.\n";
}

int main()
{
    string degrees[MAX_QUESTIONS], jobs[MAX_QUESTIONS], correctAnswers[MAX_QUESTIONS];
    int totalQuestions;
    char playAgain;

    do
    {
        loadQuestions(degrees, jobs, correctAnswers, totalQuestions);
        displayInstructions();
        int score = runQuiz(degrees, jobs, correctAnswers, totalQuestions);
        displayResults(score, totalQuestions);

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
        cout << "----------------------------\n";
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
