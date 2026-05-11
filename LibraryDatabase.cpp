#include "LibraryDatabase.h"
#include "CD.h"
#include "Magazine.h"
#include "Book.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
using namespace std;

// Define the static instance pointer
LibraryDatabase* LibraryDatabase::instance = nullptr;

// Private constructor
LibraryDatabase::LibraryDatabase(const string& userFile, const string& bookFile,
                                 const string& cdFile, const string& magazineFile,
                                 const string& reservationFile)
    : userFile(userFile), bookFile(bookFile), cdFile(cdFile),
      magazineFile(magazineFile), reservationFile(reservationFile) {}

// Static method to access the singleton instance
LibraryDatabase* LibraryDatabase::getInstance(const string& userFile, const string& bookFile,
                                              const string& cdFile, const string& magazineFile, 
                                              const string& reservationFile) {
    if (instance == nullptr) {
        instance = new LibraryDatabase(userFile, bookFile, cdFile, magazineFile, reservationFile);
    }
    return instance;
}

void LibraryDatabase::addItem(BorrowableItem *item)
{
    string fileName;
    if (dynamic_cast<CD *>(item))
    {
        fileName = cdFile;

        CD *cdItem = dynamic_cast<CD *>(item);
        ostringstream data;
        data << item->getItemId() << "," << item->getTitle() << "," << item->getCategory()
             << "," << cdItem->getArtist() << "," << cdItem->getGenre() << "\n";
        appendToFile(fileName, data.str());
    }
    else if (dynamic_cast<Magazine *>(item))
    {
        fileName = magazineFile;

        Magazine *magazineItem = dynamic_cast<Magazine *>(item);
        ostringstream data;
        data << item->getItemId() << "," << item->getTitle() << "," << item->getCategory()
             << "," << magazineItem->getIssueNumber() << "," << magazineItem->getPublicationDate() << "\n";
        appendToFile(fileName, data.str());
    }
    else if (dynamic_cast<Book *>(item))
    {
        fileName = bookFile;

        Book *bookItem = dynamic_cast<Book *>(item);
        ostringstream data;
        data << item->getItemId() << "," << item->getTitle() << "," << item->getCategory()
             << "," << bookItem->getISBN() << "," << bookItem->getAuthorName() << "\n";
        appendToFile(fileName, data.str());
    }
    else
    {
        cerr << "Unknown item type!" << endl;
        return;
    }
}

void LibraryDatabase::addBook(string bookId, string title, string category, string ISBN, string authorName){
    ostringstream data;
    data << bookId << "," << title << "," << category << "," << ISBN << "," << authorName << "\n";
    appendToFile(bookFile, data.str());
}

void LibraryDatabase::addMagazine(string itemId, string title, string category, string issueNumber, string publicationDate){
    ostringstream data;
    data << itemId << "," << title << "," << category << "," << issueNumber << "," << publicationDate << "\n";
    appendToFile(magazineFile, data.str());
}

void LibraryDatabase::addCd(string itemId, string title, string category, string artist, string genre){
    ostringstream data;
    data << itemId << "," << title << "," << category << "," << artist << "," << genre << "\n";
    appendToFile(cdFile, data.str());
}

bool LibraryDatabase::existItem(const std::string &itemId)
{
    std::string itemFiles[3] = {bookFile, cdFile, magazineFile};
    for (int i = 0; i < 3; i++)
    {
        std::ifstream inFile(itemFiles[i]); 
        if (!inFile.is_open())
        {
            return false; // File couldn't be opened
        }

        std::string line;
        while (std::getline(inFile, line))
        {
            std::stringstream ss(line);
            std::string id, name, mail, userPassword;

            // Read fields from the CSV line
            std::getline(ss, id, ',');

            
            if (id == itemId)
            {
                return true; 
            }
        }
    }

    return false; 
}

void LibraryDatabase::deleteItem(const string& itemId)
{
    std::string fileName;
    std::string files[3] = {bookFile, cdFile, magazineFile};

    for(int i = 0; i < 3; i++){
        fileName = files[i];
        removeFromFile(fileName, itemId);
    }

    //removeFromFile(fileName, item->getItemId());
}

void LibraryDatabase::addUser(const string &userId, const string &userName, const string &email, int password)
{
    ostringstream data;
    data << userId << "," << userName << "," << email << "," << password << "\n";
    appendToFile(userFile, data.str());
}

void LibraryDatabase::deleteUser(const string &userId)
{
    removeFromFile(userFile, userId);
}

bool LibraryDatabase::existUserById(const std::string &userId)
{
    std::ifstream inFile(userFile); // Ensure `userFile` is the path to your CSV file
    if (!inFile.is_open())
    {
        return false; // File couldn't be opened
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::string id, name, email, userPassword;

        // Read fields from the CSV line
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, email, ',');
        std::getline(ss, userPassword, ',');

        // Compare the userId and password
        if (id == userId )
        {
            return true; // User found
        }
    }

    return false; // User not found
}

// This method is for signup process
bool LibraryDatabase::existUser(const std::string &email)
{
    std::ifstream inFile(userFile); // Ensure `userFile` is the path to your CSV file
    if (!inFile.is_open())
    {
        return false; // File couldn't be opened
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::string id, name, mail, userPassword;

        // Read fields from the CSV line
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, mail, ',');
        std::getline(ss, userPassword, ',');

        // Compare the userId and password
        if (mail == email)
        {
            return true; // User found
        }
    }

    return false; // User not found
}

void LibraryDatabase::addReservation(Reservation *reservation)
{
    string reservationData = reservation->getReservationID() + "," +
                             reservation->getMemberID() + "," +
                             reservation->getItemID();

    appendToFile(reservationFile, reservationData);
}

void LibraryDatabase::deleteReservation(const string &reservationId)
{
    removeFromFile(reservationFile, reservationId);
}

void LibraryDatabase::loadItem(const BorrowableItem &item)
{
    string fileName;
    const BorrowableItem *itemPtr = &item;
    if (dynamic_cast<const Book *>(itemPtr))
    {
        fileName = bookFile;
    }
    else if (dynamic_cast<const CD *>(itemPtr))
    {
        fileName = cdFile;
    }
    else if (dynamic_cast<const Magazine *>(itemPtr))
    {
        fileName = magazineFile;
    }
    else
    {
        cerr << "Invalid item type!" << endl;
        return;
    }

    ifstream inFile(fileName);
    string line;
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            stringstream ss(line);
            string id, title;
            getline(ss, id, ',');
            getline(ss, title, ',');

            if (id == item.getItemId())
            {
                cout << "Item Found: ID: " << id << ", Title: " << title << endl;
                inFile.close();
                return;
            }
        }
        cout << "Item not found: " << item.getItemId() << endl;
        inFile.close();
    }
    else
    {
        cerr << "Error encountered while opening file: " << fileName << endl;
    }
}

void LibraryDatabase::loadUser(const User &user)
{
    ifstream inFile(userFile);
    string line;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            stringstream ss(line);
            string id, name, email, password;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, email, ',');
            getline(ss, password, ',');

            if (strcmp(id.c_str(), user.getUserID().c_str()) == 0)
            {
                cout << "User Found: ID: " << id << ", Name: " << name << ", Email: " << email << endl;
                inFile.close();
                return;
            }
        }
        cout << "User not found!" << endl;
        inFile.close();
    }
    else
    {
        cerr << "Error encountered while opening file: " << userFile << endl;
    }
}

void LibraryDatabase::loadReservation(const Reservation &reservation)
{
    ifstream inFile(reservationFile);
    string line;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            stringstream ss(line);
            string reservationID, userID, itemID;
            getline(ss, reservationID, ',');
            getline(ss, userID, ',');
            getline(ss, itemID, ',');

            if (strcmp(reservationID.c_str(), reservation.getReservationID().c_str()) == 0)
            {
                cout << "Reservation Found: ReservationID: " << reservationID << ", UserID: " << userID << ", ItemID: " << itemID << endl;
                inFile.close();
                return;
            }
        }
        cout << "Reservation not found: " << reservation.getReservationID() << endl;
        inFile.close();
    }
    else
    {
        cerr << "Error encountered while opening file: " << reservationFile << endl;
    }
}

void LibraryDatabase::appendToFile(const string &fileName, const string &data)
{
    ofstream file(fileName, ios::app);
    if (!file.is_open())
    {
        cerr << "Could not open file: " << fileName << endl;
        return;
    }
    file << data;
    file.close();
}

void LibraryDatabase::removeFromFile(const string &fileName, const string &userId)
{
    ifstream inputFile(fileName);
    if (!inputFile.is_open())
    {
        cerr << "Could not open file: " << fileName << endl;
        return;
    }

    ostringstream updatedData;
    string line;
    while (getline(inputFile, line))
    {
        istringstream ss(line);
        string currentID;
        getline(ss, currentID, ',');
        if (currentID != userId)
        {
            updatedData << line << "\n";
        }
    }
    inputFile.close();

    ofstream outputFile(fileName);
    if (!outputFile.is_open())
    {
        cerr << "Could not open file: " << fileName << endl;
        return;
    }
    outputFile << updatedData.str();
    outputFile.close();
}

Member *LibraryDatabase::getUser(const std::string &userId)
{
    std::ifstream inFile(userFile); // Assumes 'userFile' is a member of LibraryDatabase holding the users.csv path
    std::string line;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            std::stringstream ss(line);
            std::string id, name, email, password;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, email, ',');
            getline(ss, password, ',');

            if (id == userId)
            {
                return new Member(id, name, email, password, this);
            }
        }
        inFile.close();
    }
    else
    {
        return NULL;
    }

    return NULL;
}
