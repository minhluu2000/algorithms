#ifndef STRESS_BALL_H
#define STRESS_BALL_H

#include "Main_header.h"

enum class Stress_ball_colors {red, blue, yellow, green};

enum class Stress_ball_sizes {small, medium, large};

class Stress_ball {
    Stress_ball_colors color;
    Stress_ball_sizes size;
    public:
        Stress_ball();
        Stress_ball(Stress_ball_colors, Stress_ball_sizes);
        Stress_ball_colors get_color() const;
        Stress_ball_sizes get_size() const;
        bool operator==(const Stress_ball&);  
};

ostream& operator<<(ostream&, const Stress_ball&);

#endif