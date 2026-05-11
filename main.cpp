#include <FL/Fl.H>
#include "LibraryDatabase.h"
#include "LoginScreen.h"


int main() {

    // File paths for the database
    std::string userFile = "UserData.csv";
    std::string bookFile = "BookData.csv";
    std::string cdFile = "CdData.csv";
    std::string magazineFile = "MagazineData.csv";
    std::string reservationFile = "ReservationData.csv";

    // Create an instance of LibraryDatabase
    LibraryDatabase* db = LibraryDatabase::getInstance(userFile, bookFile, cdFile, magazineFile, reservationFile);
    LoginScreen loginScreen(*db);
    loginScreen.show();

    return Fl::run();
}


