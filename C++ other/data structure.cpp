#include <iostream>
#include <string>
#include <limits>
#include <memory>
#include <algorithm>

class Color {
public:
    //  (Foreground)
    static inline const std::string RESET   = "\033[0m";
    static inline const std::string BLACK   = "\033[30m";
    static inline const std::string RED     = "\033[31m";
    static inline const std::string GREEN   = "\033[32m";
    static inline const std::string YELLOW  = "\033[33m";
    static inline const std::string BLUE    = "\033[34m";
    static inline const std::string MAGENTA = "\033[35m";
    static inline const std::string CYAN    = "\033[36m";
    static inline const std::string WHITE   = "\033[37m";

    //(Bold/Bright)
    static inline const std::string BOLD_RED     = "\033[1;31m";
    static inline const std::string BOLD_GREEN   = "\033[1;32m";
    static inline const std::string BOLD_YELLOW  = "\033[1;33m";
    static inline const std::string BOLD_BLUE    = "\033[1;34m";

    //Background
    static inline const std::string BG_RED      = "\033[41m";
    static inline const std::string BG_GREEN    = "\033[42m";
    static inline const std::string BG_YELLOW   = "\033[43m";
    static inline const std::string BG_BLUE     = "\033[44m";
};

class Node{
private:
double data;
Node* next;
public:
void setdata(double dat){data=dat;}
void setnext(Node* nex){next=nex;}
double getdata(){return data;}
Node* getnext(){return next;}

Node() : data(0), next(nullptr) {}
};
class linkedlist {
private:
Node* head;
public :
linkedlist (){
head=NULL;
}
void deletenode (double item){
Node* del = search(item);
if (del==nullptr) return;
if (head==del){
    head=head->getnext();
    delete del;
    del=nullptr;
return;
}
else{
Node *temp=head;
while (temp->getnext()!=nullptr){
if(temp->getnext()==del){
temp->setnext(del->getnext());
delete del;
del=nullptr;
return;
}
    temp=temp->getnext();
}


}


}
bool isempty(){

return (head==NULL);
}
bool isfound(double item){
Node* temp=head;
while (temp!=NULL){
    if(temp->getdata()==item){
        return true;
    }
            temp=temp->getnext();

}
return false;


}
void insert(double dat) {

    Node* newnode = new Node(); 
    newnode->setdata(dat);
    newnode->setnext(head);      
    head = newnode;              
    
}
void display (){
Node *temp=head;
if (!isempty()){
while (temp!=NULL){
std::cout<<temp->getdata()<<"\n";
temp=temp->getnext();
}
}
else
std::cout<<"list is empty \n";



}
int count(){
Node *temp=head;
int cou=0;
while (temp!=NULL){
cou++;
temp=temp->getnext();

}
return cou;
}
 Node* search(double item){

    Node *temp=head;
    while (temp!=NULL){
if(item==temp->getdata())
return temp;
        temp=temp->getnext();

    }
    return nullptr;

}
void insertbefore(double insert,double data){
    Node* newnode =new Node;
    newnode->setdata(data);
    Node* temp=head;
    Node* insert1=search(insert);
        if (insert1==nullptr){
        std::cout<<"not found ";
        return;
    }

if (head==insert1){
newnode->setnext(insert1);
head=newnode;
return;
}

    else
    while (temp!=insert1){
        if(temp->getnext()==insert1){
newnode->setnext(insert1);
temp->setnext(newnode);
return;
        }
  temp=temp->getnext();      
        
    }
}
void replace(double old, double item) {
    Node* target = search(old);
    if (target == nullptr) { std::cout << "not found\n"; return; }
    target->setdata(item); // ✅ غيّر الداتا في نفس الـ node
}void append(double item){
    Node *newnode=new Node;
    if (isempty()){ insert(item); return;}
   Node *temp=head;
while (temp!=NULL){
if (temp->getnext()==NULL){
    newnode->setdata(item);
    newnode->setnext(NULL);
    temp->setnext(newnode);
    return;
}
    temp=temp->getnext();
}    

}

};
class Stack {
private:
Node* top;
public:
Stack (){top=NULL;}
bool isempty(){
    if (top==NULL)
    return true;
    else return false;

}
void puch (double item){
Node* newnode=new Node;
newnode->setdata(item);
newnode->setnext(top);
top=newnode;

}


void display() {
Node* temp=top;
while (temp!=NULL){
    std::cout<<temp->getdata()<<" \n        \n";
    temp=temp->getnext();

}

}

double pop (){
    if (isempty()){
        std::cout<<"stack is empty";
        return -1;
    }
    double value;
Node* temp=top;

top=top->getnext();
value=temp->getdata();
delete temp;
return value;

}
double peak(){
    if(isempty())
std::cout<<"Stack is empty";    
 else   
    return top->getdata();
}
int count (){
    int counter=0;
    Node* temp=top;
while (temp!=NULL){
counter++;
    temp=temp->getnext();
}
return counter; 

}
void search (double item) {
    
    int count=0;
Node* temp=top;
while (temp!=NULL){
if (temp->getdata()==item){
std::cout<<"item found \n "<<count<<"elements left to reach \n";
return;
}
    temp=temp->getnext();
count++;

}

}
void opposite (){
    if (isempty()|| top->getnext()==NULL) return;

Node *next=nullptr;
Node* per=nullptr;
Node *current=top;

while(current!=NULL){
    next=current->getnext();
    current->setnext(per);
    per=current;
    current=next;
}
top=per;
    
}
void clear (){
while (!isempty()) pop();
}

~Stack() {
    clear ();
}
};
class Queue {
private:
Node* front;
Node* back;
public:
Queue (){front=back=NULL;}
bool isempty (){ return (front==NULL);}
void enqueue(double item){
    Node *newnode=new Node;
    newnode->setdata(item);
    if (isempty()){front=back=newnode;  }
else{
back->setnext(newnode);
back=newnode;
}
}
void display (){
    if (isempty()){
std::cout<<"Queue is empty \n";
return;

    }
Node* temp=front;
while(temp!=NULL){
std::cout<<temp->getdata()<<std::endl;
temp=temp->getnext();

}

}
double dequeue(){
double value;

        if (isempty()){  std::cout<<"queue is empty"; return -1;}
        else if (front==back){
value=front->getdata();
            delete front ;
            front=back=NULL;
            return value;
        }
else{
Node *del=front;

value=del->getdata();
front=front->getnext();
delete del;
return value;

}
}
double peek(){
    if (isempty()){  std::cout<<"queue is empty"; }
    
    return front->getdata();
}
int count(){
int counter=0;
Node* temp=front;
while (temp!=NULL){
    counter++;
    temp=temp->getnext();
}
return counter;
}
bool isfound (double item){
        if (isempty()){  std::cout<<"queue is empty"; }
Node* temp=front;
while (temp!=NULL){
    if (temp->getdata()==item)
return true;
    
    temp=temp->getnext();
}
return false;
}
void search(double item){
    if (isempty()){  std::cout<<"queue is empty"; }
    Node* temp=front;
    int counter=0;
while (temp!=NULL){
    if (temp->getdata()==item){
std::cout<<"found and left"<<counter<<"to it";
return;
    } 
    temp=temp->getnext();
    counter++;
}


}
void clear(){
while(!isempty()){
    dequeue ();
}
}
~Queue (){clear();}
};
class BST {
private:
struct Node1 {
private:
double data;
Node1 *right;
Node1 *left;
public:
Node1(){
data=0;
right=left=NULL;

}
void setdata(double item){data=item;}
void setright(Node1 *item){right=item;}
void setleft(Node1 *item){left=item;}
Node1* getright(){return right;}
 Node1* getleft(){return left;}
 double getdata(){return data;}

};

Node1* root;


Node1* Insert(Node1* r,double item){
if(r==nullptr){
Node1* newnode= new Node1;
newnode->setdata(item);
return newnode;
}
else {
if(item>=r->getdata())
    r->setright(Insert(r->getright(),item));

else
    r->setleft(Insert(r->getleft(),item));
return r;


}
} 

void Inorder(Node1* r){ //left..root..right
if (r==NULL)
return;
Inorder(r->getleft());
std::cout<<r->getdata()<<"\t";
Inorder (r->getright());


}
void Preorder (Node1* r){ //root left right
if (r==NULL)
return;
std::cout<<r->getdata()<<"\t";
Preorder(r->getleft());
Preorder (r->getright());


}
void Postorder (Node1* r){// left right root
if (r==NULL)
return;
    Postorder(r->getleft());
Postorder (r->getright());
std::cout<<r->getdata()<<"\t";


}
Node1* Search(Node1* r,double item){
    if (r==NULL)
return NULL;
if(item==r->getdata())
return r ;
if (item>=r->getdata())
return Search (r->getright(),item);
if (item<r->getdata())
return Search(r->getleft(),item);
return NULL;

}
Node1 *Findmin(Node1 *r){
    if(r==NULL)
    return NULL;
if (r->getleft()==NULL)
return r;
r=Findmin(r->getleft());
return r;
}

Node1 *Findmax(Node1 *r){
if(r==NULL)
return NULL;
if(r->getright()==NULL)
return r;
r=Findmax(r->getright());
return r;

}
Node1 *Delete(Node1 *r,double item){
if (r==NULL)
return NULL;
if(item>r->getdata())
r->setright(Delete (r->getright(),item));
else if(item<r->getdata())
r->setleft(Delete (r->getleft(),item));
else{
if(r->getleft()==NULL&&r->getright()==NULL){
delete r;
r=NULL;
return r;
}

else if(r->getleft()==NULL){
Node1 *temp=r->getright();
delete r;
return temp;
}
else if(r->getright()==NULL){
Node1 *temp=r->getleft();
delete r;
return temp;
}
else{
Node1 *temp=Findmin(r->getright());
r->setdata(temp->getdata());
r->setright(Delete (r->getright(),temp->getdata()));

}


}
return r;

}

 

    public:
    BST(){root=NULL;}
    bool isempty(){return root==NULL;}
void Insert (double item) { root=Insert(root,item);}
bool search (double item){
    if (Search(root,item)==NULL)
    return false;
    else 
    return true;
}
void inorder (){Inorder(root);}
void preorder (){Preorder(root);}
void postorder (){Postorder(root);}
double findmin(){
    Node1 *r=Findmin(root);
  if (r==NULL)  
    return 0;
    return r->getdata();
}
double findmax(){

    Node1 *r=Findmax(root); 
      if (r==NULL)  
    return 0;
    return r->getdata();
}
bool deleteitem(double item){
    if(search(item)){
root=Delete (root,item);
return true;
    }
    else return false;
}
};
class Hash_table{
private:
struct Node1{
double data;
int key;
Node1* next;
Node1(){data=0; key=0; next=nullptr;}
};
Node1* *table;
int per;
int hashfuction(int key){return (key)%per;}
void collision(Node1* r){
int count=0;
while (r!=nullptr){
count++;
r=r->next;
}
    if(count>=10){
rehash(per+15);
    }


} //put it after the chain you make in it a newnode if tha chain bigger thqn 10 resize tha table and rech all the items in the teble
void rehash(int newper){
Node1** newtable=new Node1* [newper] ;
for (int i=0;i<newper;i++){
newtable [i]=nullptr;
}
int oldper=per;
per=newper;
for (int i=0;i<oldper;i++){
Node1* temp=table[i];
while(temp!=nullptr){
Node1 *next=temp->next;
int newindex=hashfuction(temp->key);
temp->next=newtable[newindex];
newtable[newindex]=temp;
temp=next;
}
}
delete [] table;
table=newtable;
}

Node1 *Search(int key){
int index=hashfuction(key);
Node1* temp=table[index];
while(temp!=nullptr){
    if(key==temp->key)
    return temp;
    temp=temp->next;
}
return nullptr;
}

public:
Hash_table(){
    per=15;
table=new Node1*[per];
for (int i=0;i<15;i++)
table[i]=nullptr;
}
void insert (double item,int key){
    Node1 *newnode=new Node1;
newnode->data =item;
newnode->key=key;
int index=hashfuction(key);
if(table [index]==nullptr){
table [index]=newnode;
return;
}
if (table [index]->key==key){
    table[index]->data=item;
    delete newnode;
    return;
}
Node1 *temp=table[index];
while (temp!=nullptr){
if (temp->key==key){
temp->data=item;
delete newnode;
return;
}
if (temp->next==nullptr){
temp->next=newnode;
return;
}
temp=temp->next;
}


}
double search (int key){
    Node1 *temp=Search (key);
    if(temp==nullptr)
    return 0;
    return temp->data;
}
void expand(){rehash(per*2);}
void deleteelment(int key) {
    int index = hashfuction(key);
    if (table[index] == nullptr) return;

    
    if (table[index]->key == key) {
        Node1* temp = table[index];
        table[index] = table[index]->next;
        delete temp;
        return;
    }

    
    Node1* prev = table[index];
    Node1* curr = prev->next;
    while (curr != nullptr) {
        if (curr->key == key) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}void display(){
for (int i=0;i<per;i++){
    Node1 *temp=table [i];
    while(temp!=nullptr){
std::cout<<"Key :"<<temp->key<<"   Data :"<<temp->data<<"\n";
temp=temp->next;
    }
}
}
void clear(){
    for(int i=0;i<per;i++){
        Node1 *temp=table[i];
        while(temp!=nullptr){
            Node1* next=temp->next;
            delete temp;
            temp=next;
        }
    }
}
~Hash_table (){clear (); delete [] table;}
};
int getInt(const std::string& prompt);
double getDouble(const std::string& prompt);



int main (){

}

int getInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.good()) {
            return value;  // input صح
        }

        std::cin.clear();  // امسح الـ fail state
        std::cin.ignore(    // امسح الـ buffer كله
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
        std::cout << "خطأ — أدخل رقم صحيح.\n";
    }
}
double getDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.good()) return value;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "خطأ — أدخل رقم.\n";
    }
}
