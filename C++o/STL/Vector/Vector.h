#include <vector>
#include <string>
#include <random>
#ifndef VECTOR_H  
#define VECTOR_H  
class List{
private:
inline static std::random_device rd;
inline static std::mt19937 gen{rd()};
inline static std::uniform_int_distribution<> distr{1000, 9999};
std::vector<std::string> ToDo;
std::vector<std::string>old;
std::vector<std::string> done;
std::string key;
std::string id;
std::string password; 
bool rev=false,save=true,want=false;

bool Idfound();
void savenewdate();
void savedatafrom();
void printdata(std::ofstream &file);
public:
List (std::string k):key(k){id=std::to_string(gen()); password="";}
List (std::string k,std::string i):key(k){id=i;}
List (std::string k,std::string i,std::string pas):key(k),password(pas){id=i;}
void setpas(std::string pas);
void saving(bool S){save=S;}
bool issave(){return save;}
void add(std::string added){ToDo.emplace_back(added);}
void show();
void del(int d);
void showold(int count=1);
void setdone(int task);
int showdone();
bool Tempty(){return ToDo.empty();}
bool Dempty(){return done.empty();}
bool Oempty(){return old.empty();}
void restart();
void clearD (){done.clear();}
void clearO(){old.clear();}
void clear(){ToDo.clear();clearO();key="";clearD();}
std::string getkey(){return key;}
std::string gettext(int);
void setkey(std::string k){key=k;}
bool found(int ind);
int size(){return ToDo.size();}
void clearmemory(){done.shrink_to_fit();ToDo.shrink_to_fit();old.shrink_to_fit();}
std::string next(){return ToDo.front();}
std::string last(){return ToDo.back();}
void reverse(bool r){rev=r;}
void setwant(int Do,int doned){ToDo.reserve(Do);done.reserve(doned); want=true;}
void showtask();
void showtaskdone();
std::vector<std::string> search(std::string); 
void edit(int,std::string);
void setpro(int,int);
void addwant(bool w){want=w;}
void adddone(std::string);
void addold(std::string);
void Savedata();
bool ispas(){return password!="";}
bool checkpas(std::string ch){return ch==password;}
void changepas(std::string,std::string);
~List(){ToDo.clear();done.clear();old.clear();}
};
#endif