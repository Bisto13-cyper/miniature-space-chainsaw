#include<string>
#include<iostream>
#include<fstream>
#include <limits>
#include "menu.h"
#include "Vector.h"
#include<algorithm>
#include <filesystem>
#include <memory>
bool chrepet(const std::vector<std::unique_ptr <List>>& lists,std::string name){ 
    if(name.empty()){std::cout<<"Can't Add  space\n"; return false;}
    for (const auto& it:lists){if(it->getkey()==name) 
{ std::cout<<"Name is found\n"; return false;}
        }
    return true;
}
void creatlist(std::vector<std::unique_ptr <List>>& lists){        std::cout<<"Enter list's name\n";
        std::string name;
        std::cin.ignore();
        std::getline(std::cin,name);
        if(!chrepet(lists,name)) return;
        lists.push_back(std::make_unique<List>(name));
        std::cout<<"Adeed !\n";
    
        //std::sort(lists.begin(),lists.end());
}
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
void listmenu(std::unique_ptr <List>& list){
if(!list->ispas()){}
else{
std::cout<<"Enter list's password \n";
std::string check;
std::getline(std::cin,check);
if(list->checkpas(check)) std::cout<<"Wellcome Back \n";
else {std::cout<<"Wrong Password";return;}
}
std::cout<<"Hello to "<<list->getkey()<<"To Do list \n";
while(true){
std::cout<<"1-Add task \n2-Show tasks \n3-delete task  \n4-make task done \n5-Show done tasks \n6-show deleted \n7-restart task \n8-clear done \n9-clear deleteed  \n10-clear list cache \n11-setings \n12-show next task \n13-show last task\n14-edit task\n15-search for task \n16-sorting tasks\n17-Save \n-0 Exit\n";
int ch=getInt("");
if (ch==0) break;
if((ch==2||ch==3||ch==4)&&list->Tempty()){std::cout<<"Add new tasks first \n"; continue;}
if((ch==5||ch==8)&&list->Dempty()) {std::cout<<"Add new done tasks first \n"; continue;}
if((ch==6||ch==9)&&!list->issave()){std::cout<<"Delete file is turned off\n"; continue;}
if((ch==6||ch==9)&&list->Oempty()) {std::cout<<"Delete new tasks first \n"; continue;}
if(ch==7&&list->Dempty()&&list->Oempty()){std::cout<<"No tasks to restart \n"; continue;}
if(ch==8||ch==9){
    std::cout<<"Are you sure to "<<Color::RED<<"Delete "<<Color::RESET<<"(y/n)\n";
    char S;
std::cin>>S;
if (S=='Y'||S=='y'){std::cout<<"Deleted !\n";}
else if(S=='N'||S=='n'){continue;}
}
if((ch==12||ch==13)&&list->Tempty()){std::cout<<"List is empty\n"; continue;}
switch (ch){
case 1: {
std::string task;
std::cout<<"                              \t\t Press * to stop writing                      \n";
std::cout<<"Enter Task  [ ";
std::cin.ignore();
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
case 11:set(list);
break;
case 12:std::cout<<"Next Task is {"<<list->next()<<"}\n";
break;
case 13:std::cout<<"last Task is {"<<list->last()<<"}\n";
break;
case 14:{
    int index;
list->show();
    std::cout << "Enter task number to edit: ";
     index=getInt("");
    if(!list->found(index-1)){std::cout<<"Not found \n"; break;}
    std::cout << "Current Text: " << list->gettext(index-1) << "\n";
    
    std::cout << "Enter the new text: ";
    std::string newText;
    std::cin.ignore();
    std::getline(std::cin, newText);
    
    list->edit(index-1, newText);
    std::cout << "Task updated successfully!\n";
}break;

case 15:{
std::cout<<"Enter words to find them \n";
std::string target;
std::cin.ignore();
std::getline(std::cin, target);
std::vector<std::string>found=list->search(target);
if (found.empty()) std::cout<<"found No task \n";
else {
int num=0;
for(auto X:found){
std::cout<<num<<"-"<<X<<"\n";
num++;
}
}

}break;
case 16:{
while(true){
std::cout<<"Enter 0 to exit \n";
list->show();
int s=getInt("You want task Number ... ");
if (s==0)break;
if(!list->found(s-1)){std::cout<<"Wrong number\n";break;}
int d=getInt("To be Number ... ");
if (d==0)break;
if(!list->found(d-1)){std::cout<<"Wrong number\n";break;}
list->setpro(s-1,d-1);
}


}break;
case 17:
list->Savedata();
std::cout<<Color::GREEN<<"Saved !\n"<<Color::RESET;
}


}
}
void set(std::unique_ptr <List>& list){
std::cout<<"Hello Admin list to list settings \n";
while(true){
std::cout<<"What do want \n1-edit list name \n2set default save deletes \n3-";
if(!list->ispas())std::cout<<"set list Password\n";
else std::cout<<"edit list Password or delete it\n";
std::cout<<"4-show tasks default \n5-set goal \n6-clear list !\n0-Exit";
int ch=getInt("");
if(ch==0){break;}
switch (ch){
case 1:{
std::string N;
std::cout<<"Current name is :"<<list->getkey()<<" \n Enter new name\t\t ";
std::cin.ignore();
std::getline(std::cin,N);
list->setkey(N);
}break;
case 2: {
std::cout<<"When deleting task you want 1-save it in deleted 2-don't save it\n";
int S=getInt("");
if(S==1){list->saving(true); "New settings Saved \n";}
else if(S==2){list->saving(false); "New settings Saved \n"; list->clearD();}
else std::cout<<"Wrong Input \n";}
break;
case 3:{
    std::string pas;
    if(list->ispas()){
std::string check;
std::cin.ignore();
std::getline(std::cin,check);
if(list->checkpas(check)) {
std::cout<<"Enter new password or delete current pas(0)\n";
std::cin.ignore();
std::getline(std::cin,pas);
if(pas=="0"){list->changepas(check,"");std::cout<<"Deleteed \n";}
else{
list->changepas(check,pas);
std::cout<<"Changed \n";
}
}

    }
    else{
std::cout<<"Enter new password\n";
std::cin.ignore();
std::getline(std::cin,pas);
list->setpas(pas);
std::cout<<"created \n";
    }
}break;
case 4:{
std::cout<<"Do want see Task from (start to end [1]) Or (end to start[2])\n";
int R=getInt("");
if(R==1){list->reverse(false);}
else if(R==2){list->reverse(true);}
else std::cout<<"Wrong Input \n";
}
break;
case 5:{
std::cout<<"How many tasks you'll add?\n";
int add=getInt("");
std::cout<<"How many task you wanna done\n";
int done=getInt("");
list->setwant(add,done);
}
break;
case 6:list->clear(); 
}
}
}
void menu(std::vector <std::unique_ptr<List>>& lists){

//check here

int ch;
while(true){
std::cout<<"Hello to Bisto To Do List \n1-creat new list \n2-open old list \n3-Show lists  \n4-clear cache\n5-swap To Do lists\n6-edit name\n7-delete list \n8-Save data \n9-Autosaving \n0-exit\n";
ch=getInt("");
if(ch==0){
    std::cout<<"Are you sure to exit without saving data \n"; 
    int su=getInt("Save(1)   Back(2)   exit anyway(0)");
    if(su==1){
    for(auto& it:lists){
    it->Savedata();
    }break;}
    else if (su==2) continue;
    else if(su==0)break;
    else std::cout<<"Wrong choise\n";
}
if(ch==2&&lists.empty()){std::cout<<"Please add lists first \n"; continue;}
switch (ch){
    case 1 :creatlist(lists);
    break;
    case 2:{
            std::cout<<"Lists : "<<lists.size()<<" list \n";
            int I=1;
        for (auto& x:lists){
        std::cout<<I<<"-"<<x->getkey()<<"\n"; I++;
        }
        while (true){
int ch=getInt("Select list  exit(0)");
if (ch==0) break;
if(ch>lists.size() || ch<=0){std::cout<<"Wrong list \n"; continue;}
else {
listmenu(lists[(ch-1)]);
break;
}
}
    }
    break;
    case 3:{
        std::cout<<"Lists : "<<lists.size()<<" list \n";
        for (auto& x:lists){
        std::cout<<x->getkey()<<"\n";
}}
    
    break;
    case 4:{for (auto& it:lists){it->clearmemory();}} std::cout<<"Done\n";
break;
case 5:{
    int num=1;
    for (auto& x:lists){
    std::cout<<num<<"-"<<x->getkey()<<"\n";num++;
    }
    
std::cout<<"Select two lists to swap \n";
int l1=getInt("First: ");
int l2=getInt("Second: ");
if(l1>lists.size()||l2>lists.size()||l1==l2||l1<=0||l2<=0) {std::cout<<"Wrong swapping\n"; break;}
std::swap(lists[l1-1],lists[l2-1]);}
break;
case 6:{
    int i=1;
    for (auto& x:lists){
    std::cout<<i<<"-"<<x->getkey()<<"\n";
    i++;
    }
std::cout<<"Which list you wanna edit it \n";
int edit=getInt("");
if (edit>lists.size()||edit<=0){break;}
std::string Edit;
std::cout<<"Enter new name \n";
std::cin.ignore();
std::getline(std::cin,Edit);
if(chrepet(lists,Edit))
lists[edit-1]->setkey(Edit);
else std::cout<<"Wrong name\n";
}
break;
case 7:{
int i=1;
    for (auto& x:lists){
    std::cout<<i<<"-"<<x->getkey()<<"\n";
    i++;
    }
std::cout<<"Which list you wanna delete\n";
int del=getInt("");
if (del>lists.size()||del<=0){break;}
auto it=lists.begin()+(del-1);
lists.erase(it); std::cout<<"Deleteed!\n";
}
break;
case 8:{
for(auto& it:lists){
it->Savedata();
}}
break;

}
}
}

void loaddata(std::vector <std::unique_ptr <List>>& list){
    std::cout << "Open: " << std::filesystem::absolute("lists.txt") << '\n';
std::ifstream data("lists.txt");
if (data.is_open()){
std::string line;
std::getline(data,line);
if(line=="09996718"){
while(true){
    std::string id,pass;
std::getline(data,id);
std::getline(data,line,'|');
std::getline(data,pass,'|');
auto newlist = std::make_unique <List>(line,id,pass);
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
std::string add="";
while(std::getline(data, line)){

if(line=="Done:"){ 
    add="";
    break;}
if(line=="*") {
    newlist->add(add);
    add="";
    continue;
}
if(!line.empty())
add+=line+"\n";
}
while(std::getline(data, line)){
if(line=="Old:"){ 
    add="";
    break;}
if(line=="*") {
    newlist->adddone(add);
    add="";
    continue;
}
if(!line.empty())
add+=line+"\n";
}
while(std::getline(data, line)){
if(line=="End"){ 
    add="";
    break;}
if(line=="*") {
    newlist->addold(add);
    add="";
    continue;
}
if(!line.empty())
add+=line+"\n";
}
list.push_back(std::move(newlist));
std::getline(data,line);
std::string check;
std::getline(data,check);
if(line=="09996710"&&check=="09996718")
continue;
else break;
}

}
data.close();

}
else
std::cout<<"Error while reading the file \n";



}

