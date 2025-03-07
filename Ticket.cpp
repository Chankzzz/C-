#include <iostream>
#include <bits/stdc++.h>
#include "Ticket.h"
#include "Passenger.h"

using namespace std;
bool Ticket::checkTicketsAreAvailable()
{
    int total = this->lower_berth_tickets + this->upper_berth_tickets + this->rac_tickets + this->waiting_ticket;

    return total < total_ticket;
}

void Ticket::bookTicket(Passenger &p, deque<pair<string, Passenger>> &confirmed_tickets)
{
    string name, hasChildren;
    int age;
    char gender, berth;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, name);
    p.setName(name);

    cout << "Enter age: ";
    cin >> age;
    p.setAge(age);

    cout << "Gender (M/F): ";
    cin >> gender;
    p.setGender(gender);

    if (gender == 'F' && age > 10)
    {
        cout << "Do you have children? (Y/N): ";
        cin >> hasChildren;
    }

    cout << "Enter berth (L/M/U): ";
    cin >> berth;

    if (age < 5)
    {
        p.setBerth('C');
        p.setId(++this->childrenId);
        p.setBerth(berth);
        cout << "Ticket booked successfully" << endl;
        confirmed_tickets.push_back({p.getId(), p});
        return;
    }

    if (checkTicketsAreAvailable())
    {
        cout << "Sorry, no tickets available" << endl;
        return;
    }

    if (age > 60 || (gender == 'F' && hasChildren == "Yes"))
    {
        if (this->lower_berth_tickets < total_lower_berth)
        {
            p.setBerth('L');
            this->lower_berth_tickets++;
            p.setId(this->lower_berth_tickets);
        }
        else
        {
            allocateTicket(p, berth);
        }
    }
    else
    {
        allocateTicket(p, berth);
    }

    cout << "Ticket booked successfully" << endl;
    confirmed_tickets.push_back({p.getId(), p});
}

void Ticket::printBookedTickets(deque<pair<string, Passenger>> passenger)
{
    while (!passenger.empty())
    {
        auto it = passenger.front();
        Passenger pl = it.second;

        cout << setw(10) << left << "Name       :" << pl.getName() << endl;
        cout << setw(10) << left << "Ticket Id  :" << pl.getId() << endl;
        cout << setw(10) << left << "Age        :" << pl.getAge() << endl;
        cout << setw(10) << left << "Gender     :" << pl.getGender() << endl;
        cout << setw(10) << left << "Berth      :" << pl.getBerth() << endl;
        passenger.pop_front();
        cout << "----------------------------------" << endl;
    }

    cout << "Total booked Tickets: " << this->confirmed_tickets + this->waiting_ticket + this->rac_tickets << endl;
}

void Ticket::allocateTicket(Passenger &p, char &berth)
{
    if (berth == 'L')
    {
        if (this->lower_berth_tickets < total_lower_berth)
        {
            p.setBerth(berth);
            this->lower_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->lower_berth_tickets);
        }
        else if (this->middle_berth_tickets < total_middle_berth)
        {
            p.setBerth('M');
            this->middle_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->middle_berth_tickets);
        }
        else if (this->upper_berth_tickets < total_upper_berth)
        {
            p.setBerth('U');
            this->upper_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->upper_berth_tickets);
        }
        else if (this->rac_tickets < total_rac_ticket)
        {
            p.setBerth('R');
            this->rac_tickets++;
            this->confirmed_tickets++;
            p.setId(this->rac_tickets);
        }
        else
        {
            p.setBerth('W');
            this->waiting_ticket++;
            p.setId(this->waiting_ticket);
        }
    }
    else if (berth == 'M')
    {
        if (this->middle_berth_tickets < total_middle_berth)
        {
            p.setBerth('M');
            this->middle_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->middle_berth_tickets);
        }
        else if (this->lower_berth_tickets < total_lower_berth)
        {
            p.setBerth('L');
            this->lower_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->lower_berth_tickets);
        }
        else if (this->upper_berth_tickets < total_upper_berth)
        {
            p.setBerth('U');
            this->upper_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->upper_berth_tickets);
        }
        else if (this->rac_tickets < total_rac_ticket)
        {
            p.setBerth('R');
            this->rac_tickets++;
            this->confirmed_tickets++;
            p.setId(this->rac_tickets);
        }
        else
        {
            p.setBerth('W');
            this->waiting_ticket++;
            p.setId(this->waiting_ticket);
        }
    }
    else
    {
        if (this->upper_berth_tickets < total_upper_berth)
        {
            p.setBerth('U');
            this->upper_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->upper_berth_tickets);
        }
        else if (this->lower_berth_tickets < total_lower_berth)
        {
            p.setBerth('L');
            this->lower_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->lower_berth_tickets);
        }
        else if (this->middle_berth_tickets < total_middle_berth)
        {
            p.setBerth('M');
            this->middle_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->middle_berth_tickets);
        }
        else if (this->rac_tickets < total_rac_ticket)
        {
            p.setBerth('R');
            this->rac_tickets++;
            this->confirmed_tickets++;
            p.setId(this->rac_tickets);
        }
        else
        {
            p.setBerth('W');
            this->waiting_ticket++;
            p.setId(this->waiting_ticket);
        }
    }
}

void Ticket::printAvailableTickets()
{
    cout << "--------Available tickets------" << endl;
    cout << "Lower Berth Tickets  : " << total_lower_berth - this->lower_berth_tickets << endl;
    cout << "Middle Berth Tickets : " << total_middle_berth - this->middle_berth_tickets << endl;
    cout << "Upper Berth Tickets  : " << total_upper_berth - this->upper_berth_tickets << endl;
    cout << "RAC Berth Tickets    : " << total_rac_ticket - this->rac_tickets << endl;
    cout << "Waiting List tickets : " << total_waiting_tickets - this->waiting_ticket << endl;
}

void Ticket::cancelTicket(deque<pair<string, Passenger>> &confirmed_tickets)
{
    string id;
    bool found = false;
    cout << "Enter Ticket Id: ";
    cin >> id;
    char berth;
    auto it = confirmed_tickets.begin();
    while (it != confirmed_tickets.end())
    {
        if (it->first == id)
        {
            found = true;
            berth = it->first[1];
            decrementTickets(it->first);
            confirmed_tickets.erase(it);
            cout << "Tickets canceled Successfully" << endl;
            break;
        }
        it++;
    }
    if (!found)
        cout << "Ticket not found" << endl;
    if (this->rac_tickets > 0)
        reorderRackTickets(confirmed_tickets, berth);
    if (this->waiting_ticket > 0 && this->rac_tickets < total_rac_ticket)
        reorderWaitingList(confirmed_tickets, berth);
}

void Ticket::decrementTickets(string Id)
{
    if (Id[0] == 'L')
    {
        this->lower_berth_tickets++;
        this->confirmed_tickets++;
    }
    else if (Id[0] == 'M')
    {
        this->middle_berth_tickets++;
        this->confirmed_tickets++;
    }
    else if (Id[0] == 'U')
    {
        this->upper_berth_tickets++;
        this->confirmed_tickets++;
    }
    else if (Id[0] == 'R')
    {
        this->rac_tickets++;
    }
    else if (Id[0] == 'W')
    {
        this->waiting_ticket++;
    }
}
// void Ticket::reorderRackTickets(deque<pair<string, Passenger>> &confirmed_tickets, char &berth)
void Ticket::reorderRackTickets(deque<pair<string, Passenger>> confirmed_tickets, char &berth)
{
    Passenger temp, p1;
    auto it = confirmed_tickets.begin();
    while (it != confirmed_tickets.end())
    {
        if (it->first[0] == 'R')
        {
            temp = it->second;
            confirmed_tickets.erase(it);
            this->rac_tickets--;
            break;
        }
        it++;
        p1.setName(temp.getName());
        p1.setAge(temp.getAge());
        p1.setGender(temp.getGender());
        p1.setBerth(berth);

        // to get proper id according to berth
        if (berth == 'L')
            p1.setId(++this->lower_berth_tickets);
        else if (berth == 'M')
            p1.setId(++this->middle_berth_tickets);
        else
            p1.setId(++this->upper_berth_tickets);
        confirmed_tickets.push_back({p1.getId(), p1});
        this->confirmed_tickets++;
    }
}

void Ticket::reorderWaitingList(deque<pair<string, Passenger>> &confirmed_tickets, char &berth)
{
    Passenger temp, p1;
    auto it = confirmed_tickets.begin();
    while (it != confirmed_tickets.end())
    {
        if (it->first[0] == 'W')
        {
            temp = it->second;
            confirmed_tickets.erase(it);
            this->waiting_ticket--;
            break;
        }
        it++;
    }
    p1.setName(temp.getName());
    p1.setAge(temp.getAge());
    p1.setGender(temp.getGender());
    p1.setBerth('R');
    p1.setId(++this->rac_tickets);
    confirmed_tickets.push_back({p1.getId(), p1});
}