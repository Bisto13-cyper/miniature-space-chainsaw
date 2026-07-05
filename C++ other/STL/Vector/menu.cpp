#include<string>
#include<iostream>
#include<fstream>
#include <limits>
#include "menu.h"
#include "Vector.h"
#include<algorithm>

int getInt(const std::string& prompt) {
int value;
while (true) {
std::cout << prompt;
std::cin >> value;
if (std::cin.good()) {
return value;  // input صح
 }

std::cin.clear();  
std::cin.ignore(    
std::numeric_limits<std::streamsize>::max(), '\n'
);
std::cout<<"Please Enter number";
}
}
void listmenu(List* list){
static std::string Pas=""; //make Password in Class
if(Pas==""){}
else{
std::cout<<"Enter list's password \n";
std::string check;
std::getline(std::cin,check);
if(Pas==check) std::cout<<"Wellcome Back \n";
else {std::cout<<"Wrong Password";return;}
}
std::cout<<"Hello to "<<list->getkey()<<"To Do list \n";
while(true){
std::cout<<"1-Add task \n2-Show tasks \n3-delete task  \n4-make task done \n5-Show done tasks \n6-show deleted \n7-restart task \n8-clear done \n9-clear deleteed  \n10-clear list cache \n11-setings \n12-show next task \n13-show last task\n14-edit task\n15-search for task \n16-sorting tasks\n-0 Exit\n";
int ch=getInt("");
if (ch==0) break;
if((ch==2||ch==3||ch==4)&&list->Tempty()){std::cout<<"Add new tasks first \n"; continue;}
if((ch==5||ch==8)&list->Dempty()) {std::cout<<"Add new done tasks first \n"; continue;}
if((ch==6||ch==9)&!list->issave()){std::cout<<"Delete file is turned off\n"; continue;}
if((ch==6||ch==9)&list->Oempty()) {std::cout<<"Delete new tasks first \n"; continue;}
if(ch==7&list->Dempty()&list->Oempty()){std::cout<<"No tasks to restart \n"; continue;}
if(ch==8||ch==9||ch==10){
    std::cout<<"Are you sure to "<<Color::RED<<"Delete "<<Color::RESET<<"(y/n)\n";
    char S;
std::cin>>S;
if (S=='Y'||S=='y'){std::cout<<"Deleted !\n";}
else if(S=='N'||S=='n'){continue;}
}

switch (ch){
case 1: {
std::string task;
std::cout<<"                              \t\t Press * to stop writing                      \n";
std::cout<<"Enter Task  [ ";
std::getline(std::cin,task,'*');
list->add(task);
}break;
case 2: list->show();
break;
case 3:{
list->show();
std::cout<<"which task want you to delete it ?      ";
int del=getInt("");
if (list->found(del-1)) {list->del(del); std::cout<<"Task have been deleted \n";}
else std::cout<<"Wrong Input \n"; 
}break;
break;
case 4:{
list->show();
std::cout<<"Whoch task you've done \t";
int done=getInt("");
list->setdone(done);
}break;
case 5: list->showdone();
break;
case 6:list->showold();
break;
case 7:list->restart();
break;
case 8:list->clearD();
break;
case 9:list->clearO();
break;
case 10:list->clearmemory();
break;
case 11:set(list,Pas);
case 12:std::cout<<"Next Task is {"<<list->next()<<"}\n";
case 13:std::cout<<"last Task is {"<<list->last()<<"}\n";
case 14:{
    int index;
list->show();
    std::cout << "Enter task number to edit: ";
     index=getInt("");
    if(list->found(index-1)){std::cout<<"Not found \n"; break;}
    std::cout << "Current Text: " << list->gettext(index-1) << "\n";
    
    std::cout << "Enter the new text: ";
    std::string newText;
    std::getline(std::cin, newText);
    
    list->edit(index-1, newText);
    std::cout << "Task updated successfully!\n";
}break;

case 15:{
std::cout<<"Enter words to find them \n";
std::string target;
std::getline(std::cin, target);
std::vector<std::string>found=list->search(target);
if (found.empty()) std::cout<<"found No task \n";
else {
int num=0;
for(auto X:found){
std::cout<<num<<"-"<<X;
}
}

}break;
case 16:{
std::cout<<"Enter 0 to exit \n";
while(true){
list->show();
int s=getInt("You want task Number ... ");
if (s==0)break;
int d=getInt("To be Number ... ");
if (d==0)break;
list->setpro(s-1,d-1);
}


}

}


}
}
void set(List* list,std::string& Pas){
std::cout<<"Hello Admin list to list settings \n";
while(true){
std::cout<<"What do want \n1-edit list name \n2set default save deletes \n3-";
if(Pas=="")std::cout<<"set list Password\n";
else std::cout<<"edit list Password or delete it\n";
std::cout<<"4-show tasks default \n5-set goal \n6-clear list !\n";
int ch=getInt("");
if(ch==0){break;}
switch (ch){
case 1:{
std::string N;
std::cout<<"Current name is :"<<list->getkey()<<" \n Enter new name\t\t ";
std::getline(std::cin,N);
list->setkey(N);
}break;
case 2: 
std::cout<<"When deleting task you want 1-save it in deleted 2-don't save it\n";
int S=getInt("");
if(S==1){list->saving(true); "New settings Saved \n";}
else if(S==2){list->saving(false); "New settings Saved \n"; list->clearD();}
else std::cout<<"Wrong Input \n";
break;
case 3:{
std::string MS,pas;
std::cout<<"Enter new password  exit(0) delete current password (1)\n ";
if(pas=="0") break;
if(pas=="1") {pas="";std::cout<<"Deleted!\n";}
std::getline(std::cin,pas);
std::cout<<"Enter again \n";
std::getline(std::cin,MS);
if(MS==pas){Pas=pas;std::cout<<"Done \n";}
else std::cout<<"Wrong !\n";
}break;
case 4:{
std::cout<<"Do want see Task from (start to end [1]) Or (end to start[2])\n";
int R=getInt("");
if(R==1){list->reverse(false);}
else if(R==2){list->reverse(true);}
else std::cout<<"Wrong Input \n";
}
case 5:{
std::cout<<"How many tasks you'll add?\n";
int add=getInt("");
std::cout<<"How many task you wanna done\n";
int done=getInt("");
list->setwant(add,done);
}

case 6:list->clear(); Pas="";
}
}
}
void menu(std::vector <List*> lists){

//check here
loaddata(lists);
int ch;
while(true){
std::cout<<"Hello to Bisto To Do List \n1-creat new list \n2-open old list \n3-Show lists  \n4-clear cache\n5-swap To Do lists\n6-edit name\n7-delete list \n0-exit\n";
ch=getInt("");
if(ch==0){ 
std::getline(data, line)if(ch==2&&lists.empty()){std::cout<<"Please add lists first \n"; continue;}
switch (ch){
    case 1 :{
        std::cout<<"Enter list's name\n";
        std::string name;
        std::cin.ignore();
        std::getline(std::cin,name);
         List* newl=new List(name);
        lists.push_back(newl);
        std::cout<<"Adeed !\n";
        std::sort(lists.begin(),lists.end());
    }
    break;
    case 2:{
            std::cout<<"Lists : "<<lists.size()<<" list \n";
            int I=1;
        for (auto x:lists){
        std::cout<<I<<"-"<<x->getkey()<<"\n"; I++;
        }
        while (true){
int ch=getInt("Select list  ");
if(ch>lists.size() || ch<=0){std::cout<<"Wrong list \n"; continue;}
else {
listmenu(lists[(ch-1)]);
break;
}
}
    }
    break;
    case 3:
        std::cout<<"Lists : "<<lists.size()<<" list \n";
        for (auto x:lists){
        std::cout<<x->getkey()<<"\n";
}
    
    break;
    case 4: 
for (auto it:lists){it->clearmemory();}
case 5:
    for (auto x:lists){
    std::cout<<x->getkey()<<"\n";
    }
std::cout<<"Select two lists to swap \n";
int l1=getInt("First: ");
int l2=getInt("Second: ");
std::swap(lists[l1-1],lists[l2-1]);
case 6:{
    int i=1;
    for (auto x:lists){
    std::cout<<i<<"-"<<x->getkey()<<"\n";
    i++;
    }
std::cout<<"Which list you wanna edit it \n";
int edit=getInt("");
std::string Edit;
std::cout<<"Enter new name \n";
std::getline(std::cin,Edit);
lists[edit-1]->setkey(Edit);

}
case 7:
int i=1;
    for (auto x:lists){
    std::cout<<i<<"-"<<x->getkey()<<"\n";
    i++;
    }
std::cout<<"Which list you wanna delete\n";
int del=getInt("");
auto it=lists.begin()+(del-1);
lists.erase(it);
}

}
}
void loaddata(std::vector<List*>& list){
std::ifstream data("lists.txt");
if (data.is_open()){
std::string line;
std::getline(data,line);
if(line=="09996718"){
while(true){
std::getline(data,line,'|');
List* newlist = new List(line);
std::getline(data,line,'|');
bool dat=false;
if(line=="1")dat=true;
newlist->reverse(dat);
std::getline(data,line,'|');
dat=false;
if(line=="1")dat=true;
newlist->saving(dat);
std::getline(data,line);
dat=false;
if(line=="1")dat=true;
newlist->addwant(dat);
std::getline(data,line);
while(std::getline(data, line),line!="Done:"){
std::getline(data,line);
newlist->add(line);
}
while(std::getline(data, line),line!="Old:"){
std::getline(data,line);
newlist->adddone(line);
}
while(std::getline(data, line),line!="End"){
std::getline(data,line);
newlist->addold(line);
}
list.push_back(newlist);
std::getline(data,line);
std::string check;
std::getline(data,check);
if(line=="09996710"&&check=="09996718")
continue;
else break;
}

}
data.clear();
data.close();

}
else
std::cout<<"Error while reading the file \n";



}

