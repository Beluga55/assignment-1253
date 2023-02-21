#include <iostream>
#include <string>
#include <ios>
#include <limits>
using namespace std;

void read_and_check_categories(int *);
void determine_distance(int, string *, string[]);
void read_and_check_types(int *);
void read_and_check_participants(int *);
void find_the_fees(int, int, int *, int[]);
void calc_sum_and_print(int *, int, int);
void print_category_distance_types(int, string, int, int);

// Categories Array
const string categories[] = {
    " ",
    "10km Men Open",
    "10km Women Open",
    "5km Men Open",
    "5km Women Open",
    "5km Family Fun Run Malaysian (2 Adults + 2 Kids 4 Years & above)"};

// Distance Array
const string distances[] = {"10km", "5km"};

// Types Array
const string types[] = {"", "Early Bird", "Normal"};

// Fees Array
const int fees[] = {60, 70, 60, 70, 50, 60, 50, 60, 200, 240};

// Print Out Categories
void read_and_check_categories(int *category)
{
    cout << endl;
    cout << "===== SUNWAY GOOD RUN 2023 =====" << endl;
    cout << endl;

    for (int i = 1; i <= 5; i++)
    {
        cout << "Category " << i << ": " << categories[i] << endl;
    }

    cout << "Enter Category (1 To 5 Only): ";
    cin >> *category;

    do
    {
        if (*category >= 1 && *category <= 5)
        {
            return;
        }

        cout << endl;
        cout << "Please Input A Valid Number !!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please Enter The Number Again: ";
        cin >> *category;

    } while (*category < 1 || *category > 5);
}

// Determine The Distance By The First Input
void determine_distance(int category, string *distance, const string distances[])
{
    if (category == 1 || category == 2)
    {
        *distance = distances[0];
    }

    if (category == 3 || category == 4 || category == 5)
    {
        *distance = distances[1];
    }
}

// Print Out Types
void read_and_check_types(int *type)
{
    cout << endl;
    for (int i = 1; i <= 2; i++)
    {
        cout << types[i] << ": " << i << endl;
    }

    // Get the type from the user
    cout << "Enter a number to select Early Bird or Normal: ";
    cin >> *type;

    do
    {
        if (*type >= 1 && *type <= 2)
        {
            return;
        }

        cout << endl;
        cout << "Please Input A Valid Number !!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please Enter The Number Again: ";
        cin >> *type;

    } while (*type < 1 || *type > 2);
}

// Enter Number Of Participants (Input)
void read_and_check_participants(int *participants)
{
    cout << "Enter Number Of Participants: ";
    cin >> *participants;

    while (!cin || *participants < 1)
    {
        cout << endl;
        cout << "Please Input A Valid Number !!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please Enter The Number Again: ";
        cin >> *participants;
    }

    if (cin)
    {
        return;
    }
}

// Determine The Fees Based On First Input And Second Input
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

// Calculate Sum
void calc_sum_and_print(int *sum, int fee, int number_of_participants)
{
    *sum = fee * number_of_participants;
    cout << "The Total Amount Is: "
         << "RM " << *sum << endl;
    cout << endl;
}

// Show It To The Output
void print_category_distance_types(int category, string distance, int type, int participants)
{
    cout << endl;
    cout << "Category: " << categories[category] << endl;
    cout << "Distance: " << distance << endl;
    cout << "Types: " << type[types] << endl;
    cout << "Number Of Participants: " << participants << endl;
}

int main(void)
{
    int category, type, participants, fee, sum;
    string distance;
    read_and_check_categories(&category);
    determine_distance(category, &distance, distances);
    read_and_check_types(&type);
    read_and_check_participants(&participants);
    find_the_fees(category, type, &fee, fees);
    print_category_distance_types(category, distance, type, participants);
    calc_sum_and_print(&sum, fee, participants);
    return 0;
}