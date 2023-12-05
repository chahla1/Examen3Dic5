#include <iostream>
#include <map>
#include <string>
using namespace std;

// 1. Estructura Básica:

class Environment {
private:
    map<string, int> symbolMap;
public:
    Environment() {
        addSymbol("pi", 3.1416);
    }

    void addSymbol(const string &symbol, int value) {
        symbolMap[symbol] = value;
    }

    int getSymbolValue(const string &symbol) const {
        auto it = symbolMap.find(symbol);
        if (it != symbolMap.end()) {
            return it->second;
        } else {
            return 0;
        }

    }
};