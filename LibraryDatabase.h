#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <unordered_map>
#include "BorrowableItem.h"
#include "User.h"
#include "Reservation.h"
#include "Book.h"
#include "Magazine.h"
#include "Member.h"
#include "CD.h"
using namespace std;

class Member;
class Reservation;

class LibraryDatabase {
private:
    string userFile;
    string bookFile;
    string cdFile;
    string magazineFile;
    string reservationFile;

    // Private constructor to prevent external instantiation
    LibraryDatabase(const string& userFile, const string& bookFile,
                    const string& cdFile, const string& magazineFile, 
                    const string& reservationFile);

    // Static instance of LibraryDatabase
    static LibraryDatabase* instance;

    void appendToFile(const string& fileName, const string& data);
    void removeFromFile(const string& fileName, const string& id);

public:
    // Delete copy constructor and assignment operator to prevent copying
    LibraryDatabase(const LibraryDatabase&) = delete;
    LibraryDatabase& operator=(const LibraryDatabase&) = delete;

    // Static method to access the instance
    static LibraryDatabase* getInstance(const string& userFile = "", const string& bookFile = "",
                                        const string& cdFile = "", const string& magazineFile = "", 
                                        const string& reservationFile = "");

    void addItem(BorrowableItem* item);
    void addBook(string bookId, string title, string category, string ISBN, string authorName);
    void addMagazine(string itemId, string title, string category, string issueNumber, string publicationDate);
    void addCd(string itemID, string title, string category, string artist, string genre);
    void deleteItem(const string& itemId);
    void loadItem(const BorrowableItem& item);
    bool existItem(const std::string& itemId);

    void addUser(const string& userId, const string& userName, const string& email, int password);
    void deleteUser(const string& userId);
    void loadUser(const User& user);
    bool existUserById(const string& userId);

    bool existUser(const string& email);
    Member* getUser(const string& userId);

    void addReservation(Reservation* reservation);
    void deleteReservation(const string& reservationId);
    void loadReservation(const Reservation& reservation);
};

#endif



/*

user history için de database olmalı.
Merve Ozkan

How Book Reservation Works
User Request: A library member browses the catalog and finds a book they want to borrow, but it might already be checked out by another person.

Reservation Process: The user can choose to reserve the book. This usually means that the library system will note down the user's request and wait for the book to become available.

Notification: Once the book is returned by the current borrower, the system will notify the user who made the reservation (either via email, app notification, etc.), letting them know that the book is now available.

Pick-up Period: The user typically has a set amount of time to pick up the reserved book after being notified (e.g., 2 or 3 days).

Borrowing: Once the user picks up the book, it is checked out to them, and the reservation is cleared.
*/
