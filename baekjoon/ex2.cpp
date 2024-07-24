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
    int cnt = 1;
public:
    Graph() {}
    ~Graph() {
        for(int i{ 0 }; i < vertexSeq.size(); i++) {
            Vertex* old = vertexSeq[i];
            vertexSeq[i] = NULL;
            delete old;
        }
        for(int i{ 0 }; i < edgeSeq.size(); i++) {
            Edge* old = edgeSeq[i];
            edgeSeq[i] = NULL;
            delete old;
        }
    }
    void insert(int a, int b) {
        Vertex* newA = insertVertex(a);
        Vertex* newB = insertVertex(b);
        insertEdge(newA, newB);
    }
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
    void insertEdge(Vertex* a, Vertex* b) {
        Edge* newE = new Edge;
        newE->srcV = a;
        newE->desV = b;
        edgeSeq.push_back(newE);
        a->incidentSeq.push_back(newE);
        b->incidentSeq.push_back(newE);
    }
    void dfs(Vertex* v, int b) {
        v->flag = VISITED;
        if(v->ele == b) {
            cout << cnt << endl;
            return;
        }
        for(Edge* e : v->incidentSeq) {
            if(e->flag == UNEXPLORED) {
                Vertex* w = e->opposite(v);
                if(w->flag == UNEXPLORED) {
                    e->flag = DISCOVERY;
                    cnt++;
                    dfs(w, b);
                }
                else {
                    e->flag = BACK;
                }
            }
        }
    }
    void initDfs() {
        for(Vertex* v : vertexSeq) {
            v->flag = UNEXPLORED;
        }
        for(Edge* e : edgeSeq) {
            e->flag = UNEXPLORED;
        }
        cnt = 1;
    }
};
int main(void) {
    int n, m, q;
    cin >> n >> m >> q;
    Graph g;
    while(m--) {
        int u, v;
        cin >> u >> v;
        g.insert(u, v);
    }
    while(q--) {
        int a, b;
        cin >> a >> b;
        Vertex* vA = g.findVertex(a);
        g.dfs(vA, b);
        g.initDfs();
    }
}
/*
6 6 4
1 5
5 2
1 2
1 3
2 4
3 6
2 1
2 6
3 6
1 4
 */