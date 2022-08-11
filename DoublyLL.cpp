#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;


    //constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for Node with Data: "<<val<<endl;
    }
};


void print(Node* head, Node* tail){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    cout<<endl;
}


int getlen(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head, int d){
    if(head == NULL){  //if head null at start, No node
       Node* temp = new Node(d);
       head = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, int d){
    if(tail == NULL){   //if tail null at start
        Node* temp = new Node(d);
        tail = temp;
    }
    else{
     Node* temp = new Node(d);
     tail->next = temp;
     temp->prev = tail;
     tail = tail->next;    //tail = temp;
    }
}

void insertAtPos(Node* &head, Node* &tail, int position, int d){

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
   temp->next->prev = nodeToInsert;
   temp->next = nodeToInsert;
   nodeToInsert->prev = temp;

}

void deletenode(Node* head, int position){
    if(position==1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any mid node or last node;
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main(){
    system("CLS");
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 1);
    insertAtTail(tail, 21);
    insertAtPos(head, tail, 2, 37);
    insertAtPos(head, tail, 2, 40);
    deletenode(head, 3);
    deletenode(head, 4);

    print(head, tail);
    cout<<"Length of Linked List: "<<getlen(head);

    return 0;
}
