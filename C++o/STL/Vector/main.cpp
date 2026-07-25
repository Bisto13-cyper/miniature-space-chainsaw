#include <vector>
#include "Vector.h"
#include "menu.h"
#include <memory>
int main(){
std::vector <std::unique_ptr <List>> lists;
    loaddata(lists);
menu(lists);
return 0;
}
