#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

#include "ModulesIsachenkov.h"
#include "ModulesKozlov.h"
#include "ModulesZadorozhny.h"

using namespace std;

int main()
{
    system("chcp 1251 & cls");
    vector<entry> database;
    string filename = "database.dat";
    loadDatabase(database, filename);
    int introduction = 0, finish = 0, id = 0;
    while(true){
        cout << "++===================================================================++" << endl
             << "|| 1. Виведення бази                                                 ||" << endl
             << "|| 2. Додавання нового запису в базу                                 ||" << endl
             << "|| 3. Пошук запису за ввденим прізвищем працівника                   ||" << endl
             << "|| 4. Вилучення заданого оператором запису з бази даних              ||" << endl
             << "|| 5. Завершення роботи програми з автоматичним записом даних у файл ||" << endl
             << "++===================================================================++" << endl
             << ">>> ";
        cin >> introduction;
        if (introduction == 1){
            system("cls");
            showDatabase(database);
        }
        else if (introduction == 2){
            system("cls");
            AddPersonalCard(database);
        }
        else if (introduction == 3){
            system("cls");
            string surname;
            cout << "+===========================================================" << endl
                 << " Введіть прізвище людини, яку хочете знайти: - ";
            cin >> surname;
            cout << "+===========================================================" << endl;
            searchPersonalCard(database, surname);
        }
        else if (introduction == 4){
            system("cls");
            cout << "+=========================================+" << endl
                 << " Введіть id, яке хочете видалити: - ";
            cin >> id;
            cout << "+=========================================+" << endl;
            RemovePersonalCard(database, id);
        }
        else if (introduction == 5){
            system("cls");
            saveDatabase(database, filename);
            break;
        }
        else {
            system("cls");
            cout << "Ви ввели неправильне число!\n";
        }
    }
        system("pause");
}
