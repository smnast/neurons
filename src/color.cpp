#include "color.h"

Color::Color() : r(0.0), g(0.0), b(0.0), a(1.0) {}

Color::Color(double r, double g, double b) : r(r), g(g), b(b), a(1.0) {}

Color::Color(double r, double g, double b, double a) : r(r), g(g), b(b), a(a) {}

Color::~Color() {}
