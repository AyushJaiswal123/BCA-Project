#include <iostream>
#include <string>
using namespace std;
class Book_library {
private:
    string ISBN,title,author;
public:
    Book_library(string ISBN, string title, string author): ISBN(ISBN), title(title), author(author) {
    }
    string getISBN(){
        return ISBN;
    }
    string getTitle(){
        return title;
    }
    string getAuthor(){
        return author;
    }
};
int main() {
    bool found = false;
    string ISBN;
    Book_library l1[10] = {
        Book_library("1000", "The C++ Programming Language", "Bjarne Stroustrup"),
        Book_library("1001", "Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides"),
        Book_library("1002", "The Catcher in the Rye", "J.D. Salinger"),
        Book_library("1003", "To Kill a Mockingbird", "Harper Lee"),
        Book_library("1004", "1984", "George Orwell"),
        Book_library("1005", "Pride and Prejudice", "Jane Austen"),
        Book_library("1006", "The Great Gatsby", "F. Scott Fitzgerald"),
        Book_library("1007", "The Hobbit", "J.R.R. Tolkien"),
        Book_library("1008", "Harry Potter and the Sorcerer's Stone", "J.K. Rowling"),
        Book_library("1009", "The Lord of the Rings", "J.R.R. Tolkien"),
    };
    cout << "Enter the ISBN of the Book_library: ";
    cin >> ISBN;
    for (int i = 0; i < 10; ++i) {
        if (l1[i].getISBN() == ISBN) {
            cout << "Details of Book_library are:"<<endl;
            cout << "Title:"<< l1[i].getTitle()<<endl;
            cout << "Author:"<< l1[i].getAuthor()<<endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Your book with ISBN "<< ISBN<<" is not available in the library" << endl;
    }
    return 0;
}
