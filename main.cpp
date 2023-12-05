#include <iostream>
#include <map>
#include <string>
using namespace std;

// 1. Estructura Básica:

class Environment {
private:
    std::map<std::string, int> symbol_Map;
public:
    Environment(){
        addSymbol("pi", 3,1416);
        addSymbol("e", 2,718);
    }

}


