#include <iostream>
#include <map>
#include <string>
#include "Variant.h"
using namespace std;


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

    Variant lookup(const string &symbol) const {
        auto it = symbolMap.find(symbol);
        if (it != symbolMap.end()) {
            return it->second;
        } else {
            return Variant();
        }

    }
};
//2. Insertar Símbolos:
void insert(const string &symbol, const Variant &value) {
    // Verificamos si el símbolo ya existe
    auto it = symbolMap.find(symbol);

    if (it == symbolMap.end()) {
        // Si el símbolo no existe, lo añadimos
        symbolMap[symbol] = value;
    } else {
        // Si el símbolo ya existe, podríamos manejarlo de alguna manera
        it->second = value;
    }
}
};


