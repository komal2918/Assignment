# Overview

This C++ program provides implementations for:

- Binary Search: Searches for a target in a sorted array.

- Quick Sort: Sorts an array using Quick Sort.

- BFS Traversal: Traverses a graph starting from a given node.

- Logging Mechanism: Stores each API call in a logs.txt file.

## Prerequisites

C++ compiler (G++ recommended)

Command-line terminal

## Installation & Execution

1. Compile the Program

g++ -std=c++17 backend.cpp -o backend

2. Run the Program

./backend

## How to Use

Once the program starts, it will display the following menu:

Select an operation:
1. Binary Search
2. Quick Sort
3. BFS Traversal
4. View Logs
5. Exit
Enter choice:

### Binary Search

Input: Sorted array (space-separated, end with -1), then enter the target value.

Example:

Enter sorted array elements (space-separated, end with -1): 1 3 5 7 9 -1

Enter target value: 5

Output: Index: 2

### Quick Sort

Input: Array elements (space-separated, end with -1).

Example:

Enter array elements to sort (space-separated, end with -1): 3 1 4 1 5 9 -1

Output: Sorted: 1 1 3 4 5 9

### BFS Traversal

Input: Enter the number of edges, then enter each edge (node1 node2 format), followed by the start node.

Example:

Enter number of edges: 5

Enter edges (format: node1 node2):

A B

A C

B D

C E

E F

Enter start node: A

Output: BFS Order: A B C D E F

Error Handling: If a non-existing start node is given, the program will print an error message.

### View Logs

Command: Selecting this option will display all previous operations stored in logs.txt.

Example Output:

Algorithm : Binary Search 

Input : Array : 1 3 5 7 9 | Target : 5

Output : Index : 2

### Exit

Command: Selecting this option exits the program.

## Additional Notes

Each operation is logged in logs.txt.

If BFS is run with a missing start node, it will notify the user and not proceed.

Input validation is handled gracefully to avoid crashes
