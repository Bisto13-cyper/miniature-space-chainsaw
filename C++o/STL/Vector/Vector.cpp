#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <iostream>
#include <string>
#include "Vector.h"
#include "menu.h"
#include<fstream>


void List::show(){
    if(!rev){
        int count=1;
for(auto X:ToDo){std::cout<<count<<"-"<<X<<"\n"; count++;}
    }
if(rev){
int count=ToDo.size();
for(auto X=ToDo.rbegin();
X>ToDo.rend();X++) std::cout<<count<<"-"<<&X<<"\n"; count--;}
}
void List::del(int d){
auto iter=ToDo.begin()+ (d-1);
if(save)
old.push_back(*iter);
ToDo.erase(iter);
}
void List::showold(int count){
for(auto X:old){std::cout<<count<<"-"<<X<<"\n";count++;}
}
void List::setdone(int task){
if (task>ToDo.size()) { std::cout<<"Wrong choise "; return;}
auto it=ToDo.begin()+task-1;
done.push_back(*it);
ToDo.erase(it);

}
int List::showdone(){
int count=1;
for (auto it:done){
std::cout<<count<<"-"<<it<<"("<<Color::GREEN<<"done"<<")"<<Color::RESET<<"\n"; count++;
}
return count;
}
void List:: restart(){
showold(showdone());
int res=getInt("Which task do you wanna retsart  ");
if (res<=done.size()&&res>0){
auto it=done.begin()+res-1;
ToDo.push_back(*it);
done.erase(it);
std::cout<<"Done \n";
}
else if(res>done.size()&&res<=(done.size()+old.size())){
res=res-done.size();
auto it=old.begin()+res-1;
ToDo.push_back(*it);
old.erase(it);
std::cout<<"Done \n";
}
else{std::cout<<"Wrong Input\n";}

}
bool List:: found(int ind){
try {
ToDo.at(ind);
}
catch (const std::out_of_range& e){
return false;
}
return true;
}
void List:: showtask(){
std::cout<<"You didn't finish "<<ToDo.size();
if(want)std::cout<<" from "<<ToDo.capacity();
std::cout<<"\n";
}
void List::showtaskdone(){
    std::cout<<"You finished "<<done.size();
    if(want)std::cout<<" from "<<ToDo.capacity();
std::cout<<"\n";
}
std::vector<std::string> List:: search(std::string target){
std::vector<std::string> found;
int num=1;
for(auto it:ToDo){
if(it.find(target)!=std::string::npos) 
found.push_back(std::to_string(num)+"-"+it);
num++;
}
return found;
}
std::string List:: gettext(int index){
try{
ToDo.at(index);
}
catch(const std::out_of_range& e){std::cout<<"Not found\n";}
return ToDo.at(index);
}
void List:: edit(int index,std::string Edit){
auto it =ToDo.begin()+index;
ToDo.erase(it);
ToDo.insert(it,Edit);

}
void List::setpro(int s,int d){
auto T1=ToDo.begin()+s;
auto T2=ToDo.begin()+d;
std::iter_swap(ToDo.begin() + s, ToDo.begin() + d);
}
void List::savenewdate(){
std::ofstream data("lists.txt",std::ios::app);
if(data.is_open()){
data<<"09996718\n"<<id<<"\n"<<key<<"|"<<rev<<"|"<<save<<"|"<<want<<"\n";
data<<"ToDo:\n";
for(auto it:ToDo){
data<<it<<"\n*\n";
}
data<<"Done:\n";
for(auto it:done){
data<<it<<"\n*\n";
}
data<<"Old:\n";
for(auto it:old){
data<<it<<"\n*\n";
}
data<<"End\n";
data<<"09996710\n";
data.close();
}
}
void List::printdata(std::ofstream &data){
if(data.is_open()){
data<<id<<"\n"<<key<<"|"<<rev<<"|"<<save<<"|"<<want<<"\n";
data<<"ToDo:\n";
for(auto it:ToDo){
data<<it<<"\n*\n";
}
data<<"Done:\n";
for(auto it:done){
data<<it<<"\n*\n";
}
data<<"Old:\n";
for(auto it:old){
data<<it<<"\n*\n";
data.close();
}

}
}
void List::adddone(std::string don) 
{done.push_back(don);}
void List::addold(std::string ol)
{old.push_back(ol);}
void List::savedatafrom(){
    bool skipmode=false;
std::string Idstr=id,line;
std::ifstream old("lists.txt");
std::ofstream current("temp.txt");
if(!old||!current) return;
while(std::getline(old,line)){
if(line.find(Idstr)!=std::string::npos){
printdata(current);
skipmode=true;
continue;
}
if(line.find("End")!=std::string::npos&&skipmode) skipmode=false;

if(!skipmode) 
current<<line<<"\n";
}
old.close();
current. close();
remove("lists.txt");
rename("temp.txt","lists.txt");
}
void List::Savedata(){
if(Idfound())
savedatafrom();
else
savenewdate();
 
}
bool List::Idfound(){
std::ifstream file("lists.txt");
std::string line;
while(std::getline(file,line)){
if(line==id){
    file.close();
    return true;
}
}
file.close();
return false;
}

//try search and sittings and file handling



//add file handling them try Every thing
void vectorsexplain(){
std::vector<int> A;
std::vector <int>B;
int index=5;
A.at(index);//return out_of_range if don't found 
A[index];//use it if you'll add 
A.front();//read first element
A.back();//read last element
A.data();//return first pointer from Array whoch in this vector

//iterators
A.begin();//return place of first  element 
A.end();//return after last element 
A.rbegin();// last element
A.rend();// before first element
A.cbegin();//read only
A.cend();//read only
A.crbegin();//read knly with reverse
A.crend();//read only with reverse 

//capacity
int capacity=100;
A.empty();//isempty?
A.size();//how elemen here
A.max_size();//
A.reserve(capacity);//replace before editing
A.capacity();//capacity
A.shrink_to_fit();//clear places without elements 

//edittng
auto iterator=A.begin();
int value=2008;
int newsize=10;
A.clear();//clear list
A.insert(iterator, value);//add element in place that iterator 
A.erase(iterator); //remove element in place that iterator
A.push_back(value);//add at the last vector
A.pop_back();//remove from last vector
A.emplace(iterator, value);//like insert
A.emplace_back(value);//like push_back
A.resize(newsize);//set new size
A.swap(B);//swap two vectors; (use it)
A.assign(newsize, value);//set new size all with element (value)



}

