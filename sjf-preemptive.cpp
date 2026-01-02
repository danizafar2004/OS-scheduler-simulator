#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int at[10], bt[10], rt[10], wt[10] = {0}, tat[10] = {0};
    int complete = 0, time = 0, shortest;
    bool done[10] = {false};
    // input
    for(int i = 0; i < n; i++) {
        cout << "Arrival & Burst time for P" << i+1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i]; // remaining time
    }
    cout << "\nGantt Chart: ";
    while(complete != n) {
        shortest = -1;
        int minBurst = 999;
        // it will find the process with shortest remaining time that has arrived
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && !done[i] && rt[i] < minBurst) {
                minBurst = rt[i];
                shortest = i;
            }
        }
        if(shortest == -1) {
            time++;
        }
        else {
            cout << "P" << shortest+1 << " ";
            rt[shortest]--;
            time++;
            if(rt[shortest] == 0) {
                complete++;

                done[shortest] = true;
                tat[shortest] = time - at[shortest];
                wt[shortest] = tat[shortest] - bt[shortest];
            }
        }
    }
    // printing the table
    cout << "\n\nProcess AT BT WT TAT\n";
    float avgwt = 0, avgtat = 0;
    for(int i = 0; i < n; i++) {
        cout << " P" << i+1 << " " << at[i] << " " << bt[i]
        << " " << wt[i] << " " << tat[i] << endl;
        avgwt += wt[i];
        avgtat += tat[i];
    }
    cout << "\nAverage Waiting Time = " << avgwt/n << endl;
    cout << "Average Turnaround Time = " << avgtat/n << endl;
    return 0;
}