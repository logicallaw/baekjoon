#include <iostream>
#include <string>
using namespace std;
class SLinkedList;
class IntNode{
private:
    int ele;
    IntNode* next;
    friend class SLinkedList;
};

class SLinkedList{
private:
    IntNode* head;
    IntNode* tail;
    int n;
public:
    SLinkedList() : head{ NULL }, tail{ NULL }, n{ 0 } {}
    bool empty() const { return (n == 0); }
    int size() const { return n; }
    void addBack(int x) {
        IntNode* newNode = new IntNode;
        newNode->ele = x;
        newNode->next = NULL;
        if(empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        n++;
    }
    int removeFront() {
        if(empty()){
            return -1;
        }
        IntNode* old = head;
        int result = old->ele;
        head = head->next;
        delete old;
        n--;
        if(empty()){
            tail = NULL;
        }
        return result;
    }
    int front() const {
        if(empty()){
            return -1;
        } else {
            return head->ele;
        }
    }
    int back() const {
        if(empty()){
            return -1;
        } else {
            return tail->ele;
        }
    }
};

int main(void){
    int n;
    cin >> n;
    SLinkedList q;
    while(n--){
        string userInput;
        cin >> userInput;
        if(userInput == "push") {
            int x;
            cin >> x;
            q.addBack(x);
        } else if (userInput == "pop") {
            cout << q.removeFront() << endl;
        } else if (userInput == "size") {
            cout << q.size() << endl;
        } else if (userInput == "empty") {
            cout << q.empty() << endl;
        } else if (userInput == "front") {
            cout << q.front() << endl;
        } else if (userInput == "back") {
            cout << q.back() << endl;
        }
    }
    return 0;
}