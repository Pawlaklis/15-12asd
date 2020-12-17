#include <iostream>
#include <vector>
struct Node{
    long long value;
    Node* next;
    Node* prev;
    Node* min;
    Node(long long t){
        value = t;
        prev = nullptr;
        next = nullptr;
        min = nullptr;
    }
    Node(Node* t){
        value = reinterpret_cast<long long>(t);
        prev = nullptr;
        next = nullptr;
        min = nullptr;
    }
};

class _1_28{
public:
    bool *T;
    Node *first;
    int size;
    _1_28(int n){
        size = n;
        T = new bool[n];
        for (int i = 0; i < n; ++i) {
            T[i] = false;
        }
    }
    ~_1_28(){
        delete []T;
    }
    void Select(){
        if(first!= nullptr){
            T[first->value] = -1;
            Node *temp = first;
            first = first->next;
            delete temp;
        }
    }
    bool Search(int i){
        return T[i];
    }
    void insert(int i){
        T[i] = true;
        Node *T = new Node(i);
        if (first != nullptr){
            T->next = first;
            first = T;
        } else
            first = T;
    }
    void print(){
        for (int i = 0; i < size; ++i) {
            if (T[i])
                std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

class _1_29{
public:
    Node* first;
    Node* *T;

    _1_29(int N){
        first = nullptr;
        T = new Node*[N];
        for (int i = 0; i < N; ++i) {
            T[i] = nullptr;
        }
    }
    ~_1_29(){
        while(first != nullptr){
            Node *t = first;
            first = first->next;
            delete t;
        }
    }
    void push(int i){
        Node *temp = new Node(i);
        Node *tempT = new Node(temp);
        if(first == nullptr)
            first = temp;
        else {
            temp->next = first;
            first = temp;
        }
        if(T[i] == nullptr){
            T[i] = tempT;
        } else{
            tempT->next = T[i];
            T[i] = tempT;
        }
    }
    void pop(){
        if (first != nullptr){
            Node *temp = first;
            first = first->next;
            Node *tempT = T[temp->value];
            T[temp->value] = tempT->next;
            delete tempT;
            delete temp;
        }
    }
    bool search(int i){
        return T[i] != nullptr;
    }
    void Delete(int i){
        if (T[i] != nullptr){
            Node *temp = reinterpret_cast<Node *>(T[i]->value);
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            } else{
                first = temp->next;
                if(first != nullptr)
                  first->prev = nullptr;
            }
            delete temp;
            Node *tempT = reinterpret_cast<Node *>(T[i]->value);
            T[i] = tempT->next;
            delete tempT;
        }
    }
    void print(){
        Node *T = first;
        while (T!= nullptr){
            std::cout << T->value << " ";
            T = T->next;
        }
        std::cout << std::endl;
    }
};

class _1_30{
public:
    Node *first;
    Node *min;
    _1_30(){
        first = nullptr;
        min = nullptr;
    }
    void push(int i){
        Node *T = new Node(i);
        if (first == nullptr){
            first = T;
            min = T;
            T->min = min;
        }
        else{
            first->prev = T;
            T->next = first;
            first = T;
            T->min = min;
            if(min->value < T->value)
                min = T;
        }
    }
    void pop(){
        if(first != nullptr){
            if(min != first){
                Node *t =first;
                first = first->next;
                first->prev = nullptr;
                delete t;
            } else{
                Node *t =first;
                first = first->next;
                first->prev = nullptr;
                delete t;
                if (first != nullptr){
                    min = nullptr;
                }
                else{
                    min = first->min;
                }
            }

        }
    }
    void uptomin(){
        if(first != nullptr){
            first = min->next;
            first->prev = nullptr;
            Node *t = min;
            if(first != nullptr)
                min = first->min;
            else
                min = nullptr;
            while (t != nullptr) { //język C++ wymaga w tym miejscu liniowego dekonstruktora, gdyż doszłoby do wycików pamięci przy braku takiego rozwiązania
                Node *T = t->prev;
                delete t;
                t = T;
            }

        }
    }
    void print(){
        Node *T = first;
        while (T!= nullptr){
            std::cout << T->value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    _1_28 object0(20);
    _1_29 object1(20);


    object0.insert(1);
    object0.insert(2);
    object0.insert(3);
    object0.print();
    object1.push(1);
    object1.push(2);
    object1.push(3);
    object1.pop();
    object1.print();
    return 0;
}
