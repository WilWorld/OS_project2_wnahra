# OS_project2_wnahra
Programming Assignment #2
This program implements the Banker’s Algorithm to determine whether a system of processes and resources is in a safe or unsafe state. The program reads an input file containing:

The available resources vector

The allocation matrix

The maximum demand matrix

It then computes the need matrix, runs the safety algorithm, and prints:

Whether the system is in a safe state

The safe sequence of processes (if one exists)

This program is designed to prevent deadlock by analyzing resource allocation before granting further requests.
