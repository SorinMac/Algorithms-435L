#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Node structure for the LinkedObj
struct LinkedObj {
    string node;
    vector<int> neighbors;
    bool isProcessed = false;
};

// Node structure for the Queue
struct QueueNode {
    int data;
    QueueNode* link;
};

// Queue class
class Queue {
public:
    Queue() : front(nullptr), back(nullptr) {}

    void enqueue(int info) {
        QueueNode* temp = new QueueNode;
        temp->data = info;
        temp->link = nullptr;

        if (isEmptyQueue()) {
            front = temp;
            back = temp;
        } else {
            temp->link = back;
            back = temp;
        }
    }

    int dequeue() {
        if (isEmptyQueue()) {
            return 0;
        }

        QueueNode* temp = front;
        int data = temp->data;

        front = front->link;
        delete temp;

        if (front == nullptr) {
            back = nullptr;
        }

        return data;
    }

    bool isEmptyQueue() const {
        return front == nullptr;
    }

private:
    QueueNode* front;
    QueueNode* back;
};

// Depth-First Search (DFS)
void depthFirstSearch(LinkedObj Vertices[], int id, int count) {
    if (!Vertices[id].isProcessed) {
        Vertices[id].isProcessed = true;

        cout << "Visited node " << stoi(Vertices[id].node) << endl;

        for (int neighbor : Vertices[id].neighbors) {
            depthFirstSearch(Vertices, neighbor - 1, count);
        }
    }
}

// Breadth-First Search (BFS)
void breadthFirstSearch(LinkedObj Vertices[], int id, int count) {
    Queue BFSQueue;

    BFSQueue.enqueue(id);

    Vertices[id].isProcessed = true;

    cout << "\nBreadth-First Search: " << "\n";

    while (!BFSQueue.isEmptyQueue()) {
        int current = BFSQueue.dequeue();

        cout << "Visited Node: " << stoi(Vertices[current].node) << endl;

        for (int neighbor : Vertices[current].neighbors) {
            if (!Vertices[neighbor - 1].isProcessed) {
                Vertices[neighbor - 1].isProcessed = true;
                BFSQueue.enqueue(neighbor - 1);
            }
        }
    }
}

// Function to create LinkedObj array and perform DFS and BFS
void performSearch(int vertexCount, vector<int> start, vector<int> end, int count) {
    // Create an array of LinkedObj called Vertices to store them all
    LinkedObj Vertices[vertexCount];
    int VECTOR_SIZE = max(start.size(), end.size());

    // Give the name to the node value of each of the LinkedObj
    for (int i = 0; i < vertexCount; i++) {
        Vertices[i].node = to_string(i + 1);
    }

    // Add neighbors to Vertices based on start and end vectors
    for (int i = 0; i < VECTOR_SIZE; i++) {
        int startIndex = start[i] - 1;
        int endIndex = end[i] - 1;

        Vertices[startIndex].neighbors.push_back(end[i]);
        Vertices[endIndex].neighbors.push_back(start[i]);
    }

    cout << "\nLinked Objects: " << "\n";
    for (int i = 0; i < vertexCount; i++) {
        cout << "Neighbors of Node " << stoi(Vertices[i].node) << ": ";
        for (int neighbor : Vertices[i].neighbors) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    int id = 0;

    cout << "\nDepth-First Search: " << "\n";
    depthFirstSearch(Vertices, id, count);

    for (int i = 0; i < vertexCount; i++) {
        Vertices[i].isProcessed = false;
    }

    cout << "\n";

    breadthFirstSearch(Vertices, id, count);
}
