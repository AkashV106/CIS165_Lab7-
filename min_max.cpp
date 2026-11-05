#include <iostream>
using namespace std;

const int MAX_ENTRIES = 10000;
const int SENTINEL = -99;

int main()
{
    int values[MAX_ENTRIES];
    int count = 0;
    int number = 0;
    int largest = 0;
    int smallest = 0;

    cout << "Enter an integer (-99 to stop): ";
    cin >> number;

    if (number == SENTINEL)
    {
        cout << "No data values were entered." << endl;
    }
    else
    {
        
        largest = number;
        smallest = number;

        
        while (number != SENTINEL && count < MAX_ENTRIES)
        {
            values[count] = number;
            count++;

            if (number > largest)
            {
                largest = number;
            }
            if (number < smallest)
            {
                smallest = number;
            }

            if (count < MAX_ENTRIES)
            {
                cout << "Enter an integer (-99 to stop): ";
                cin >> number;
            }
        }

        cout << "Values entered: ";
        for (int index = 0; index < count; index++)
        {
            cout << values[index] << " ";
        }
        cout << endl;

        cout << "Largest value: " << largest;
        cout << " Smallest value: " << smallest << endl;
    }

    return 0;
}
