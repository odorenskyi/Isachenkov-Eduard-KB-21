#include <iostream>
#include <fstream>
#include <string>
#include "ModulesIsachenkov.h"

using namespace std;

int main()
{
    string path = __FILE__;
    string path_result = "..\\TestSuite\\TestResult.txt";
    string path_suite = "..\\TestSuite\\TestSuite.txt";
    size_t check = path.find("\\lab12\\prj\\");
    int expected_a[5] = {1, 2, 3, 4, 5};
    ClassLab12_Isachenkov Test;
    if(check == string::npos){
        ofstream fout;
        fout.open(path_result);
        fout << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";
        for(int i = 0; i < 100; i++)
            cout << "\a";
        fout.close();
    }
    else {
        ifstream fin;
        ofstream fout;
        string a, b, text;

        fout.open(path_result);
        fin.open(path_suite);

        for(int i = 0; i < 5; i++){

            getline(fin, a, ',');
            getline(fin, b, ';');
            getline(fin, text);

            double s = stoi(text);

            Test.in_a(stoi(a));
            Test.in_b(stoi(b));

            if(Test.out_S() == s){
                fout << "Test case " << i+1 << " PASSED\n";
            }
            else
                fout << "Test case " << i+1 << " FAILED\n";
        }
        fout.close();
        fin.close();
    }
    system("pause");
    return 0;
}
