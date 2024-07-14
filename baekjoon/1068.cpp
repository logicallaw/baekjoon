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
        int leef = 0;
    public:
        Tree() {
            root = NULL;
        }
        ~Tree() {
            for(std::vector<IntNode*>::size_type i{ 0 }; i < nodes.size(); i++) {
                delete nodes[i];
            }
        }
        bool isExternal(IntNode* v) const { return v->child.size() == 0; }
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
            }
        }
        void erase(int x) {
            if(x == 0) {
                root = NULL;
            } else { //부모 모두 존재
                IntNode* old = findNode(x);
                //노드의 부모의 자식에서 삭제
                for(int i{ 0 }; i < old->par->child.size(); i++) {
                    if(old->par->child[i] == old) {
                        old->par->child.erase(old->par->child.begin() + i);
                        break;
                    }
                }
                //nodes에서 삭제
                for(int i{ 0 }; i < nodes.size(); i++) {
                    if(nodes[i] == old) {
                        nodes.erase(nodes.begin() + i);
                        break;
                    }
                }
            }
        }
        void postOrder(IntNode* v) {
            for(IntNode* c : v->child){
                postOrder(c);
            }
            if(isExternal(v)) {
                leef++;
            }
        }
        void printleef(){
            if(root != NULL) {
                postOrder(root);
            }
            cout << leef << endl;
        }
    };
    int main(void) {
        int n;
        cin >> n;
        Tree tree;
        for(int i{ 0 }; i < n; i++){
            int x;
            cin >> x;
            tree.insert(x, i);
        }
        int x;
        cin >> x;
        tree.erase(x);
        tree.printleef();
    }