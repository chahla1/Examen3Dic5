#include <iostream>
#include <map>
#include <string>
#include "Variant.h"

class Environment {
private:
    std::map<std::string, Variant> symbolMap;

public:
    Environment() {
        addSymbol("pi", Variant(3.1416));
    }

    void addSymbol(const std::string &symbol, const Variant &value) {
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

    void insert(const std::string &symbol, const Variant &value) {
        auto it = symbolMap.find(symbol);

        if (it == symbolMap.end()) {
            symbolMap[symbol] = value;
        } else {
            it->second = value;
        }
    }

    // Función para eliminar un símbolo
    void removeSymbol(const std::string &symbol) {
        auto it = symbolMap.find(symbol);
        if (it != symbolMap.end()) {
            symbolMap.erase(it);
        }
    }

    // Función para verificar si un símbolo existe en el entorno
    bool symbolExists(const std::string &symbol) const {
        return symbolMap.find(symbol) != symbolMap.end();
    }
};

int main() {
    try {
        // Crear un objeto Environment
        Environment environment;

        // Añadir símbolos al entorno con sus valores representados por objetos Variant
        environment.insert("x", Variant(10));
        environment.insert("y", Variant("Hola Examen"));

        // Actualizar el valor de un símbolo existente
        environment.insert("x", Variant(8));

        // Mostrar los valores de los símbolos en el entorno
        std::cout << "Value of x: " << environment.lookup("x").getInt() << std::endl;
        std::cout << "Value of y: " << environment.lookup("y").getString() << std::endl;
//6. Expandiendo Funcionalidades:
        // Eliminar el símbolo "x"
        environment.removeSymbol("x");


        // Verificar si el símbolo "x" existe después de eliminarlo
        if (environment.symbolExists("x")) {
            std::cout << "Symbol 'x' still exists." << std::endl;
        } else {
            std::cout << "Symbol 'x' has been removed." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
