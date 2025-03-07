#include <iostream>
// #include <windows.h>  // Only if using Windows-specific commands
#include <deque>
#include <utility>
#include "passenger.h"
#include "Ticket.h"

using namespace std;

void display()
{
    cout << "***************Welcome to Railway Reservation System***************" << endl;
    cout << "1. Book Ticket" << endl;
    cout << "2. Cancel Ticket" << endl;
    cout << "3. Print Booked Tickets" << endl;
    cout << "4. Print Available Tickets" << endl;
    cout << "5. Exit" << endl;
}

int main()
{
    deque<pair<string, Passenger>> confirmed_tickets;  // Corrected deque declaration
    Ticket t;  // Updated class name

    Passenger p;
    int choice;

    do
    {
        #ifdef _WIN32
            system("cls");  // Clears screen in Windows
        #else
            system("clear");  // Clears screen in Linux/macOS
        #endif

        display();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.bookTicket(p, confirmed_tickets);
            break;

        case 2:
            t.cancelTicket(confirmed_tickets);
            break;

        case 3:
            t.printBookedTickets(confirmed_tickets);

            break;

        case 4:
            t.printAvailableTickets();

            break;

        case 5:
            cout << "Thank you for using the Railway Reservation System!" << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
            cin.get();
            break;
        }
        _getwch();

    } while (true);

    return 0;
}
