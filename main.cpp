#include <iostream>
#include <limits>
#include "graph.h"
using namespace std;

void displayMenu() {
    cout << "\nPackage Delivery Route Optimizer\n";
    cout << "================================\n";
    cout << "1. Find Minimum Spanning Tree (Prim's)\n";
    cout << "2. Find Shortest Path from a zone (Dijkstra)\n";
    cout << "3. Add new delivery route\n";
    cout << "4. Display current routes\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

int main() {
    cout << "Package Delivery Route Optimizer\n";
    cout << "================================\n";

    int size;
    cout << "Enter number of delivery zones (including warehouse): ";
    while (!(cin >> size) || size <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer: ";
    }

    graph g(size);

    cout << "\nEnter adjacency matrix weights (0 for no connection):\n";
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            int weight;
            cout << "Zone " << i << " to " << j << ": ";
            while (!(cin >> weight) || weight < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid weight. Please enter non-negative integer: ";
            }
            if (weight > 0) {
                g.add_node(i, j, weight);
            }
        }
    }

    int choice;
    do {
        displayMenu();
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter 1-5: ";
        }

        switch (choice) {
            case 1: {
                g.MST();
                break;
            }
            case 2: {
                int source;
                cout << "Enter source zone (0 to " << size - 1 << "): ";
                while (!(cin >> source) || source < 0 || source >= size) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid zone. Please enter 0-" << size-1 << ": ";
                }
                g.shortest_path_from_zone(source);
                break;
            }
            case 3: {
                int from, to, weight;
                cout << "Enter route to add (from to weight): ";
                while (!(cin >> from >> to >> weight) || from < 0 || from >= size ||
                       to < 0 || to >= size || weight <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Enter valid zone numbers (0-" << size-1
                         << ") and positive weight: ";
                       }
                g.add_node(from, to, weight);
                cout << "Route added successfully!\n";
                break;
            }
            case 4: {
                g.display_routes();
                break;
            }
            case 5: {
                cout << "Exiting program...\n";
                break;
            }
        }
    } while (choice != 5);

    return 0;
}