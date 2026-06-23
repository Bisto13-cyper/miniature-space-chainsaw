#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <iostream>
#include <string>
#include "Vector.h"
#include "menu.h"


void List::show(){
int count=1;
for(auto X:ToDo){std::cout<<count<<"-"<<X<<"\n"; count++;}
}
void List::del(int d){
auto iter=ToDo.begin()+ (d-1);
if(save)
old.push_back(*iter);
ToDo.erase(iter);
}
void List::showold(int count=1){
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
//add sorting searching front() end() undo 





