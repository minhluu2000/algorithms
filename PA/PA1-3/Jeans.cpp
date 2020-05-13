#include "Jeans.h"

Jeans::Jeans() {
    color = static_cast<Jeans_colors>(rand() % 4);
    size = static_cast<Jeans_sizes>(rand() % 3);
}

Jeans::Jeans(Jeans_colors c, Jeans_sizes s) {
    color = c;
    size = s;
}

Jeans_colors Jeans::get_color() const { return color; }

Jeans_sizes Jeans::get_size() const { return size; }

bool Jeans::operator==(const Jeans& sb) {
    if (color == sb.color && size == sb.size) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Jeans& sb) {
    switch(sb.get_color()) {
        case Jeans_colors::white: os << "(white,"; break;
        case Jeans_colors::blue: os << "(blue,"; break;
        case Jeans_colors::brown: os << "(brown,"; break;
        case Jeans_colors::black: os << "(black,"; break;
    }
    switch(sb.get_size()) {
        case Jeans_sizes::small: os << "small)"; break;
        case Jeans_sizes::medium: os << "medium)"; break;
        case Jeans_sizes::large: os << "large)"; break;
        case Jeans_sizes::xlarge: os << "xlarge)"; break;
    }
}

