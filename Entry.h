#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry {

private:

    static unsigned int const MAX_YEAR;
    static unsigned int const MIN_YEAR;

    static std::string const VALID_ISBN_CHARACTERS;

    std::string bookTitle;
    std::string authorName;
    unsigned int pageCount;
    unsigned int yearPublished;
    std::string isbnNumber;
    float priceUSD;

public:

    Entry();
    Entry(std::string const &book_title, std::string const &author_name, unsigned int const page_count, unsigned int const year_published, std::string const &isbn_number, float const price_usd);

    std::string getTitle() const;
    std::string getAuthor() const;
    unsigned int getPageCount() const;
    unsigned int getYearPublished() const;
    std::string getISBN() const;
    float getPrice() const;


};

#endif // ENTRY_H