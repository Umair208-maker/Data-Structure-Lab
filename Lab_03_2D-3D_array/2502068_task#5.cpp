#include <iostream>
using namespace std;

int main()
{
    int computerStatus[2][3][5] = {
        {
            {1, 0, 1, 0, 1},
            {0, 1, 0, 1, 0},
            {1, 1, 0, 0, 1}
        },
        {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 0, 1, 0, 1}
        }
    };

    int totalAvailable = 0;
    int totalInUse = 0;
    int availableByLab[2] = {0, 0};

    int selectedLab, selectedRow, selectedComputer;

    for (int labIndex = 0; labIndex < 2; labIndex++)
    {
        cout << "Lab " << labIndex + 1 << ":\n";

        for (int rowIndex = 0; rowIndex < 3; rowIndex++)
        {
            for (int computerIndex = 0; computerIndex < 5; computerIndex++)
            {
                cout << computerStatus[labIndex][rowIndex][computerIndex] << " ";

                if (computerStatus[labIndex][rowIndex][computerIndex] == 0)
                {
                    totalAvailable++;
                    availableByLab[labIndex]++;
                }
                else
                {
                    totalInUse++;
                }
            }

            cout << endl;
        }
    }

    cout << "Total Available Computers = "
         << totalAvailable << endl;

    cout << "Total Computers In Use = "
         << totalInUse << endl;

    for (int labIndex = 0; labIndex < 2; labIndex++)
    {
        cout << "Available computers in Lab "
             << labIndex + 1 << " = "
             << availableByLab[labIndex] << endl;
    }

    cout << "Enter lab (1-2): ";
    cin >> selectedLab;

    cout << "Enter row (1-3): ";
    cin >> selectedRow;

    cout << "Enter computer (1-5): ";
    cin >> selectedComputer;

    if (computerStatus[selectedLab - 1][selectedRow - 1][selectedComputer - 1] == 0)
    {
        cout << "Selected computer is available";
    }
    else
    {
        cout << "Selected computer is in use";
    }

    return 0;
}

