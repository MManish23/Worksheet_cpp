#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_BOOKS = 10;
const int TITLE_SIZE = 100;


void writeBooks(const char* fileName, char books[MAX_BOOKS][TITLE_SIZE]) {
    ofstream out(fileName, ios::binary);
    if (!out) {
        cout << "Error writing to file!" << endl;
        return;
    }
    out.write((char*)books, sizeof(char) * MAX_BOOKS * TITLE_SIZE);
    out.close();
}


void readBooks(const char* fileName, char books[MAX_BOOKS][TITLE_SIZE]) {
    ifstream in(fileName, ios::binary);
    if (!in) {
        cout << "Error reading from file!" << endl;
        return;
    }
    in.read((char*)books, sizeof(char) * MAX_BOOKS * TITLE_SIZE);
    in.close();
}


bool searchBook(char books[MAX_BOOKS][TITLE_SIZE], const char* title) {
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (strcmp(books[i], title) == 0)
            return true;
    }
    return false;
}

int main() {
    char books[MAX_BOOKS][TITLE_SIZE];
    char fileName[50];
    char searchTitle[TITLE_SIZE];

    cout << "Enter filename to save books: ";
    cin >> fileName;
    cin.ignore();


    for (int i = 0; i < MAX_BOOKS; i++) {
        cout << "Book " << i + 1 << ": ";
        cin.getline(books[i], TITLE_SIZE);
    }


    writeBooks(fileName, books);


    cout << "\nEnter a book title to search: ";
    cin.getline(searchTitle, TITLE_SIZE);


    readBooks(fileName, books);


    if (searchBook(books, searchTitle))
        cout << "Book found!" << endl;
    else
        cout << "Book not found." << endl;

    return 0;
}