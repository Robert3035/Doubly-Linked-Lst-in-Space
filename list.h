struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(){
        this->val = '0';
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int v){
        this->val = v;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int v, Node n){
        this->val = v;
        this->next = &n;
    }
};

class List{
    private:
        Node* front; //points to the front of list
        Node* back; //points to the back of the list
        Node* it; //points to the current node
        int size; // gives size
        bool empty;
    public:
        List(){
            this->front;
            this->back;
            this->it = front;
            this->size = 0;
        }
        List(int v){
            Node n(v);
            this->front = &n;
            this->back = &n;
            this->it = &n;
            this->size = 1;
        }
        int get_iterator(){//Return the value at the iterator
            if(it == nullptr){
                return ']';
            }
            else
                return it->val;
        }
        bool isEmpty(){//Checks whether the list is empty and returns a boolean
            if(front == nullptr){
                return true;
            }
        }
        void begin(){//Moves the iterator to the front of the list
            it = front;
        }
        void end(){//Moves the iterator to the end of the list
            while(it->next != nullptr){
                it = it -> next;
            }
        }
        int getFront(){//Returns the value that front is pointing at
            return front->val;
        }
        int getBack(){//Returns the value that back is pointing at
            return back->val;
        }
        void push_front(int x){//Creates a new node at the beginning of the list
            Node temp(x, *front);
            front = &temp;
            size++;
        }
        void push_back(int x){
            Node temp(x, *back);
            back = &temp;
            size++;
        }
        void pop_front(){//Clears the node at the front of the list
            Node *temp = front;
            front = front->next;
            front->prev = nullptr;
            delete temp;
        }
        void insert_after(int x){
            //Creates new node and temp pointer to help us insert it
            if(it->next != nullptr){
                Node* temp = new Node(x);
                temp->next = it->next;
                it->next = temp;
                it = temp;
            }
            else{
                Node* temp = new Node(x);
                it->next = temp;
                it = temp;
            }
            size++;
        }
        void insert(int x){
            it = front;
            while(it->next != nullptr){
                if(x > it->val){
                    it = it->next;
                }
                else if(x < it->val){
                    Node* temp = new Node(x);
                    temp->prev = it->prev;
                    temp->next = it;
                    it->prev = temp;
                    it = temp->prev;
                    it->next = temp;
                    it = temp;
                }
            }
        }
        void clear(){//Clears the list
            front = nullptr;
            it = nullptr;
            back = nullptr;
            //All pointers don't point at anything, losing all of the nodes and clearing the list
        }
        void move_up(){//Moves the iterator up in the list
            if(it->next != nullptr){
                it = it -> next;
            }
        }
        void move_back(){//Moves the iterator back in the list
            if(it->prev != nullptr){
                it = it->prev;
            }
        }
};