#include <iostream>
#include <string>
using namespace std;

void print_categories(int *);
void print_types(int *);
void read_number_of_participants(int *);
void find_the_fees(int, int, int *, int[]);
void calc_sum_and_print(int *, int, int);

// Define The Categories And Their Names
const string categories[] = {
    " ",
    "10km Men Open",
    "10km Women Open",
    "5km Men Open",
    "5km Women Open",
    "5km Family Fun Run Malaysian (2 Adults + 2 Kids 4 Years & above)"};

// Define The Types And Their Names
const string types[] = {"", "Early Bird", "Normal"};

// Define The Fees For Each Category
const int fees[] = {60, 70, 60, 70, 50, 60, 50, 60, 200, 240};

void print_categories(int *category)
{
    // Print Out The Categories
    for (int i = 1; i <= 5; i++)
    {
        cout << "Category " << i << ": " << categories[i] << endl;
    }

    cout << "Enter A Number To Select Category (Only 1 To 5): ";
    cin >> *category;
    cout << endl;

    // Check If The Category Is Valid
    while (*category < 1 || *category > 5)
    {
        cout << endl;
        cout << "NOTE: Please input number between 1 to 5 only" << endl;
        cout << endl;

        // Print Out The Categories
        for (int i = 1; i <= 5; i++)
        {
            cout << "Category " << i << ": " << categories[i] << endl;
        }

        cout << "Enter A Number To Select Category (Only 1 To 5): ";
        cin >> *category;
        cout << endl;
    }
}

void print_types(int *type)
{
    // Print Out The Types
    for (int i = 1; i <= 2; i++)
    {
        cout << types[i] << ": " << i << endl;
    }

    // Get the type from the user
    cout << "Enter a number to select Early Bird or Normal: ";
    cin >> *type;
    cout << endl;

    while (*type < 1 || *type > 2)
    {
        cout << endl;
        cout << "NOTE: Please input number between 1 to 2 only" << endl;
        cout << endl;

        // Print Out The Types
        for (int i = 1; i <= 2; i++)
        {
            cout << types[i] << ": " << i << endl;
        }

        // Get the type from the user
        cout << "Enter a number to select Early Bird or Normal: ";
        cin >> *type;
        cout << endl;
    }
}

void read_number_of_participants(int *number_of_participants)
{
    cout << "Enter Number Of Participants: ";
    cin >> *number_of_participants;
}

void find_the_fees(int category, int type, int *fee, const int fees[])
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            if (category == i && type == j)
            {
                int fee_index = (category - 1) * 2 + (type - 1);
                *fee = fees[fee_index];
            }
        }
    }
}

void calc_sum_and_print(int *sum, int fee, int number_of_participants)
{
    *sum = fee * number_of_participants;
    cout << "The Total Amount Is: " << *sum << endl;
}

int main(void)
{
    int category, type, number_of_participants, fee, sum;
    print_categories(&category);
    print_types(&type);
    read_number_of_participants(&number_of_participants);
    find_the_fees(category, type, &fee, fees);
    calc_sum_and_print(&sum, fee, number_of_participants);
}