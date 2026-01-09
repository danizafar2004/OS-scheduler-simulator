#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    string pid[20];
    int arrival[20], burst[20];
    int start[20], finish[20], waiting[20], tat[20];
    int done[20] = {0};

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Process ID: ";
        cin >> pid[i];
        cout << "Arrival Time: ";
        cin >> arrival[i];
        cout << "Burst Time: ";
        cin >> burst[i];
    }

    int completed = 0;
    int time = 0;

    // jump to earliest arrival time
    int minArrival = arrival[0];
    for (int i = 1; i < n; i++) {
        if (arrival[i] < minArrival)
            minArrival = arrival[i];
    }
    time = minArrival;

    cout << "\nGantt Chart: ";

    while (completed < n) {
        int idx = -1;
        int bestBurst = 99999;

        // choose shortest job among arrived processes
        for (int i = 0; i < n; i++) {
            if (done[i] == 0 && arrival[i] <= time) {
                if (burst[i] < bestBurst) {
                    bestBurst = burst[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        start[idx] = time;
        time += burst[idx];
        finish[idx] = time;
        waiting[idx] = start[idx] - arrival[idx];
        tat[idx] = finish[idx] - arrival[idx];

        done[idx] = 1;
        completed++;

        cout << "| " << pid[idx] << " ";
    }
    cout << "|\n";

    double wsum = 0, tsum = 0;
    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t"
             << arrival[i] << "\t"
             << burst[i] << "\t"
             << waiting[i] << "\t"
             << tat[i] << endl;
        wsum += waiting[i];
        tsum += tat[i];
    }

    cout << "\nAverage Waiting Time: " << wsum / n;
    cout << "\nAverage Turnaround Time: " << tsum / n;

    return 0;
}
