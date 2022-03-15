#include <iostream>
#include "ModulesIsachenkov.h"

using namespace std;

void testdriver_1(void){
    int posadOklad[3] = {1000, 2500,  3000};
    int zarobPlata[3] = {5000, 10000, 15450};
    int year[3] =       {9,    4,     16};
    int num1 [3] =      {6200, 12750, 19200};
    for(int i = 0; i < 3; i++){
        if (Task_9_1(posadOklad[i], zarobPlata[i], year[i]) == num1[i])
            cout << "\nTest case #0" << i+1 << " PASSED.\n";
        else
            cout << "\nTest case #0" << i+1 << " FAILED.\n";
    }
}

void testdriver_2(void){
    int one[3] =    {1,   -6,     1};
    int two[3] =    {4,   -2,     8};
    int three[3] =  {8,    1,     16};
    int four[3] =   {10,   4,     22};
    int five[3] =   {15,   8,     26};
    int six[3] =    {21,   12,    34};
    int num2_1[3] = {9,    2,     17};
    int num2_2[3] = {49,   37,    64};
    temperature test;
    //for(int i = 0; i < 3; i++){
    //    test = Task_9_2(one[i], two[i], three[i], four[i], five[i], six[i]);
    //    if ((test.celsia == num2_1[i]) && (test.farangeit == num2_2[i]))
    //        cout << "\nTest case #0" << i+1 << " PASSED.\n";
    //    else
    //        cout << "\nTest case #0" << i+1 << " FAILED.\n";
    //}
}

void testdriver_3(void){
    int N[3] = {1234567, 7654321, 57210};
    int k[3] = {21,      13,      12};
    for(int i = 0; i < 3; i++){
       if (Task_9_3(N[i]) == k[i])
            cout << "\nTest case #0" << i+1 << " PASSED.\n";
        else
            cout << "\nTest case #0" << i+1 << " FAILED.\n";
    }
}

int main()
{
    testdriver_1();
    testdriver_2();
    testdriver_3();
    return 0;
}
