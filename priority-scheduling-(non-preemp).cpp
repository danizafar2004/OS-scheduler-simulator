#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0 || n > 20) {
        cout << "Number of processes must be between 1 and 20\n";
        return 0;
    }

    string pid[20];
    int arrival[20], burst[20], priority[20];
    int start[20], finish[20], waiting[20], tat[20];
    bool done[20] = {false};

    for (int i = 0; i < n; i++) {
        cout << "\nProcess " << i + 1 << endl;
        cout << "Process ID: ";
        cin >> pid[i];
        cout << "Arrival Time: ";
        cin >> arrival[i];
        cout << "Burst Time: ";
        cin >> burst[i];
        cout << "Priority (lower number = higher priority): ";
        cin >> priority[i];
    }

    int completed = 0;
    int time = 0;

    // start from earliest arrival
    int minArrival = arrival[0];
    for (int i = 1; i < n; i++)
        if (arrival[i] < minArrival)
            minArrival = arrival[i];

    time = minArrival;

    cout << "\nGantt Chart:\n";
    cout << time;

    while (completed < n) {
        int idx = -1;
        int bestPriority = 99999;

        // select highest priority available process
        for (int i = 0; i < n; i++) {
            if (!done[i] && arrival[i] <= time) {
                if (priority[i] < bestPriority) {
                    bestPriority = priority[i];
                    idx = i;
                }
                // tie-breaking: earlier arrival
                else if (priority[i] == bestPriority &&
                         arrival[i] < arrival[idx]) {
                    idx = i;
                }
            }
        }

        // CPU Idle
        if (idx == -1) {
            cout << " --IDLE-- " << time + 1;
            time++;
            continue;
        }

        // Execute process completely (NON-PREEMPTIVE)
        start[idx] = time;
        time += burst[idx];
        finish[idx] = time;
        waiting[idx] = start[idx] - arrival[idx];
        tat[idx] = finish[idx] - arrival[idx];

        done[idx] = true;
        completed++;

        cout << " --" << pid[idx] << "-- " << time;
    }

    cout << "\n\nProcess Details:\n";
    cout << "PID\tAT\tBT\tP\tWT\tTAT\n";

    double totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t"
             << arrival[i] << "\t"
             << burst[i] << "\t"
             << priority[i] << "\t"
             << waiting[i] << "\t"
             << tat[i] << endl;

        totalWT += waiting[i];
        totalTAT += tat[i];
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = " << totalWT / n;
    cout << "\nAverage Turnaround Time = " << totalTAT / n << endl;

    return 0;
}
