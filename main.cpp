#include <iostream>
#include <map>
#include <string>
using namespace std;
#include "Variant.h"

// 1. Estructura Básica:

class Environment {
private:
    map<string, Variant> symbolMap;
public:
    Environment() {
        addSymbol("pi", Variant(3.1416));
    }

    void addSymbol(const string &symbol, const Variant &value) {
        symbolMap[symbol] = value;
    }

    Variant lookup(const std::string &symbol) const {
        auto it = symbolMap.find(symbol);
        if (it != symbolMap.end()) {
            return it->second;
        } else {
            return Variant();
        }

    }
};
//2. Insertar Símbolos:



