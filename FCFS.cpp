#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "How many processes? ";
    cin >> n;

    string pname[n];
    int at[n], bt[n], wt[n], tat[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter Process Name, Arrival Time, and Burst Time for P"
             << i + 1 << ": ";
        cin >> pname[i] >> at[i] >> bt[i];
    }

    // Sorting by Arrival Time (FCFS)
    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - a - 1; b++) {
            if (at[b] > at[b + 1]) {
                swap(at[b], at[b + 1]);
                swap(bt[b], bt[b + 1]);
                swap(pname[b], pname[b + 1]);
            }
        }
    }

    int time = 0;
    float sumWT = 0, sumTAT = 0;

    // Waiting Time & Turnaround Time Calculation
    for (int i = 0; i < n; i++) {
        if (time < at[i]) {
            time = at[i];
        }

        wt[i] = time - at[i];
        tat[i] = wt[i] + bt[i];

        sumWT += wt[i];
        sumTAT += tat[i];

        time += bt[i];
    }

    // Output Table
    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << pname[i] << "\t"
             << at[i] << "\t\t"
             << bt[i] << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << (sumWT / n);
    cout << "\nAverage Turnaround Time: " << (sumTAT / n) << endl;

    // Gantt Chart
    cout << "\nGantt Chart:\n| ";

    time = 0;
    for (int i = 0; i < n; i++) {
        if (time < at[i]) {
            cout << "Idle | ";
            time = at[i];
        }
        cout << pname[i] << " | ";
        time += bt[i];
    }
    cout << endl;

    return 0;
}