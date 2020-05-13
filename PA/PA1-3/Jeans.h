#ifndef JEANS_H
#define JEANS_H

#include "Main_header.h"

enum class Jeans_colors {white, blue, brown, black};

enum class Jeans_sizes {small, medium, large, xlarge};

class Jeans {
    Jeans_colors color;
    Jeans_sizes size;
    public:
        Jeans();
        Jeans(Jeans_colors, Jeans_sizes);
        Jeans_colors get_color() const;
        Jeans_sizes get_size() const;
        bool operator==(const Jeans&);  
};

ostream& operator<<(ostream&, const Jeans&);

#endif