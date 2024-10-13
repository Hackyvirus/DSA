#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_QUEUE_SIZE 5

// Queue structure and functions
typedef struct {
    int front, rear, size;
    int arr[MAX_QUEUE_SIZE];
} Queue;

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

int isFull(Queue *queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

int enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is Full\n");
        return -1;
    } else {
        queue->arr[queue->rear] = data;
        printf("%d is enqueued to the queue\n", data);
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        queue->size++;
        return 0;
    }
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return -1;
    } else {
        int value = queue->arr[queue->front];
        printf("The dequeued element is %d\n", value);
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        queue->size--;
        return value;
    }
}

// Graph structure and functions
int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
int visited[MAX_VERTICES]; // Visited array to keep track of visited nodes

// Function to add an edge to the graph (undirected graph)
void addEdge(int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1; // For undirected graph
}

// BFS function using the custom Queue implementation
void bfs(int startVertex) {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        // Visit all the adjacent vertices of the current vertex
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                enqueue(&queue, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices = 6;

    // Initialize the graph
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Adding some edges to the graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    printf("Breadth-First Search starting from vertex 0:\n");
    bfs(0);

    return 0;
}
