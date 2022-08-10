#include<iostream>
#include<stdio.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data: "<<value<<endl;
    }
};


void insertAtHead(Node* &head, int d){
        //new node create
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}


void insertAtPos(Node* &tail, Node* &head, int position, int d){
   //Inserting at 1st position
   if(position == 1){
    insertAtHead(head, d);
    return;
   }

   Node* temp = head;
   int cnt = 1;
   while(cnt<position-1){
    temp = temp->next;
    cnt++;
   }

   //Inserting at Last position
   if(temp->next == NULL){
    insertAtTail(tail, d);
    return;
   }

   //creating a node for d
   Node* nodeToInsert = new Node(d);
   nodeToInsert->next = temp->next;
   temp->next = nodeToInsert;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deletenode(int position, Node* &head){
    //deleting head node
    if(position==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt=1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
}

int main(){

    system("CLS");
    Node* node1 = new Node(10);


    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtHead(head, 12);
    insertAtTail(tail, 15);
    insertAtPos(tail, head, 3, 22);
    insertAtPos(tail, head, 1, 5);
    insertAtPos(tail, head, 6, 30);

    print(head);

    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;
    deletenode(1, head);
    cout<<"head: "<<head->data<<endl;
    //Traversing whole List
    print(head);


    return 0;
}
