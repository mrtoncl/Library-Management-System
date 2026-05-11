#include "Book.h"
#include <iostream>

Book::Book(const std::string &itemID, const std::string &title,
           const std::string &category, const std::string &ISBN, const std::string &authorName)
    : BorrowableItem(itemID, title, category), ISBN(ISBN), authorName(authorName) {}

std::string Book::getISBN() const
{
  return ISBN;
}

std::string Book::getAuthorName() const
{
  return authorName;
}

void Book::displayDetails() const
{
  std::cout << "Book Details:\n";
  std::cout << "Title: " << title << "\n";
  std::cout << "Author: " << authorName << "\n";
  std::cout << "ISBN: " << ISBN << "\n";
}



