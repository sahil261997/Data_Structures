#include <bits/stdc++.h>
using namespace std;

struct AdjListNode
{
    int data;
    AdjListNode *next;
};

struct AdjList
{
    AdjListNode *head;
};

struct Graph
{
    int V;
    AdjList *arr;
};

AdjListNode *newAdjListNode(int);
Graph *createGraph(int);
void addEdge(Graph *, int, int);
void printGraph(Graph *);

int main()
{
    int totalVertices = 4;
    Graph *graph;
    graph = createGraph(totalVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    printGraph(graph);
}

AdjListNode *newAdjListNode(int data)
{
    AdjListNode *nptr = new AdjListNode;
    nptr->data = data;
    nptr->next = NULL;
    return nptr;
}

Graph *createGraph(int V)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->arr = new AdjList[V];
    for (int i = 0; i < V; i++)
    {
        graph->arr[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    AdjListNode *nptr = newAdjListNode(dest);
    nptr->next = graph->arr[src].head;
    graph->arr[src].head = nptr;
    nptr = newAdjListNode(src);
    nptr->next = graph->arr[dest].head;
    graph->arr[dest].head = nptr;
}

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->V; i++)
    {
        AdjListNode *root = graph->arr[i].head;
        cout << "Adjacency list of vertex " << i << endl;
        while (root != NULL)
        {
            cout << root->data << " -> ";
            root = root->next;
        }
        cout << endl;
    }
}