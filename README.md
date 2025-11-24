This program implements the Banker’s Algorithm to determine whether a system of processes and resources is in a safe or unsafe state. The program reads an input file containing:

* The available resources vector

* The allocation matrix

* The maximum demand matrix

It then computes the need matrix, runs the safety algorithm, and prints:

* Whether the system is in a safe state

* The safe sequence of processes (if one exists)

Banker’s Algorithm used to avoid deadlocks in operating systems.
It ensures the system stays in a safe state—a state where all processes can run to completion without deadlock.

* The algorithm uses the following data structures:

* Available[j] = Number of resource instances currently available for each resource type j.

* Allocation[i][j] = Number of instances of each resource type currently allocated to process i.

* Max[i][j] = Maximum demand that process i may request.

* Need[i][j] = Max[i][j] − Allocation[i][j] = Remaining resources needed by process i to finish.
