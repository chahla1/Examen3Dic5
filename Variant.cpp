#include <iostream>
#include <variant>

class Variant {
private:
    std::variant<int, double, std::string> value;

public:
    Variant() : value(0) {}

    Variant(int intValue) : value(intValue) {}

    Variant(double doubleValue) : value(doubleValue) {}

    Variant(const char* stringValue) : value(std::string(stringValue)) {}

    int getInt() const {
        return std::get<int>(value);
    }

    double getDouble() const {
        return std::get<double>(value);
    }

    std::string getString() const {
        return std::get<std::string>(value);
    }

    // Sobrecarga del operador << para facilitar la salida a cout
    friend std::ostream& operator<<(std::ostream& os, const Variant& variant) {
        std::visit([&os](const auto& val) { os << val; }, variant.value);
        return os;
    }

    bool isEmpty();
};

bool Variant::isEmpty() {
    return false;
}
