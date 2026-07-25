#include<string>
#include "Vector.h"
#include <memory>
#ifndef MENU_H  
#define MENU_H  
int getInt(const std::string& prompt);
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
void listmenu(std::unique_ptr <List>& list);
void set(std::unique_ptr <List>& list);
void menu(std::vector <std::unique_ptr<List>>& lists);
void loaddata(std::vector <std::unique_ptr <List>>& list);
void creatlist(std::vector<std::unique_ptr <List>>& lists);
#endif