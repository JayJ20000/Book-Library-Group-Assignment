#include <string>

#include "Entry.h"

using namespace std;

unsigned int const Entry::MAX_YEAR = 2023;
unsigned int const Entry::MIN_YEAR = 1500;
string const Entry::VALID_ISBN_CHARACTERS = "0123456789X";

Entry::Entry() {
    // throw integer 0 to indicate no parameters
    throw 0;
}

Entry::Entry(string const &book_title,
             string const &author_name,
             unsigned int const page_count,
             unsigned int const year_published,
             string const &isbn_number,
             double const price_usd) : bookTitle(book_title),
                                       authorName(author_name),
                                       pageCount(page_count),
                                       yearPublished(year_published),
                                       isbnNumber(isbn_number),
                                       priceUSD(price_usd) {
    
    // throw integer number based on parameter order number
    
    if (bookTitle.empty()) throw 1;
    if (authorName.empty()) throw 2;
    if (pageCount == 0) throw 3;
    if (priceUSD < 0) throw 6;
    if (yearPublished < MIN_YEAR || yearPublished > MAX_YEAR) throw 4;

    // remove hyphens in ISBN number
    for (int i = isbnNumber.length() - 1; i >= 0; i--) {
        if (isbnNumber[i] == '-') {
            isbnNumber.erase(i, 1);
        } else {
            if (VALID_ISBN_CHARACTERS.find(isbnNumber[i]) == string::npos) throw 5;
            if (i != 9 && isbnNumber[i] == 'X') throw 5; // X only valid as the 10th digit
        }
    }


    // isbn checkbit validation from https://en.wikipedia.org/wiki/ISBN
    switch (isbnNumber.length()) {

        case 10: {

            int t = 0, s = 0;
            for (int i = 0; i < 10; i++) {
                t += (isbnNumber[i] == 'X') ? 10 : isbnNumber[i] - 48;
                s += t;
            }

            if (s % 11 != 0) throw 5;
            break;
        }

        case 13: {

            int val = 0;
            for (int i = 0; i < 12; i += 2) {
                val += isbnNumber[i] - 48 + 3 * (isbnNumber[i + 1] - 48);
            }
            if (isbnNumber[12] - 48 != ((10 - (val % 10)) % 10)) throw 5;
            break;
        }

        default: {
            throw 5;
        }
    }

}

string Entry::getTitle() const {
    return bookTitle;
}

string Entry::getAuthor() const {
    return authorName;
}

unsigned int Entry::getPageCount() const {
    return pageCount;
}

unsigned int Entry::getYearPublished() const {
    return yearPublished;
}

string Entry::getISBN() const {
    return isbnNumber;
}

double Entry::getPrice() const {
    return priceUSD;
}