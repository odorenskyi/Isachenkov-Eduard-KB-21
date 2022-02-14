#include <iostream>
#include "ModulesIsachenkov.h"
#include <cmath>

using namespace std;

void test_s (void){
    int num1 [5] = {1, 2, 3, 2, 1};
    int num2 [5] = {1, 2, 3, 1, 2};
    int num3 [5] = {1, 2, 3, 3, 3};
    double result[5] = {7.14, 29.14, 348.14, 55.14, 13.14};
    for(int i = 0; i < 5; i++){
        if (round(s_calculation(num1[i], num2[i], num3[i]) * 100) / 100 == result[i])
            cout << "Test case #0" << i+1 << " PASSED.\n";
        else
            cout << "Test case #0" << i+1 << " FAILED.\n";
    }
}

int main()
{
    test_s();
    return 0;
}
