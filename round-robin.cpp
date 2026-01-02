#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int arrival[n], burst[n], remaining[n];
    int waiting[n], turnaround[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time for P" << i + 1 << ": ";
        cin >> arrival[i];

        cout << "Enter Burst Time for P" << i + 1 << ": ";
        cin >> burst[i];

        remaining[i] = burst[i];
    }

    int quantum;
    cout << "Enter Time Quantum: ";
    cin >> quantum;

    int time = 0;
    bool done;

    // Gantt Chart
    cout << "\nGantt Chart:\n| ";

    // Round Robin Scheduling
    while (true) {
        done = true;

        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0) {
                done = false;

                cout << "P" << i + 1 << " | ";

                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    waiting[i] = time - arrival[i] - burst[i];
                    remaining[i] = 0;
                }
            }
        }

        if (done)
            break;
    }

    // Calculations
    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];
        totalWT += waiting[i];
        totalTAT += turnaround[i];
    }

    // Output Table
    cout << "\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << arrival[i] << "\t\t"
             << burst[i] << "\t\t"
             << waiting[i] << "\t\t"
             << turnaround[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << endl;

    return 0;
}//
// Created by Hp on 1/2/2026.
//
