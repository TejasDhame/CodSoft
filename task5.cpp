#include <iostream>
#include <vector>
#include <algorithm>

class Book {
public:
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;

    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), ISBN(i), available(true) {}
};


class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const std::string& title, const std::string& author, const std::string& ISBN) {
        books.emplace_back(title, author, ISBN);
    }

    void searchBook(const std::string& searchKey) {
        for (const auto& book : books) {
            if (book.title == searchKey || book.author == searchKey || book.ISBN == searchKey) {
                std::cout << "Book found: " << book.title << " by " << book.author << " (ISBN: " << book.ISBN << ")\n";
                return;
            }
        }
        std::cout << "Book not found.\n";
    }

    void checkoutBook(const std::string& ISBN) {
        auto it = std::find_if(books.begin(), books.end(), [ISBN](const Book& book) {
            return book.ISBN == ISBN && book.available;
        });

        if (it != books.end()) {
            it->available = false;
            std::cout << "Book checked out successfully.\n";
        } else {
            std::cout << "Book not available for checkout.\n";
        }
    }

    void returnBook(const std::string& ISBN) {
        auto it = std::find_if(books.begin(), books.end(), [ISBN](const Book& book) {
            return book.ISBN == ISBN && !book.available;
        });

        if (it != books.end()) {
            it->available = true;
            std::cout << "Book returned successfully.\n";
        } else {
            std::cout << "Invalid return. Book not checked out or not found.\n";
        }
    }
};

int main() {
    Library library;

    library.addBook("The Catcher in the Rye", "J.D. Salinger", "978-0-316-76948-0");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "978-0-06-112008-4");
    library.addBook("1984", "George Orwell", "978-0-452-28423-4");

    int choice;
    std::string searchKey, ISBN;

    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Search for a Book\n";
        std::cout << "2. Check out a Book\n";
        std::cout << "3. Return a Book\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter search key (title, author, or ISBN): ";
            std::cin >> searchKey;
            library.searchBook(searchKey);
            break;

        case 2:
            std::cout << "Enter ISBN of the book to check out: ";
            std::cin >> ISBN;
            library.checkoutBook(ISBN);
            break;

        case 3:
            std::cout << "Enter ISBN of the book to return: ";
            std::cin >> ISBN;
            library.returnBook(ISBN);
            break;

        case 4:
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

