#include <cmath>

float s_calculation(int x, int y, int z) {
    float S = pow(z + y + z, 2.0) - sqrt(fabs((2.0 * M_PI * sqrt((1.0/2.0) * z)) / (y + (4.0 * (pow(x, 3.0) + cos(z)))) ));
    return S;
}
