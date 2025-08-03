#include <stdio.h>
#include <string.h>

int main()
{
    int ids[100], count = 0;
    char titles[100][100], authors[100][100];

    while (1)
    {
        int choice;
        printf("\n--- Library Inventory ---\n");
        printf("1. Add Book\n2. View Books\n3. Search by Title\n4. Delete by ID\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice)
        {
        case 1:
            if (count >= 100)
            {
                printf("Inventory Full.\n");
                break;
            }
            printf("Enter Book ID: ");
            scanf("%d", &ids[count]);
            getchar();
            printf("Enter Book Title: ");
            fgets(titles[count], 100, stdin);
            titles[count][strcspn(titles[count], "\n")] = '\0';

            printf("Enter Author: ");
            fgets(authors[count], 100, stdin);
            authors[count][strcspn(authors[count], "\n")] = '\0';

            count++;
            printf("Book Added.\n");
            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                printf("ID: %d | Title: %s | Author: %s\n", ids[i], titles[i], authors[i]);
            }
            break;

        case 3:
        {
            char search[100];
            int found = 0;
            printf("Enter title to search: ");
            fgets(search, 100, stdin);
            search[strcspn(search, "\n")] = '\0';

            for (int i = 0; i < count; i++)
            {
                if (strcmp(titles[i], search) == 0)
                {
                    printf("Found: ID=%d | Title=%s | Author=%s\n", ids[i], titles[i], authors[i]);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Book not found.\n");
            break;
        }

        case 4:
        {
            int delID, index = -1;
            printf("Enter ID to delete: ");
            scanf("%d", &delID);
            for (int i = 0; i < count; i++)
            {
                if (ids[i] == delID)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
            {
                printf("Book ID not found.\n");
            }
            else
            {
                for (int i = index; i < count - 1; i++)
                {
                    ids[i] = ids[i + 1];
                    strcpy(titles[i], titles[i + 1]);
                    strcpy(authors[i], authors[i + 1]);
                }
                count--;
                printf("Book deleted.\n");
            }
            break;
        }

        case 5:
            printf("Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
