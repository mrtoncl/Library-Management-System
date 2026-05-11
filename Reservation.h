#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <ctime> // Tarih için
#include "Member.h" 
#include "BorrowableItem.h"

class Member;

class Reservation {
public:
    // Kurucu
    Reservation(const std::string& reservationID, const std::string& memberID,
                const std::string& itemID, const std::tm& reservationDate);

    // Get (Alıcı) Metotları
    std::string getReservationID() const;
    std::string getMemberID() const;
    std::string getItemID() const;
    std::tm getReservationDate() const;

    // Rezervasyonları yönetme ile ilgili fonksiyonlar
    void setReservedItem(BorrowableItem* reservedItem); // Bir BorrowableItem ile ilişkilendir
    BorrowableItem* getReservedItem() const;

    void setMember(Member* member); // Bir Member ile ilişkilendir
    Member* getMember() const;

private:
    std::string reservationID;
    std::string memberID;
    std::string itemID;
    std::tm reservationDate;
    BorrowableItem* reservedItem = nullptr; // Rezerve edilen BorrowableItem'a işaretçi
    Member* member = nullptr;
};

#endif
