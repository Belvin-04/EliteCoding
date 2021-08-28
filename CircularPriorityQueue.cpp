#include<iostream>
using namespace std;
class Node{
    public:
        string name;
        Node *next;
        int priority;
        Node(string name,int priority){
            this->name = name;
            this->priority = priority;
            this->next = NULL;
        }
};

class CircularQueue{
    Node *front,*rear;
    public:
        CircularQueue(){
            front = rear = NULL;
        }
        ~CircularQueue(){

        }
        void enqueue(string name,int priority){
            Node *temp = new Node(name,priority);
            if(front == NULL && rear == NULL){
                front = rear = temp;
                temp->next = front;
            }
            else{
                Node *rearPointer = rear;
                while(rearPointer->next != front){
                    rearPointer = rearPointer->next;
                }
                rearPointer->next = temp;
                temp->next = front;
                rear = temp;
            }
        }
        string dequeue(){
            if(front == NULL && rear == NULL){
                return "Queue is Empty";
            }
            else if(front == rear){
                string name = front->name;
                delete front;
                front = rear = NULL;
                return name;
            }
            else{
                string name = front->name;
                Node *temp = front;
                front = front->next;
                rear->next = front;
                delete temp;
                return name;
            }
        }
        void printQueue(){
            if(front == NULL && rear == NULL){
                cout << "Queue is Empty";
            }
            else{
                Node *rearPointer = front;
                while(rearPointer != rear){
                    cout << rearPointer->name <<"->";
                    rearPointer = rearPointer->next;
                }
                cout << rearPointer->name;
            }
        }
};

int main(){
    CircularQueue queue;
    queue.enqueue("ABC",0);
    queue.enqueue("BCD",0);
    queue.enqueue("EFG",0);
    queue.enqueue("HIJ",0);
    queue.enqueue("KLM",0);

    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;

    queue.printQueue();
    
}