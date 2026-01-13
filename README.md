# OS-scheduler-simulator
Operating systems project 
Process Scheduling Simulator
Operating Systems Project - Fall 2025

Project Overview
This project is a simulation system designed to efficiently manage and organize multiple processes for optimal CPU utilization. The simulator demonstrates how different scheduling algorithms perform under varying dynamic workloads.


Team Members:
Laiba Abubakr 

Muhammad Danish Zafar 

Muhammad Zaid

Mian Ali Maqsood

Faris khan

Features & Algorithms
The simulator implements the following CPU scheduling algorithms to evaluate system performance:


First-Come, First-Served (FCFS): A non-preemptive algorithm that processes tasks in order of arrival.


Shortest Job First (SJF): Selects the process with the smallest execution time to minimize waiting time.


Priority Scheduling: Assigns CPU time based on process importance.


Round Robin (RR): Provides fairness by using time-quanta for process switching.

Key Performance Metrics
To analyze the effectiveness of each algorithm, the system calculates and compares the following:



Turnaround Time: Total time taken from process submission to completion.


Waiting Time: Total time a process spends in the ready queue.


CPU Utilization: The percentage of time the CPU is actively executing tasks.

Project Structure

/src: Contains the C++ source code for the simulator logic.



/docs: Includes the comprehensive project documentation and research report.
