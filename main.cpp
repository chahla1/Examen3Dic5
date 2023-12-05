#include <iostream>
#include <map>
#include <string>
#include "Variant.h"

//4. Gestion de errores

// Esto es una excepción para indicar que se intentó acceder a un símbolo no existente
class SymbolNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Symbol not found";
    }
};

// Esto es una excepción para indicar que se intentó insertar un símbolo ya existente con un valor diferente
class SymbolAlreadyExistsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Symbol already exists with a different value";
    }
};

// 1. Estructura Básica:
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
            // Devolver un objeto Variant que indica que el símbolo no fue encontrado
            return Variant(); // Asumiendo que Variant tiene un constructor predeterminado indicando "sin valor"
        }
    }

    // 2. Insertar Símbolos:
    void insert(const std::string &symbol, const Variant &value) {
        auto it = symbolMap.find(symbol);

        if (it == symbolMap.end()) {
            symbolMap[symbol] = value;
        } else {
            it->second = value;
        }
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

        // Intentar buscar un símbolo que no existe
        Variant resultZ = environment.lookup("z");

        if (resultZ.isEmpty()) {
            std::cout << "Symbol 'z' not found." << std::endl;
        } else {
            std::cout << "Value of z: " << resultZ.getString() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
