#include <iostream>
#include "Database.h"
using namespace std;

// Create a global DB of books
Database g_db;


// Receive a command from the user and run it.
void run_commands() {
    while (true) {
        int choice;
        int book_id;

        // Display the menu of options
        cout << endl;
        cout << "Please select an option:" << endl;
        cout << "1) View Catalog of books" << endl;
        cout << "2) Checkout a book" << endl;
        cout << "3) Return a book" << endl;
        cout << "4) List of available books" << endl;
        cout << "5) Quit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                g_db.print_catalog();
                break;
            case 2:
                cout << "Enter the book ID: ";
                cin >> book_id;
                g_db.checkout_book(book_id);
                break;
            case 3:
                cout << "Enter the book ID: ";
                cin >> book_id;
                g_db.return_book(book_id);
                break;
            case 4:
                cout << "Not yet implemented" << endl;
                break;
            case 5:
                cout << "Terminating" << endl;
                return;
                break;
            default:
                cerr << "Invalid choice " << choice << endl;
                continue;
        }
    }
}

int main(int argc, char* argv[]) {
    cout << endl;
    cout << "Welcome LevelOps Library Management System" << endl;
    cout << "==========================================" << endl << endl;

    // Initialize the DB of books
    g_db.initialize();

    run_commands();
    return 0;
}
