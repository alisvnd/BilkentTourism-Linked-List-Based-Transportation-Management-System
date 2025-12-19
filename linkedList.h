#ifndef LINKED_LIST_H
#define LINKED_LIST_H


template <typename T>
class linkedList {

public:
    struct Node{
        T data;
        Node* next;
        Node(T obj) : data(obj), next(nullptr) {} 
    };

private:
    Node* head;
    int size;

public:
    
    linkedList() : head(nullptr), size(0) {}

    ~linkedList(){
        Node* current = head, *temp;
        while (current){
            temp = current->next;
            delete current;
            current = temp;
        }
        head = nullptr;
        size = 0;
    }

    const Node* getHead() const {
        return head;
    }

    int getSize() const{
        return size;
    }

    bool addSorted(const T& obj){
        Node* newNode = new Node(obj);
        if(!head){
            head = newNode;
            size++;
            return true;
        }
        else{
            if (head->data.getId() == obj.getId()){
                delete newNode;
                return false;
            }
            else if(head->data.getId() > obj.getId()){
                newNode->next = head;
                head = newNode;
                size++;
                return true;
            }
            else{
                Node* current = head;
                while(current->next){
                    if(current->next->data.getId() == obj.getId()){
                        delete newNode;
                        return false;
                    }
                    if(current->next->data.getId() > obj.getId()){
                        break;
                    }
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
                size++;
                return true;
            }
        }
    }

    bool remove(int id){
        if(!head){
            return false;
        }
        if(head->data.getId() == id){
            Node* temp = head->next;
            delete head;
            head = temp;
            size--;
            return true;
        }
        Node* prev = head, *current = head->next;
        while (current){
            if (current->data.getId() > id){
                return false;
            }
            else if (current->data.getId() == id){
                prev->next = current->next;
                delete current;
                size--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    T* getById(int id) const{
        Node* current = head;
        while(current){
            if (current->data.getId() == id){
                return &(current->data);
            }
            else if (current->data.getId() > id){
                return nullptr;
            }
            current = current->next;
        }
        return nullptr;
    }

    bool contains(int id) const {
        Node* current = head;
        while(current){
            if (current->data.getId() == id){
                return true;
            }
            else if (current->data.getId() > id){
                return false;
            }
            current = current->next;
        }
        return false;
    }
};

#endif