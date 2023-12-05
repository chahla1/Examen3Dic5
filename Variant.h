//
// Created by chahla on 05/12/2023.
//

#ifndef EXAMEN3DIC5_VARIANT_H
#define EXAMEN3DIC5_VARIANT_H


class Variant {

public:
    Variant();

    Variant(double d);

    Variant(const char string[12]);

    long getInt();

    std::basic_ostream<char, std::char_traits<char>> &getString();
};


#endif //EXAMEN3DIC5_VARIANT_H
