#include <cmath>

float s_calculation(int x, int y, int z){
    return (pow((2 * z + 1), x)) - (sqrt(abs(y - 0.5 * z))) + z + 3.141592653589793;
}
