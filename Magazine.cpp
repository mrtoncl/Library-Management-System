#include "Magazine.h"
#include <iostream>

Magazine::Magazine(const std::string &itemID, const std::string &title,
                   const std::string &category,
                   const std::string &issueNumber, const std::string &publicationDate)
    : BorrowableItem(itemID, title, category), issueNumber(issueNumber), publicationDate(publicationDate) {}

std::string Magazine::getIssueNumber() const
{
  return issueNumber;
}

std::string Magazine::getPublicationDate() const
{
  return publicationDate;
}

void Magazine::displayDetails() const
{
  std::cout << "Magazine Details:\n";
  std::cout << "Title: " << title << "\n";
  std::cout << "Issue Number: " << issueNumber << "\n";
  std::cout << "Publication Date: " << publicationDate << "\n";
}

