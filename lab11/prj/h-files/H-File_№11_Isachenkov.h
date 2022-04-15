#ifndef DATABASESTRUCT_H_INCLUDED
#define DATABASESTRUCT_H_INCLUDED

#include <iostream>

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

void printPersonalCard(entry personalCard, int i);
void loadnigFile(vector<entry> &database, string pathname);
void showDatabase(vector<entry> database);
void searchPersonalCard(vector<entry> &database, string surname);

#endif // DATABASESTRUCT_H_INCLUDED
