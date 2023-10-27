#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry {

private:

    std::string bookTitle;
    std::string authorName;
    unsigned int pageCount;
    unsigned int yearPublished;
    std::string isbnNumber;
    float priceUSD;

public:

    Entry();
    ~Entry();
    
};

#endif // ENTRY_H