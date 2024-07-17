    #include <iostream>
    #include <vector>
    using namespace std;
    class Tree;
    class IntNode{
    private:
        IntNode* par;
        int ele;
        vector<IntNode*> child;
        friend class Tree;
    };
    class Tree {
    private:
        IntNode* root;
        vector<IntNode*> nodes;
        int leaf = 0;
    public:
        Tree() {
            root = NULL;
        }
        ~Tree() {
            for(int i{ 0 }; i < nodes.size(); i++) {
                delete nodes[i];
            }
        }
        bool isExternal(IntNode* v) const { return v->child.size() == 0; }
        int getLeafs() const { return leaf; }
        IntNode* getRoot() const { return root; }
        IntNode* findNode(int e) const {
            for(int i{ 0 }; i < nodes.size(); i++) {
                if(nodes[i]->ele == e) {
                    return nodes[i];
                }
            }
            return NULL;
        }
        void insert(int x, int i) {
            if(x == -1){
                root = new IntNode;
                root->par = NULL;
                root->ele = i;
                nodes.push_back(root);
                return;
            }
            IntNode* parNode = findNode(x);
            if(parNode != NULL) {
                IntNode* newNode = new IntNode;
                newNode->par = parNode;
                newNode->ele = i;
                parNode->child.push_back(newNode);
                nodes.push_back(newNode);
            } else {
                return;
            }
        }
        void erase(int x) {
            if(root->ele == x) {
                root = NULL;
            } else {
                IntNode* delNode = findNode(x);
                if(delNode == NULL) return;
                IntNode* parNode = delNode->par;
                bool isDeleted = false;
                //nodes에서 삭제
                for(int i{ 0 }; i < nodes.size(); i++) {
                    if(isDeleted) break;
                    if(nodes[i] == delNode) {
                        nodes.erase(nodes.begin() + i);
                        isDeleted = true;
                    }
                }
                //parent-child 연결 해제
                isDeleted = false;
                for(int i{ 0 }; i < parNode->child.size(); i++) {
                    if(isDeleted) break;
                    if(parNode->child[i] == delNode) {
                        parNode->child.erase(parNode->child.begin() + i);
                        isDeleted = true;
                    }
                }
                delete delNode;
            }
        }
        void postOrder(IntNode* v) {
            for(IntNode* c : v->child){
                postOrder(c);
            }
            if(isExternal(v)) {
                leaf++;
            }
        }
    };
    int main(void) {
        int n;
        cin >> n;
        Tree t;

        for(int i{ 0 }; i < n; i++){
            int x;
            cin >> x;
            t.insert(x, i);
        }

        int x;
        cin >> x;
        t.erase(x);

        IntNode* r = t.getRoot();
        if(r != NULL) {
            t.postOrder(r);
        }
        cout << t.getLeafs() << endl;
    }