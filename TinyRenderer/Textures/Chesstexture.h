#pragma once

#include <cmath>

class ChessTexture {
public:
    int d = 8;
public:
    ChessTexture();
    ChessTexture(int d);

    bool getMapping(double u, double v);
};
