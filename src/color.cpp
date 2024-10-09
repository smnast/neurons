#include "color.h"

Color::Color() : r(0x00), g(0x00), b(0x00), a(0xFF) {}

Color::Color(Uint8 r, Uint8 g, Uint8 b) : r(r), g(g), b(b), a(0xFF) {}

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : r(r), g(g), b(b), a(a) {}

Color::~Color() {}
