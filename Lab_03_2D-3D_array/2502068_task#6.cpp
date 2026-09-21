#include <iostream>
using namespace std;

int main()
{
    int numbers[2][2][2] = {
        {
            {10, 20},
            {30, 40}
        },
        {
            {50, 60},
            {70, 80}
        }
    };

    int searchValue;
    bool isFound = false;

    cout << "3D Array:\n";

    for (int layerIndex = 0; layerIndex < 2; layerIndex++)
    {
        cout << "Layer " << layerIndex + 1 << ":\n";

        for (int rowIndex = 0; rowIndex < 2; rowIndex++)
        {
            for (int columnIndex = 0; columnIndex < 2; columnIndex++)
            {
                cout << numbers[layerIndex][rowIndex][columnIndex] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

    cout << "Searching for: ";
    cin >> searchValue;

    for (int layerIndex = 0; layerIndex < 2; layerIndex++)
    {
        for (int rowIndex = 0; rowIndex < 2; rowIndex++)
        {
            for (int columnIndex = 0; columnIndex < 2; columnIndex++)
            {
                if (numbers[layerIndex][rowIndex][columnIndex] == searchValue)
                {
                    cout << "\nElement found!\n";
                    cout << "Layer: " << layerIndex + 1 << endl;
                    cout << "Row: " << rowIndex + 1 << endl;
                    cout << "Column: " << columnIndex + 1 << endl;

                    isFound = true;
                }
            }
        }
    }

    if (!isFound)
    {
        cout << "Element not found";
    }

    return 0;
}

