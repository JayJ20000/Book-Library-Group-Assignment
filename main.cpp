#include <iostream>
#include <string>

using namespace std;

int promptMainMenu();
void readCatalogFromFile();
void writeCatalogToFile();
void searchCatalogByBook();
void searchCatalogByAuthor();
void addToCatalog();
void removeFromCatalog();
void printCatalog();

int main() {

    cout << "\nBook Catalog"
         << "\n============"
         << "\n\nAt any point, you can leave a prompt blank\nto return to the previous screen." << endl;

    int opt = 0;
    do {
        opt = promptMainMenu();
        switch (opt) {

            case 1: // import file
                readCatalogFromFile();
                break;

            case 2: // export file
                writeCatalogToFile();
                break;

            case 3: // search by book title
                searchCatalogByBook();
                break;

            case 4: // search by author name
                searchCatalogByAuthor();
                break;

            case 5: // add a book
                addToCatalog();
                break;

            case 6: // delete a book
                removeFromCatalog();
                break;

            case 7: // display complete catalog
                printCatalog();
                break;

            case 8:
                cout << "\nThank you for using Book Catalog!\n" << endl;
                break;

            default:
                cout << "* Invalid menu selection, try again." << endl;
                break;
        }
    } while (opt != 8);

    return 0;
}

int promptMainMenu() {

    unsigned int opt = 0;
    string val;
    
    cout << "\nMain Menu\n"
         << "\n1. Import from a Catalog File"
         << "\n2. Export to a Catalog File"
         << "\n3. Search by Book Title"
         << "\n4. Search by Author"
         << "\n5. Add a Book to the Catalog"
         << "\n6. Remove a Book from the Catalog"
         << "\n7. Display the entire Catalog"
         << "\n8. Exit"
         << "\n\nEnter a menu option: ";

    getline(cin, val);
    if (!val.empty() && val.find_first_not_of("1234567890") == string::npos) opt = stoi(val);

    return opt;

}

void readCatalogFromFile() {
    cout << "\nIMPORT FROM A CATALOG FILE" << endl;
}

void writeCatalogToFile() {
    cout << "\nEXPORT TO A CATALOG FILE" << endl;
}

void searchCatalogByBook() {
    cout << "\nSEARCH BY BOOK TITLE" << endl;
}

void searchCatalogByAuthor() {
    cout << "\nSEARCH BY AUTHOR" << endl;
}

void addToCatalog() {
    cout << "\nADD A BOOK TO THE CATALOG" << endl;
}

void removeFromCatalog() {
    cout << "\nREMOVE A BOOK FROM THE CATALOG" << endl;
}

void printCatalog() {
    cout << "\nDISPLAY THE ENTIRE CATALOG" << endl;
}