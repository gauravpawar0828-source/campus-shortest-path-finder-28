#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 99999

int graph[MAX][MAX];
int n = 0;
int source = -1;
int distance[MAX];
int parent[MAX];
int visited[MAX];

char location[MAX][50];

int graphEntered = 0;
int shortestPathFound = 0;

void enterGraph() {
    int i, j, edge;

    printf("\nEnter number of locations: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of locations!\n");
        n = 0;
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter name of location %d: ", i + 1);
        scanf(" %[^\n]", location[i]);
    }

    printf("\nEnter distance between locations.\n");
    printf("Enter 0 if there is no direct road.\n");
    printf("(Diagonal values will automatically be 0.)\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                printf("Distance from %s to %s: ",
                       location[i], location[j]);

                scanf("%d", &edge);

                if (edge < 0) {
                    printf("Distance cannot be negative.\n");
                    j--;
                }
                else {
                    graph[i][j] = edge;
                }
            }
        }
    }

    graphEntered = 1;
    shortestPathFound = 0;

    printf("\nCampus graph entered successfully!\n");
}

void displayMatrix() {
    int i, j;

    if (!graphEntered) {
        printf("\nPlease enter the campus graph first.\n");
        return;
    }

    printf("\n========== ADJACENCY MATRIX ==========\n\n");

    printf("%-20s", "");

    for (i = 0; i < n; i++)
        printf("%-12s", location[i]);

    printf("\n");

    for (i = 0; i < n; i++) {

        printf("%-20s", location[i]);

        for (j = 0; j < n; j++) {

            if (graph[i][j] == 0 && i != j)
                printf("%-12s", "INF");
            else
                printf("%-12d", graph[i][j]);
        }

        printf("\n");
    }
}

void selectSource() {
    int i;

    if (!graphEntered) {
        printf("\nPlease enter the campus graph first.\n");
        return;
    }

    printf("\n========== LOCATIONS ==========\n");

    for (i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, location[i]);
    }

    printf("\nEnter source location number: ");
    scanf("%d", &source);

    if (source < 1 || source > n) {
        printf("Invalid source location!\n");
        source = -1;
        return;
    }

    source--;

    printf("\nSource selected: %s\n", location[source]);
    shortestPathFound = 0;
}

void dijkstra() {
    int i, count, u, v;
    int minDistance;

    if (!graphEntered) {
        printf("\nPlease enter the campus graph first.\n");
        return;
    }

    if (source == -1) {
        printf("\nPlease select a source location first.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        distance[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }

    distance[source] = 0;

    for (count = 0; count < n - 1; count++) {

        minDistance = INF;
        u = -1;

        /* Find unvisited vertex with minimum distance */
        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        /* Update adjacent vertices */
        for (v = 0; v < n; v++) {

            if (graph[u][v] != 0 &&
                !visited[v] &&
                distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    shortestPathFound = 1;

    printf("\nDijkstra's algorithm completed successfully!\n");
}

void printPath(int vertex) {
    if (parent[vertex] == -1) {
        printf("%s", location[vertex]);
        return;
    }

    printPath(parent[vertex]);
    printf(" -> %s", location[vertex]);
}

void displayPaths() {
    int i;

    if (!shortestPathFound) {
        printf("\nPlease run Dijkstra's Algorithm first.\n");
        return;
    }

    printf("\n========== SHORTEST PATHS ==========\n");

    for (i = 0; i < n; i++) {

        if (i == source)
            continue;

        printf("\nDestination: %s\n", location[i]);

        if (distance[i] == INF) {
            printf("Shortest Distance: Not reachable\n");
            printf("Path: No path available\n");
        }
        else {
            printf("Shortest Distance: %d\n", distance[i]);
            printf("Path: ");
            printPath(i);
            printf("\n");
        }
    }
}

void displayDistances() {
    int i;

    if (!shortestPathFound) {
        printf("\nPlease run Dijkstra's Algorithm first.\n");
        return;
    }

    printf("\n========== DISTANCES FROM SOURCE ==========\n");

    printf("Source: %s\n\n", location[source]);

    printf("%-25s %-15s\n", "Destination", "Distance");

    for (i = 0; i < n; i++) {

        if (distance[i] == INF)
            printf("%-25s %-15s\n",
                   location[i], "INF");
        else
            printf("%-25s %-15d\n",
                   location[i], distance[i]);
    }
}

int main() {
    int choice;

    do {
        printf("\n\n===== CAMPUS SHORTEST ROUTE FINDER =====\n");
        printf("1. Enter Campus Graph\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. Select Source Location\n");
        printf("4. Find Shortest Distance\n");
        printf("5. Display Shortest Paths\n");
        printf("6. Display Distance from Source to All Locations\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                enterGraph();
                break;

            case 2:
                displayMatrix();
                break;

            case 3:
                selectSource();
                break;

            case 4:
                dijkstra();
                break;

            case 5:
                displayPaths();
                break;

            case 6:
                displayDistances();
                break;

            case 7:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice! Please enter 1-7.\n");
        }

    } while (choice != 7);

    return 0;
}