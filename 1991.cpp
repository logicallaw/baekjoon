#include <iostream>
#include <vector>
using namespace std;
class Tree;
class CharNode {
private:
    CharNode* par;
    char ele;
    CharNode* leftC = NULL;
    CharNode* rightC = NULL;
    friend class Tree;
};
class Tree{
private:
    CharNode* root;
    vector<CharNode*> nodes;
public:
    Tree() {
        root = new CharNode;
        root->par = NULL;
        root->ele = 'A';
        nodes.push_back(root);
    }
    ~Tree() {
        for(int i{ 0 }; i < nodes.size(); i++) {
            delete nodes[i];
        }
    }
    CharNode* findNode(char c) {
        for(int i{ 0 }; i < nodes.size(); i++) {
            if(nodes[i]->ele == c) {
                return nodes[i];
            }
        }
        return NULL;
    }
    void insert(char v, char lv, char rv) {
        CharNode* nodeV = findNode(v);
        if(nodeV == NULL) {
            return;
        }
        //Left Child
        if(lv != '.') {
            CharNode* nodeLeft = new CharNode;
            nodeLeft->par = nodeV;
            nodeLeft->ele = lv;
            nodeV->leftC = nodeLeft;
            nodes.push_back(nodeLeft);
        }
        //Right Child
        if(rv != '.') {
            CharNode* nodeRight = new CharNode;
            nodeRight->par = nodeV;
            nodeRight->ele = rv;
            nodeV->rightC = nodeRight;
            nodes.push_back(nodeRight);
        }
    }
    CharNode* getRoot() const { return root; }
    void visit(CharNode* v) const {
        cout << v->ele;
    }
    void preOrder(CharNode* v) {
        visit(v);
        if(v->leftC != NULL) {
            preOrder(v->leftC);
        }
        if(v->rightC != NULL) {
            preOrder(v->rightC);
        }
    }
    void inOrder(CharNode* v) {
        if(v->leftC != NULL) {
            inOrder(v->leftC);
        }
        visit(v);
        if(v->rightC != NULL) {
            inOrder(v->rightC);
        }
    }
    void postOrder(CharNode* v) {
        if(v->leftC != NULL) {
            postOrder(v->leftC);
        }
        if(v->rightC != NULL) {
            postOrder(v->rightC);
        }
        visit(v);
    }
};
int main(void) {
    int n;
    cin >> n;
    Tree tree;
    while(n--) {
        char c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        tree.insert(c1, c2, c3);
    }
    CharNode* rootNode = tree.getRoot();
    tree.preOrder(rootNode);
    cout << endl;

    tree.inOrder(rootNode);
    cout << endl;

    tree.postOrder(rootNode);

    return 0;
}