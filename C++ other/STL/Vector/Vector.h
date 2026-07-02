#include <vector>
#include <string>
class List{
private:
std::vector<std::string> ToDo;
std::vector<std::string>old;
std::vector<std::string> done;
std::string key;
bool rev,save,want;
public:
List (std::string k):key(k){}
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
};