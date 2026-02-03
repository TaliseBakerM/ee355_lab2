#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Define the Book class (one book)
class Book {

    public:
        // Some attributes
        string BookID;
        string BookName;
        string BookAuthor;
        // Making this date since the input file has date
        string DateOfPub;
        string YearOfPub;
        string Price;
        string Status;
        
    // A func to display all the info of the books to use when I later am searching for books
    void displayBookInfo() {
        cout << "Book Title: " << BookName << endl;
        cout << "Book ID: " << BookID << endl;
        cout << "Author: " << BookAuthor << endl;
        cout << "Date Published: " << DateOfPub << endl;
        cout << "Price: " << Price << endl;
        cout << "Status: " << Status << endl;
    }
};

// A function to help get rid of whitespace
string trim(string s) {
    int start = s.find_first_not_of(" \t\r");
    int end = s.find_last_not_of(" \t\r");

    if (start == string::npos)
        return "";

    return s.substr(start, end - start + 1);
}


// Define the BookList class (more than one book)
class BookList {
    private:
        // Use the vector thing we learned in lecture to make multiple book objects in a book list
        vector<Book> books;
    
    public:
        // Function to load the books from the file
        void loadBooks(string filename) {
            // open file
            ifstream bookFile(filename);

            // loop through until you get to the end of the file
            while (true) {
                Book individualBook;

                // see if we are at the end yet
                if (!getline(bookFile, individualBook.BookName))
                    return;

                getline(bookFile, individualBook.BookID);
                getline(bookFile, individualBook.BookAuthor);
                getline(bookFile, individualBook.DateOfPub);
                getline(bookFile, individualBook.Price);
                getline(bookFile, individualBook.Status);

                // Get rid of all the extra whitespace and stuff
                individualBook.BookName = trim(individualBook.BookName);
                individualBook.BookID = trim(individualBook.BookID);
                individualBook.BookAuthor = trim(individualBook.BookAuthor);
                individualBook.DateOfPub = trim(individualBook.DateOfPub);
                individualBook.Price = trim(individualBook.Price);
                individualBook.Status = trim(individualBook.Status);


                // Skip the blank lines
                string empty;
                getline(bookFile, empty);

                books.push_back(individualBook);
            }

            // close to file
            bookFile.close();
        }

        // A function to find books by name, im assuming there is only one book of each name but that can be changed easily if thats not the case so the func is more like the findAuthor one
        void findName(string bookName) {
            for (int i = 0; i < books.size(); i++) {
                if (books[i].BookName == bookName) {
                    books[i].displayBookInfo();
                    return;
                }
            }
            cout << "No book with that name was found" <<  endl;
        }

        // A function to find a book with an ID and then say if there is none
        void findID(string bookID) {
            for (int i = 0; i < books.size(); i++) {
                if (books[i].BookID == bookID) {
                    books[i].displayBookInfo();
                    return;
                }
            }
            cout << "No book with that ID was found" <<  endl;
        }

        // A function to find books by author and display them
        void findAuthor(string bookAuthor) {
            for (int i = 0; i < books.size(); i++) {
                if (books[i].BookAuthor == bookAuthor) {
                    books[i].displayBookInfo();
                }
            }
        }

};


// Main function needed
int main() {
    BookList libraryCatalogue;

    // Use the function to read in the file
    libraryCatalogue.loadBooks("inputList.txt");

    // Ask the reader for some choices to pick and loop until they wanna exit
    int userChoice = 0;
    while (userChoice != 4) {
        // print out the whole menu situation
        cout << "\nLibrary System" << endl;
        cout << "1. Find all the book details by a given name" << endl;
        cout << "2. Find all the book details by a given ID" << endl;
        cout << "3. Find books by a given author" << endl;
        cout << "4. Exit the library catalogue" << endl;
        cout << "Enter choice: ";
        cin >> userChoice;
        cin.ignore();


        // Go through and do the appropriate action for each choice
        if (userChoice == 1) {
            string bookName;
            cout << "Enter book name: ";
            getline(cin, bookName);
            libraryCatalogue.findName(bookName);
        }
        else if (userChoice == 2) {
            string bookID;
            cout << "Enter book ID: ";
            getline(cin, bookID);
            libraryCatalogue.findID(bookID);
        }
        else if (userChoice == 3) {
            string bookAuthor;
            cout << "Enter author name: ";
            getline(cin, bookAuthor);
            libraryCatalogue.findAuthor(bookAuthor);
        }

    }
    // must return 0
    return 0;
}








