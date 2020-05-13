#include "Stress_ball.h"

Stress_ball::Stress_ball() {
    color = static_cast<Stress_ball_colors>(rand() % 4);
    size = static_cast<Stress_ball_sizes>(rand() % 3);
}

Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) {
    color = c;
    size = s;
}

Stress_ball_colors Stress_ball::get_color() const { return color; }

Stress_ball_sizes Stress_ball::get_size() const { return size; }

bool Stress_ball::operator==(const Stress_ball& sb) {
    if (color == sb.color && size == sb.size) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Stress_ball& sb) {
    switch(sb.get_color()) {
        case Stress_ball_colors::red: os << "(red,"; break;
        case Stress_ball_colors::blue: os << "(blue,"; break;
        case Stress_ball_colors::yellow: os << "(yellow,"; break;
        case Stress_ball_colors::green: os << "(green,"; break;
    }
    switch(sb.get_size()) {
        case Stress_ball_sizes::small: os << "small)"; break;
        case Stress_ball_sizes::medium: os << "medium)"; break;
        case Stress_ball_sizes::large: os << "large)"; break;
    }
}

