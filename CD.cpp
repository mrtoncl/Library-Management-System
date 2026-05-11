#include "CD.h"
#include <iostream>

CD::CD(const std::string &itemID, const std::string &title,
       const std::string &category, const std::string &artist, const std::string &genre)
    : BorrowableItem(itemID, title, category), artist(artist), genre(genre) {}

std::string CD::getArtist() const
{
  return artist;
}

std::string CD::getGenre() const
{
  return genre;
}

void CD::displayDetails() const
{
  std::cout << "CD Details:\n";
  std::cout << "Title: " << title << "\n";
  std::cout << "Artist: " << artist << "\n";
  std::cout << "Genre: " << genre << "\n";
}