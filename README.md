# 🎓 Campus Shortest Route Finder – Dijkstra's Algorithm

### Analysis of Algorithms (AOA) – Problem-Based Learning Experiment 2

A menu-driven C program that finds the **shortest distance and shortest path between campus locations** using **Dijkstra's Algorithm**.

---

## 📌 Problem Statement

A college campus consists of multiple locations such as the Main Gate, Library, Computer Department, Laboratory, and Auditorium. These locations are connected by roads, and each road has a specific distance.

The objective is to develop a menu-driven C program that allows the user to:

* Enter the campus road network.
* Represent the campus using a weighted adjacency matrix.
* Select a source location.
* Find the shortest distance from the source to all other locations.
* Display the shortest path to each location.
* Display the distance from the selected source to every location.

---

## 🎯 Objectives

* Implement a **weighted graph** using an adjacency matrix.
* Implement **Dijkstra's Shortest Path Algorithm**.
* Find the shortest distance from a single source to all vertices.
* Reconstruct and display the shortest paths.
* Understand the **Greedy Method** used by Dijkstra's Algorithm.
* Analyze time and space complexity.

---

## 🧠 Algorithm Used

### Dijkstra's Algorithm

Dijkstra's Algorithm is a **Greedy Algorithm** used to find the shortest path from a single source vertex to all other vertices in a weighted graph.

It works only when all edge weights are **non-negative**.

### Basic Steps

1. Initialize the distance of the source vertex to `0`.
2. Initialize the distance of all other vertices to `INF`.
3. Mark all vertices as unvisited.
4. Select the unvisited vertex with the smallest distance.
5. Mark it as visited.
6. Update the distances of its neighboring vertices.
7. Store the previous vertex in the `parent[]` array.
8. Repeat until all reachable vertices are processed.
9. Use the parent array to reconstruct the shortest paths.

---

## 🗺️ Sample Campus Locations

| No. | Location            |
| --: | ------------------- |
|   1 | Main Gate           |
|   2 | Library             |
|   3 | Computer Department |
|   4 | Laboratory          |
|   5 | Auditorium          |

---

## 📊 Sample Adjacency Matrix

The following matrix represents the distance between campus locations.

| From / To               | Main Gate | Library | Computer Department | Laboratory | Auditorium |
| ----------------------- | --------: | ------: | ------------------: | ---------: | ---------: |
| **Main Gate**           |         0 |       4 |                  10 |         15 |         20 |
| **Library**             |         4 |       0 |                   3 |          8 |         15 |
| **Computer Department** |        10 |       3 |                   0 |          2 |          9 |
| **Laboratory**          |        15 |       8 |                   2 |          0 |          3 |
| **Auditorium**          |        20 |      15 |                   9 |          3 |          0 |

> In this implementation, `0` between two different locations means there is no direct road between them. The diagonal elements are `0`.

---

## 🔢 Example Input

### Number of Locations

```text
5
```

### Location Names

```text
Main Gate
Library
Computer Department
Laboratory
Auditorium
```

### Distance Matrix

```text
0 4 10 15 20
4 0 3 8 15
10 3 0 2 9
15 8 2 0 3
20 15 9 3 0
```

### Source Location

```text
1
```

Here, location `1` represents **Main Gate**.

---

## 🖥️ Menu

```text
========== CAMPUS SHORTEST ROUTE FINDER ==========

1. Enter Campus Graph
2. Display Adjacency Matrix
3. Select Source Location
4. Find Shortest Distance
5. Display Shortest Paths
6. Display Distance from Source to All Locations
7. Exit
```

---

## 📍 Shortest Distance Calculation

For the source **Main Gate**:

### Main Gate → Library

```text
Distance = 4
```

### Main Gate → Computer Department

Direct:

```text
10
```

Through Library:

```text
4 + 3 = 7
```

Therefore:

```text
Shortest Distance = 7
```

### Main Gate → Laboratory

Through Library and Computer Department:

```text
4 + 3 + 2 = 9
```

Therefore:

```text
Shortest Distance = 9
```

### Main Gate → Auditorium

Through Library → Computer Department → Laboratory:

```text
4 + 3 + 2 + 3 = 12
```

Therefore:

```text
Shortest Distance = 12
```

---

## ✅ Expected Output

```text
========== SHORTEST PATHS ==========

Destination: Library
Shortest Distance: 4
Path: Main Gate -> Library

Destination: Computer Department
Shortest Distance: 7
Path: Main Gate -> Library -> Computer Department

Destination: Laboratory
Shortest Distance: 9
Path: Main Gate -> Library -> Computer Department -> Laboratory

Destination: Auditorium
Shortest Distance: 12
Path: Main Gate -> Library -> Computer Department -> Laboratory -> Auditorium
```

---

## 📋 Final Distance Table

| Destination         | Shortest Distance | Shortest Path                                                       |
| ------------------- | ----------------: | ------------------------------------------------------------------- |
| Main Gate           |                 0 | Main Gate                                                           |
| Library             |                 4 | Main Gate → Library                                                 |
| Computer Department |                 7 | Main Gate → Library → Computer Department                           |
| Laboratory          |                 9 | Main Gate → Library → Computer Department → Laboratory              |
| Auditorium          |                12 | Main Gate → Library → Computer Department → Laboratory → Auditorium |

---

## 🏗️ Project Structure

```text
Campus-Shortest-Route-Finder/
│
├── campus_shortest_route.c
├── README.md
└── screenshots/
    └── output.png
```

---

## 🔧 Important Variables

| Variable            | Purpose                                        |
| ------------------- | ---------------------------------------------- |
| `graph[][]`         | Stores the adjacency matrix                    |
| `distance[]`        | Stores shortest distances                      |
| `parent[]`          | Stores previous vertex for path reconstruction |
| `visited[]`         | Tracks processed vertices                      |
| `location[][]`      | Stores campus location names                   |
| `graphEntered`      | Checks whether graph is entered                |
| `shortestPathFound` | Checks whether Dijkstra has been executed      |

---

## ⚙️ Complexity Analysis

### Time Complexity

The program uses an adjacency matrix and a linear search to find the minimum-distance vertex.

```text
Time Complexity = O(V²)
```

where `V` is the number of locations.

### Space Complexity

The adjacency matrix requires:

```text
O(V²)
```

Additional arrays require `O(V)` space.

Therefore:

```text
Overall Space Complexity = O(V²)
```

---

## ⚠️ Limitations

* Dijkstra's Algorithm does not support negative edge weights.
* The adjacency matrix requires `O(V²)` memory.
* This implementation has `O(V²)` time complexity.
* `0` represents no direct connection between different locations.
* It is less efficient for very large sparse graphs compared with an adjacency-list implementation using a priority queue.

---

## 🌍 Real-World Applications

Dijkstra's Algorithm is widely used in:

* 🏫 Campus navigation
* 🗺️ GPS and map applications
* 🚗 Route planning
* 📦 Delivery systems
* 🌐 Computer network routing
* 🚆 Transportation systems
* 🏢 Building navigation
* 📍 Location-based applications

---

## 📚 AOA Concepts Covered

This project demonstrates:

* Graphs
* Weighted Graphs
* Adjacency Matrix
* Greedy Method
* Dijkstra's Algorithm
* Shortest Path
* Path Reconstruction
* Parent/Predecessor Array
* Time Complexity
* Space Complexity

---

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR-USERNAME/Campus-Shortest-Route-Finder.git
```

### 2. Open the Project

```bash
cd Campus-Shortest-Route-Finder
```

### 3. Compile

Using GCC:

```bash
gcc campus_shortest_route.c -o campus_route
```

### 4. Run

Windows:

```bash
campus_route
```

Linux/macOS:

```bash
./campus_route
```

---

## 🛡️ Input Validation

The program handles common invalid inputs such as:

* Invalid menu choice
* Invalid number of locations
* Invalid source location
* Negative distance
* Running Dijkstra before entering the graph
* Displaying paths before calculating shortest paths

---

## 📌 Result

The **Campus Shortest Route Finder** was successfully implemented in C using **Dijkstra's Algorithm**.

For the selected source **Main Gate**, the shortest distances are:

```text
Library             → 4
Computer Department → 7
Laboratory          → 9
Auditorium          → 12
```

The program also reconstructs and displays the corresponding shortest paths using the `parent[]` array.

---

## 👨‍💻 Author

**Gaurav Pawar**

### 📖 Subject

**Analysis of Algorithms (AOA)**

### 🧪 Experiment

**PBLE 2 – Campus Shortest Route Finder**

---

## ⭐ Key Learning

> This project demonstrates how Dijkstra's Greedy Algorithm can be applied to a real-world campus navigation problem to efficiently determine the shortest routes between locations.
