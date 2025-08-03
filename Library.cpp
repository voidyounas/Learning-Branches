#include <iostream>
#include <string>
using namespace std;

int main()
{
    string titles[100], authors[100];
    int ids[100], count = 0;

    while (true)
    {
        int choice;
        cout << "\n--- Library Inventory ---\n";
        cout << "1. Add Book\n2. View Books\n3. Search by Title\n4. Delete by ID\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            if (count >= 100)
            {
                cout << "Inventory Full.\n";
                break;
            }
            cout << "Enter Book ID: ";
            cin >> ids[count];
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, titles[count]);
            cout << "Enter Author: ";
            getline(cin, authors[count]);
            count++;
            cout << "Book Added.\n";
            break;
        case 2:
            for (int i = 0; i < count; i++)
            {
                cout << "ID: " << ids[i] << " | Title: " << titles[i]
                     << " | Author: " << authors[i] << endl;
            }
            break;
        case 3:
        {
            string search;
            cout << "Enter title to search: ";
            getline(cin, search);
            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (titles[i] == search)
                {
                    cout << "Found: ID=" << ids[i] << ", Title=" << titles[i]
                         << ", Author=" << authors[i] << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found.\n";
            break;
        }
        case 4:
        {
            int delID, index = -1;
            cout << "Enter ID to delete: ";
            cin >> delID;
            for (int i = 0; i < count; i++)
            {
                if (ids[i] == delID)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
                cout << "Book ID not found.\n";
            else
            {
                for (int i = index; i < count - 1; i++)
                {
                    ids[i] = ids[i + 1];
                    titles[i] = titles[i + 1];
                    authors[i] = authors[i + 1];
                }
                count--;
                cout << "Book deleted.\n";
            }
            break;
        }
        case 5:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
