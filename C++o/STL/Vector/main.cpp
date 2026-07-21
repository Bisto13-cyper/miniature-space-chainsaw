#include <vector>
#include "Vector.h"
#include "menu.h"
int main(){
std::vector <List*> lists;
    loaddata(lists);
menu(lists);
for(auto p : lists)
    delete p;
return 0;
}
