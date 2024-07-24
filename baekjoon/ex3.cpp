#include <iostream>
#include <vector>
#define UNEXPLORED 0
#define VISITED 1
#define DISCOVERY 2
#define BACK 3
#define FINISHED 4
using namespace std;
class Edge;
class Vertex;
class Graph;

class Edge {
private:
    int flag = UNEXPLORED;
    Vertex* srcV = NULL;
    Vertex* desV = NULL;
    Vertex* opposite(Vertex* v) {
        if(v == srcV) {
            return desV;
        } else {
            return srcV;
        }
    }
    friend class Graph;
};
class Vertex{
private:
    int ele;
    int flag = UNEXPLORED;
    vector<Edge*> incidentSeq;
    friend class Graph;
};
class Graph{
private:
    vector<Vertex*> vertexSeq;
    vector<Edge*> edgeSeq;
public:
    Graph(int n) {
        for(int i{ 1 }; i <= n; i++) {
            Vertex *newV = new Vertex;
            newV->ele = i;
            vertexSeq.push_back(newV);
        }
    }
//    ~Graph() {
//        for(int i{ 0 }; i < vertexSeq.size(); i++) {
//            Vertex* old = vertexSeq[i];
//            vertexSeq[i] = NULL;
//            delete old;
//        }
//        for(int i{ 0 }; i < edgeSeq.size(); i++) {
//            Edge* old = edgeSeq[i];
//            edgeSeq[i] = NULL;
//            delete old;
//        }
//    }
    Vertex* insertVertex(int v) {
        Vertex* newV = findVertex(v);
        if(newV == NULL) {
            newV = new Vertex;
            newV->ele = v;
            vertexSeq.push_back(newV);
        }
        return newV;
    }
    Vertex* findVertex(int e) {
        for(Vertex* v : vertexSeq) {
            if(v->ele == e) {
                return v;
            }
        }
        return NULL;
    }
    void insertEdge(int a, int b) {
        Vertex* vA = findVertex(a);
        Vertex* vB = findVertex(b);

        Edge* newE = new Edge;
        newE->srcV = vA;
        newE->desV = vB;
        edgeSeq.push_back(newE);
        vA->incidentSeq.push_back(newE);
        vB->incidentSeq.push_back(newE);
    }
    void dfs(Vertex* v) {
        v->flag = VISITED;
        cout << v->ele << " ";
        for(Edge* e : v->incidentSeq) {
            if(e->flag == UNEXPLORED) {
                Vertex* w = e->opposite(v);
                if(w->flag == UNEXPLORED) {
                    e->flag = DISCOVERY;
                    dfs(w);
                }
                else {
                    e->flag = BACK;
                }
            }
        }
    }
    void initGraph() {
        for(Vertex* v : vertexSeq) {
            v->flag = UNEXPLORED;
        }
        for(Edge* e : edgeSeq) {
            e->flag = UNEXPLORED;
        }
    }
};
int main(void) {
    int n, m, v;
    cin >> n >> m >> v;
    Graph g(n);
    while(m--) {
        int a, b;
        cin >> a >> b;
        g.insertEdge(a,b);
    }
    Vertex* vertexV = g.findVertex(v);
    g.dfs(vertexV);
    g.initGraph();
//    g.bfs(vertexV);
}