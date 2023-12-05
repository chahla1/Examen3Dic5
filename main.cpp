#include <iostream>
#include <map>
#include <string>
using namespace std;

// 1. Estructura Básica:

class Environment {
private:
    map<string, int> symbol_Map;
public:
    Environment(){}
    Variant lookup(const string& symbolName) const {
        auto it = symbolTable.find(symbolName);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            return Variant();
        }
    }






}


