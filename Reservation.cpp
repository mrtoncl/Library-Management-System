#include "Reservation.h"
#include <iostream>
#include <iomanip>

Reservation::Reservation(const std::string& reservationID, const std::string& memberID,
                         const std::string& itemID, const std::tm& reservationDate)
    : reservationID(reservationID), memberID(memberID), itemID(itemID), reservationDate(reservationDate) {}

std::string Reservation::getReservationID() const {
    return reservationID;
}

std::string Reservation::getMemberID() const {
    return memberID;
}

std::string Reservation::getItemID() const {
    return itemID;
}

std::tm Reservation::getReservationDate() const{
    return reservationDate;
}

void Reservation::setReservedItem(BorrowableItem* reservedItem)
{
    this->reservedItem = reservedItem;
}

BorrowableItem* Reservation::getReservedItem() const
{
    return reservedItem;
}