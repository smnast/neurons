#ifndef COLOR_H
#define COLOR_H

class Color {
public:
    Color();
    Color(double x, double y, double z);
    Color(double x, double y, double z, double a);
    ~Color();

    double r;
    double g;
    double b;
    double a;
};

#endif // COLOR_H
