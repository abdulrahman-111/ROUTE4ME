# Route4Me - Delivery Route Optimization System

[![C++](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)

## Overview

**Route4Me** is a C++-based application designed to optimize package delivery routes across multiple zones, including a warehouse. Developed as a project for the Data Structures and Algorithms course (CSE 123), it implements graph algorithms to compute:
- **Minimum Spanning Tree (MST)** using Prim's Algorithm for cost-efficient network design.
- **Shortest Paths** using Dijkstra's Algorithm for the fastest delivery routes from any specified zone.

The system features an interactive command-line interface, dynamic route management, and robust error handling, making it suitable for optimizing delivery networks in real-world scenarios.

## Features

- **Interactive Menu System**: Allows users to perform multiple operations (e.g., compute MST, find shortest paths, add routes) in a single run.
- **Dynamic Route Management**: Add new delivery routes and recalculate optimizations dynamically.
- **Graph Visualization**: Displays current routes in a clear adjacency matrix format.
- **Error Handling**: Validates all user inputs to ensure robustness and prevent crashes.
- **Efficient Algorithms**:
  - **Prim's Algorithm**: Computes the MST to connect all zones with minimal total cost.
  - **Dijkstra's Algorithm**: Finds the shortest paths from a specified zone to all others, including exact path details.

## Project Structure

```
Route4Me/
├── include/
│   ├── graph.h              # Graph class definition
│   ├── prim's.h            # MST class for Prim's Algorithm
│   ├── SSSP.h              # SSSP class for Dijkstra's Algorithm
├── src/
│   ├── main.cpp            # Main program with interactive menu
│   ├── graph.cpp           # Graph class implementation
│   ├── prim's.cpp         # Prim's Algorithm implementation
│   ├── SSSP.cpp            # Dijkstra's Algorithm implementation
├── README.md               # This file
├── LICENSE                 # MIT License
└── Project_description.pdf # Project report
```

## Prerequisites

- **C++ Compiler**: g++ or any C++11-compliant compiler (e.g., clang++, MSVC).
- **Standard Template Library (STL)**: Included with any standard C++ installation.
- **Operating System**: Compatible with Windows, Linux, or macOS.

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/Route4Me.git
   cd Route4Me
   ```

2. **Compile the Program**:
   ```bash
   g++ -o Route4Me src/main.cpp src/graph.cpp src/prim's.cpp src/SSSP.cpp -I include
   ```

3. **Run the Program**:
   ```bash
   ./Route4Me
   ```

## Usage

1. **Launch the Program**:
   - Run the compiled executable (`./Route4Me`).
   - Enter the number of delivery zones (including the warehouse) when prompted.

2. **Input the Adjacency Matrix**:
   - Provide weights for connections between zones (0 for no connection, positive integers for route costs).
   - Example input for a 3-zone graph:
     ```
     Zone 0 to 1: 5
     Zone 0 to 2: 10
     Zone 1 to 2: 3
     ```

3. **Interact with the Menu**:
   - Choose from the following options:
     1. **Find Minimum Spanning Tree (Prim's)**: Outputs MST edges and total minimum cost.
     2. **Find Shortest Path from a Zone (Dijkstra)**: Enter a source zone to compute shortest paths and distances to all other zones.
     3. **Add New Delivery Route**: Add a new route by specifying source zone, destination zone, and weight.
     4. **Display Current Routes**: Shows all current routes in the adjacency matrix.
     5. **Exit**: Terminates the program.

4. **Example Output**:
   - For MST (Prim's):
     ```
     Edge    Weight
     0-1     5
     1-2     3
     The min_cost= 8
     ```
   - For Shortest Paths (Dijkstra from Zone 0):
     ```
     Shortest delivery routes from zone 0:
     -----------------------------------------
     Zone    Distance    Path
     -----------------------------------------
     0       0           path: 0
     1       5           path: 0 -> 1
     2       8           path: 0 -> 1 -> 2
     ```

## Implementation Details

- **Data Structures**:
  - **Adjacency Matrix**: Stores the graph as a 2D vector for efficient access.
  - **Adjacency List**: Converted from the matrix for Dijkstra's Algorithm to optimize edge traversal.
  - **Priority Queue (Min-Heap)**: Used in Dijkstra's Algorithm for efficient shortest path computation.
  - **Arrays/Vectors**: Track visited nodes, distances, and parent nodes for both algorithms.

- **Classes**:
  - **graph**: Manages the delivery network, including route addition and algorithm invocation.
  - **mst**: Implements Prim's Algorithm to compute the MST.
  - **sssp**: Implements Dijkstra's Algorithm for shortest path calculations.

- **Algorithms**:
  - **Prim's Algorithm**: Finds the MST by iteratively selecting the minimum-weight edge connecting visited and unvisited nodes.
  - **Dijkstra's Algorithm**: Computes shortest paths from a source zone using a priority queue for efficient node selection.

## Contributing

Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a feature branch (`git checkout -b feature/your-feature`).
3. Commit your changes (`git commit -m 'Add your feature'`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Open a pull request.

Please ensure your code follows the project's coding style and includes appropriate comments.

## Author

- **Abdulrahman Gomaa** 
- Developed as part of the Data Structures and Algorithms course (CSE 123).
- **Instructor**: Dr. Amr El-Masry


## Acknowledgments

- Thanks to Dr. Amr El Masri  for their guidance.
- The interactive menu and input handling were developed with assistance from AI tools, while core algorithms and logic were implemented independently.
- Future work includes adding support for weighted directed graphs and visualizing the graph using a GUI.

## Future Work

- Implement support for directed graphs to model one-way routes.
- Add a graphical user interface (GUI) for visualizing the delivery network.
- Enhance error handling for edge cases (e.g., disconnected graphs).
- Integrate additional graph algorithms (e.g., Kruskal's Algorithm for MST).
