#include <iostream>
using namespace std;

int main()
{
    int bedStatus[3][3][4] = {
        {
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {1, 1, 0, 0}
        },
        {
            {0, 0, 1, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0}
        },
        {
            {1, 0, 0, 1},
            {0, 1, 0, 0},
            {1, 1, 1, 0}
        }
    };

    int totalOccupied = 0;
    int occupiedByFloor[3] = {0, 0, 0};

    int selectedFloor, selectedWard, selectedBed;

    for (int floorIndex = 0; floorIndex < 3; floorIndex++)
    {
        cout << "Floor " << floorIndex + 1 << ":\n";

        for (int wardIndex = 0; wardIndex < 3; wardIndex++)
        {
            for (int bedIndex = 0; bedIndex < 4; bedIndex++)
            {
                cout << bedStatus[floorIndex][wardIndex][bedIndex] << " ";

                if (bedStatus[floorIndex][wardIndex][bedIndex] == 1)
                {
                    totalOccupied++;
                    occupiedByFloor[floorIndex]++;
                }
            }

            cout << endl;
        }
    }

    cout << "Total Occupied Beds = " << totalOccupied << endl;
    cout << "Total Available Beds = " << 36 - totalOccupied << endl;

    for (int floorIndex = 0; floorIndex < 3; floorIndex++)
    {
        cout << "Occupied beds on Floor "
             << floorIndex + 1 << " = "
             << occupiedByFloor[floorIndex] << endl;
    }

    cout << "Enter floor (1-3): ";
    cin >> selectedFloor;

    cout << "Enter ward (1-3): ";
    cin >> selectedWard;

    cout << "Enter bed (1-4): ";
    cin >> selectedBed;

    if (bedStatus[selectedFloor - 1][selectedWard - 1][selectedBed - 1] == 0)
    {
        cout << "Selected bed is available";
    }
    else
    {
        cout << "Selected bed is occupied";
    }

    return 0;
}

