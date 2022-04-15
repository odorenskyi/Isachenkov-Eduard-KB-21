#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct date{
    short day = 0;      //1...
    short month = 0;    //1...
    short year = 0;
};

struct entry {
    date creationDate;
    int regNum = -1;
    int id = -1;
    char gender = 'm';
    char typeOfWork = 'f';
    string fullName = "";
    date birthDate;
    string citizenship = "";
    enum {basicSecondary, compSecondary, vocational,
          incompHigher, basicHigher, higher} education;
    string placeOfEducation = "";
    string lastPlaceOfWork = "";
    string lastJob = "";
    struct {
        short days = 0;
        short months = 0;
        short years = 0;
    } workingExp;
    string placeOfLiving = "";
    string passportInfo = "";
    string additionalInfo = "";
    date dateOfFiring;
    string reasonOfFiring = "";
};

void printPersonalCard(entry personalCard, int i){
    cout << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ')
         << "|" << setw(63) << "ВІДДІЛ КАДРІВ: ОСОБОВА КАРТКА ПРАЦІВНИКА, Ф. П-2" << setw(16) << "|" << endl
         << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ');
    cout << "|" << setw(6) << i+1 << "|" << setw(25) << left << "Дата створення:" << "|" << setw(45)
                 << (personalCard.creationDate.day < 10 ? "0" : "") + to_string(personalCard.creationDate.day) + "." +
                    (personalCard.creationDate.month < 10 ? "0" : "") + to_string(personalCard.creationDate.month) + "." +
                    to_string(personalCard.creationDate.year) << "|" << endl << resetiosflags(ios::left);
            for (int j = 0; j < 17; j++) {
                cout << "|" << setw(7) << "|" << setw(25) << left;
                switch(j) {
                case 0:
                    cout << "Реєстраційний номер:" << "|" << setw(45) << personalCard.regNum;
                    break;
                case 1:
                    cout << "Ідентифікаційний номер:" << "|" << setw(45) << personalCard.id;
                    break;
                case 2:
                    cout << "Стать:" << "|" << setw(45) << (personalCard.gender == 'm' ? "чоловіча" : "жіноча");
                    break;
                case 3:
                    cout << "Вид роботи:" << "|" << setw(45) << (personalCard.typeOfWork == 'f' ? "основна" : "за суміцниством");
                    break;
                case 4:
                    cout << "ПІБ працівника:" << "|" << setw(46) << personalCard.fullName;
                    break;
                case 5:
                    cout << "Дата народження:" << "|" << setw(45) << (personalCard.birthDate.day < 10 ? "0" : "") +
                            to_string(personalCard.birthDate.day) + "." + (personalCard.birthDate.month < 10 ? "0" : "") +
                            to_string(personalCard.birthDate.month) + "." + to_string(personalCard.birthDate.year);
                    break;
                case 6:
                    cout << "Громадянство:" << "|" << setw(45) << personalCard.citizenship;
                    break;
                case 7:
                    cout << "Освіта:" << "|" << setw(45) << (personalCard.education == entry::basicSecondary ? "базова середня" :
                                                             personalCard.education == entry::compSecondary ? "повна середня" :
                                                             personalCard.education == entry::vocational ? "професійно-технічна" :
                                                             personalCard.education == entry::incompHigher ? "неповна вища" :
                                                             personalCard.education == entry::basicHigher ? "базова вища" : "вища");
                    break;
                case 8:
                    cout << " " << "|" << setw(45) << personalCard.placeOfEducation;
                    break;
                case 9:
                    cout << "Останнє місце роботи:" << "|" << setw(45) << personalCard.lastPlaceOfWork;
                    break;
                case 10:
                    cout << resetiosflags(ios::left) << "посада:    " << left << "|" << setw(45) << personalCard.lastJob;
                    break;
                case 11:
                    cout << "Стаж роботи:" << "|" << setw(45) << (personalCard.workingExp.days != 0 ?
                            to_string(personalCard.workingExp.days) + " днів " : "") + (personalCard.workingExp.months != 0 ?
                            to_string(personalCard.workingExp.months) + " місяців " : "") + (personalCard.workingExp.years != 0 ?
                            to_string(personalCard.workingExp.years) + " років" : "");
                    break;
                case 12:
                    cout << "Місце проживання:" << "|" << setw(45) << personalCard.placeOfLiving;
                    break;
                case 13:
                    cout << "Паспортні дані:" << "|" << setw(45) << personalCard.passportInfo;
                    break;
                case 14:
                    cout << "Додаткові відомості:" << "|" << setw(45) << personalCard.additionalInfo;
                    break;
                case 15:
                    cout << "Дата звільнення:" << "|" << setw(45) << (personalCard.dateOfFiring.day != 0 &&
                            personalCard.dateOfFiring.month != 0 && personalCard.dateOfFiring.year != 0 ?
                            (personalCard.dateOfFiring.day < 10 ? "0" : "") + to_string(personalCard.dateOfFiring.day) + "." +
                            (personalCard.dateOfFiring.month < 10 ? "0" : "") + to_string(personalCard.dateOfFiring.month) +
                            "." + to_string(personalCard.dateOfFiring.year) : "-");
                    break;
                case 16:
                    cout << resetiosflags(ios::left) << "причина:         " << left << "|" << setw(45)
                         << personalCard.reasonOfFiring;
                    break;
                }
                cout << "|" << endl << resetiosflags(ios::left);
            }
                cout << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ');
}

void loadnigFile(vector<entry> &database, string pathname){

    entry tmpEntry;

    ifstream bin ("database.dat", ios::in | ios::binary);
    int* fileLen = new int(bin.seekg(0, ios::end).tellg());
    bin.seekg(0, ios::beg);
    while (bin.tellg() < *fileLen) {
        int len;
        bin.read((char*)&tmpEntry, sizeof(tmpEntry.creationDate)+sizeof(int)*2 + sizeof(char)*2);

        bin.read((char*)&len, sizeof(int));
        tmpEntry.fullName.resize(len);         //instead of dynamic buffer
        bin.read((char*)&tmpEntry.fullName[0], len);

        bin.read((char*)&tmpEntry.birthDate, sizeof(date));

        bin.read((char*)&len, sizeof(int));
        tmpEntry.citizenship.resize(len);
        bin.read((char*)&tmpEntry.citizenship[0], len);

        bin.read((char*)&tmpEntry.education, sizeof(int));

        bin.read((char*)&len, sizeof(int));
        tmpEntry.placeOfEducation.resize(len);
        bin.read((char*)&tmpEntry.placeOfEducation[0], len);

        bin.read((char*)&len, sizeof(int));
        tmpEntry.lastPlaceOfWork.resize(len);
        bin.read((char*)&tmpEntry.lastPlaceOfWork[0], len);

        bin.read((char*)&len, sizeof(int));
        tmpEntry.lastJob.resize(len);
        bin.read((char*)&tmpEntry.lastJob[0], len);

        bin.read((char*)&tmpEntry.workingExp, sizeof(short)*3);

        bin.read((char*)&len, sizeof(int));
        tmpEntry.placeOfLiving.resize(len);
        bin.read((char*)&tmpEntry.placeOfLiving[0], len);

        bin.read((char*)&len, sizeof(int));
        tmpEntry.passportInfo.resize(len);
        bin.read((char*)&tmpEntry.passportInfo[0], len);

        bin.read((char*)&len, sizeof(int));
        tmpEntry.additionalInfo.resize(len);
        bin.read((char*)&tmpEntry.additionalInfo[0], len);

        bin.read((char*)&tmpEntry.dateOfFiring.day, sizeof(date));

        bin.read((char*)&len, sizeof(int));
        tmpEntry.reasonOfFiring.resize(len);
        bin.read((char*)&tmpEntry.reasonOfFiring[0], len);

        database.push_back(tmpEntry);
    }
    bin.close();
}


void searchPersonalCard(vector<entry> &database, string surname){
    string lastName;
    for(int i = 0; i < database.size(); i++){
        istringstream(database[i].fullName) >> lastName;
        if(lastName == surname){
            printPersonalCard(database[i], i);
        }
    }
}

void showDatabase(vector<entry> database){
    char option;
    do {
        cout << "+==============================================================+" << endl
             << " Ви хочете вивести базу даних на консоль (c) або у файл (t) - "; cin >> option;
        cout << "+==============================================================+" << endl;
    }while (option != 'c' && option != 't');
    if (option == 'c') {
        cout << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ')
             << "|" << setw(63) << "ВІДДІЛ КАДРІВ: ОСОБОВА КАРТКА ПРАЦІВНИКА, Ф. П-2" << setw(16) << "|" << endl
             << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ');
        for (int i = 0; i < database.size(); i++) {
            cout << "|" << setw(6) << i+1 << "|" << setw(25) << left << "Дата створення:" << "|" << setw(45)
                 << (database[i].creationDate.day < 10 ? "0" : "") + to_string(database[i].creationDate.day) + "." +
                    (database[i].creationDate.month < 10 ? "0" : "") + to_string(database[i].creationDate.month) + "." +
                    to_string(database[i].creationDate.year) << "|" << endl << resetiosflags(ios::left);
            for (int j = 0; j < 17; j++) {
                cout << "|" << setw(7) << "|" << setw(25) << left;
                switch(j) {
                case 0:
                    cout << "Реєстраційний номер:" << "|" << setw(45) << database[i].regNum;
                    break;
                case 1:
                    cout << "Ідентифікаційний номер:" << "|" << setw(45) << database[i].id;
                    break;
                case 2:
                    cout << "Стать:" << "|" << setw(45) << (database[i].gender == 'm' ? "чоловіча" : "жіноча");
                    break;
                case 3:
                    cout << "Вид роботи:" << "|" << setw(45) << (database[i].typeOfWork == 'f' ? "основна" : "за суміцниством");
                    break;
                case 4:
                    cout << "ПІБ працівника:" << "|" << setw(46) << database[i].fullName;
                    break;
                case 5:
                    cout << "Дата народження:" << "|" << setw(45) << (database[i].birthDate.day < 10 ? "0" : "") +
                            to_string(database[i].birthDate.day) + "." + (database[i].birthDate.month < 10 ? "0" : "") +
                            to_string(database[i].birthDate.month) + "." + to_string(database[i].birthDate.year);
                    break;
                case 6:
                    cout << "Громадянство:" << "|" << setw(45) << database[i].citizenship;
                    break;
                case 7:
                    cout << "Освіта:" << "|" << setw(45) << (database[i].education == entry::basicSecondary ? "базова середня" :
                                                             database[i].education == entry::compSecondary ? "повна середня" :
                                                             database[i].education == entry::vocational ? "професійно-технічна" :
                                                             database[i].education == entry::incompHigher ? "неповна вища" :
                                                             database[i].education == entry::basicHigher ? "базова вища" : "вища");
                    break;
                case 8:
                    cout << " " << "|" << setw(45) << database[i].placeOfEducation;
                    break;
                case 9:
                    cout << "Останнє місце роботи:" << "|" << setw(45) << database[i].lastPlaceOfWork;
                    break;
                case 10:
                    cout << resetiosflags(ios::left) << "посада:    " << left << "|" << setw(45) << database[i].lastJob;
                    break;
                case 11:
                    cout << "Стаж роботи:" << "|" << setw(45) << (database[i].workingExp.days != 0 ?
                            to_string(database[i].workingExp.days) + " днів " : "") + (database[i].workingExp.months != 0 ?
                            to_string(database[i].workingExp.months) + " місяців " : "") + (database[i].workingExp.years != 0 ?
                            to_string(database[i].workingExp.years) + " років" : "");
                    break;
                case 12:
                    cout << "Місце проживання:" << "|" << setw(45) << database[i].placeOfLiving;
                    break;
                case 13:
                    cout << "Паспортні дані:" << "|" << setw(45) << database[i].passportInfo;
                    break;
                case 14:
                    cout << "Додаткові відомості:" << "|" << setw(45) << database[i].additionalInfo;
                    break;
                case 15:
                    cout << "Дата звільнення:" << "|" << setw(45) << (database[i].dateOfFiring.day != 0 &&
                            database[i].dateOfFiring.month != 0 && database[i].dateOfFiring.year != 0 ?
                            (database[i].dateOfFiring.day < 10 ? "0" : "") + to_string(database[i].dateOfFiring.day) + "." +
                            (database[i].dateOfFiring.month < 10 ? "0" : "") + to_string(database[i].dateOfFiring.month) +
                            "." + to_string(database[i].dateOfFiring.year) : "-");
                    break;
                case 16:
                    cout << resetiosflags(ios::left) << "причина:         " << left << "|" << setw(45)
                         << database[i].reasonOfFiring;
                    break;
                }
                cout << "|" << endl << resetiosflags(ios::left);
            }
            if (i+1 != database.size())
                cout << "+" << setfill('—') << setw(7) << "+" << setw(26) << "+" << setw(46) << "+" << setfill(' ') << endl;
            else
                cout << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ');
        }
    }
    else {
        do {
            string filename;
            cout << "Введіть назву файлу: ";
            cin >> filename;
            ofstream fout (filename, ios::out);
            if (fout.is_open()) {
                fout << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ')
                     << "|" << setw(63) << "ВІДДІЛ КАДРІВ: ОСОБОВА КАРТКА ПРАЦІВНИКА, Ф. П-2" << setw(16) << "|" << endl
                     << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ');
                for (int i = 0; i < database.size(); i++) {
                    fout << "|" << setw(6) << i+1 << "|" << setw(25) << left << "Дата створення:" << "|" << setw(45)
                         << (database[i].creationDate.day < 10 ? "0" : "") + to_string(database[i].creationDate.day) + "." +
                            (database[i].creationDate.month < 10 ? "0" : "") + to_string(database[i].creationDate.month) + "." +
                            to_string(database[i].creationDate.year) << "|" << endl << resetiosflags(ios::left);
                    for (int j = 0; j < 17; j++) {
                        fout << "|" << setw(7) << "|" << setw(25) << left;
                        switch(j) {
                        case 0:
                            fout << "Реєстраційний номер:" << "|" << setw(45) << database[i].regNum;
                            break;
                        case 1:
                            fout << "Ідентифікаційний номер:" << "|" << setw(45) << database[i].id;
                            break;
                        case 2:
                            fout << "Стать:" << "|" << setw(45) << (database[i].gender == 'm' ? "чоловіча" : "жіноча");
                            break;
                        case 3:
                            fout << "Вид роботи:" << "|" << setw(45) << (database[i].typeOfWork == 'm' ? "основна" : "за суміцниством");
                            break;
                        case 4:
                            fout << "ПІБ працівника:" << "|" << setw(45) << database[i].fullName;
                            break;
                        case 5:
                            fout << "Дата народження:" << "|" << setw(45) << (database[i].birthDate.day < 10 ? "0" : "") +
                                    to_string(database[i].birthDate.day) + "." + (database[i].birthDate.month < 10 ? "0" : "") +
                                    to_string(database[i].birthDate.month) + "." + to_string(database[i].birthDate.year);
                            break;
                        case 6:
                            fout << "Громадянство:" << "|" << setw(45) << database[i].citizenship;
                            break;
                        case 7:
                            fout << "Освіта:" << "|" << setw(45) << (database[i].education == entry::basicSecondary ? "базова середня" :
                                                                     database[i].education == entry::compSecondary ? "повна середня" :
                                                                     database[i].education == entry::vocational ? "професійно-технічна" :
                                                                     database[i].education == entry::incompHigher ? "неповна вища" :
                                                                     database[i].education == entry::basicHigher ? "базова вища" : "вища");
                            break;
                        case 8:
                            fout << " " << "|" << setw(45) << database[i].placeOfEducation;
                            break;
                        case 9:
                            fout << "Останнє місце роботи:" << "|" << setw(45) << database[i].lastPlaceOfWork;
                            break;
                        case 10:
                            fout << resetiosflags(ios::left) << "посада:    " << left << "|" << setw(45) << database[i].lastJob;
                            break;
                        case 11:
                            fout << "Стаж роботи:" << "|" << setw(45) << (database[i].workingExp.days != 0 ?
                                    to_string(database[i].workingExp.days) + " днів " : "") + (database[i].workingExp.months != 0 ?
                                    to_string(database[i].workingExp.months) + " місяців " : "") + (database[i].workingExp.years != 0 ?
                                    to_string(database[i].workingExp.years) + " років" : "");
                            break;
                        case 12:
                            fout << "Місце проживання:" << "|" << setw(45) << database[i].placeOfLiving;
                            break;
                        case 13:
                            fout << "Паспортні дані:" << "|" << setw(45) << database[i].passportInfo;
                            break;
                        case 14:
                            fout << "Додаткові відомості:" << "|" << setw(45) << database[i].additionalInfo;
                            break;
                        case 15:
                            fout << "Дата звільнення:" << "|" << setw(45) << (database[i].dateOfFiring.day != 0 &&
                                    database[i].dateOfFiring.month != 0 && database[i].dateOfFiring.year != 0 ?
                                    (database[i].dateOfFiring.day < 10 ? "0" : "") + to_string(database[i].dateOfFiring.day) + "." +
                                    (database[i].dateOfFiring.month < 10 ? "0" : "") + to_string(database[i].dateOfFiring.month) +
                                    "." + to_string(database[i].dateOfFiring.year) : "-");
                            break;
                        case 16:
                            fout << resetiosflags(ios::left) << "причина:         " << left << "|" << setw(45)
                                 << database[i].reasonOfFiring;
                            break;
                        }
                        fout << "|" << endl << resetiosflags(ios::left);
                    }
                    if (i+1 != database.size())
                        fout << "+" << setfill('—') << setw(7) << "+" << setw(26) << "+" << setw(46) << "+" << setfill(' ') << endl;
                    else
                        fout << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ');
                }
                fout.close();
            }
            else {
                cerr << "Сталася помилка під час написання " << filename << ". Cпробуйте ще раз." << endl;
                continue;
            }
        }while (false);
    }
}
