#pragma once
#include <iostream>
#include <deque>
#include "passenger.h" // Ensure this file is correctly implemented

using namespace std;

class Ticket {
private:
    int total_ticket;
    int lower_berth_tickets;
    int upper_berth_tickets; // Fixed inconsistency
    int middle_berth_tickets;
    int rac_tickets;
    int waiting_ticket;
    int total_lower_berth;
    int total_middle_berth; // Fixed typo
    int total_upper_berth;
    int total_rac_ticket;
    int total_waiting_tickets;
    int childrenId; // Fixed typo
    int confirmed_tickets;

public:
    // uctor to initialize ticket counts
    Ticket(int lower = 1, int middle = 1, int upper = 1, int rac = 2, int waiting = 2)
        : lower_berth_tickets(0), upper_berth_tickets(0), middle_berth_tickets(0), 
          rac_tickets(0), waiting_ticket(0), total_lower_berth(lower), 
          total_middle_berth(middle), total_upper_berth(upper), 
          total_rac_ticket(rac), total_waiting_tickets(waiting), 
          childrenId(0), confirmed_tickets(0) {}

    // Ticket management functions
    bool checkTicketsAreAvailable();
    void bookTicket(Passenger& p, deque<pair<string, Passenger>>& confirmed_tickets);
    void cancelTicket(deque<pair<string, Passenger>>& confirmed_tickets);
    void printBookedTickets(deque<pair<string, Passenger>> Passenger);
        //  printBookedTickets(deque<pair<string, Passenger>> passenger)
    void printAvailableTickets() ;
    
    // Utility functions
    void allocateTicket(Passenger& p, char& berth);
    void decrementTickets(string id);
    void reorderRackTickets(deque<pair<string, Passenger>>confirmed_tickets, char& berth);
    void reorderWaitingList(deque<pair<string, Passenger>>& confirmed_tickets, char& berth);
};
