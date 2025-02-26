#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Passenger {
public:
    string name;
    int age;
    string gender;
    int seat_number;
    Passenger* next;

    Passenger(string n, int a, string g, int s) : name(n), age(a), gender(g), seat_number(s), next(nullptr) {}
};

class Flight {
private:
    Passenger* head;
    vector<int> seats;
    int total_seats;

public:
    Flight(int capacity) : total_seats(capacity) {
        head = nullptr;
        seats.resize(capacity, 0);
    }

    void book_ticket() {
        string name, gender;
        int age, seat_number;
        cout << "Enter passenger name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter gender: ";
        cin >> gender;

        do {
            cout << "Enter preferred seat number (1-" << total_seats << "): ";
            cin >> seat_number;
        } while (seat_number < 1 || seat_number > total_seats || seats[seat_number - 1] == 1);

        Passenger* new_passenger = new Passenger(name, age, gender, seat_number);
        new_passenger->next = head;
        head = new_passenger;
        seats[seat_number - 1] = 1;
        cout << "Ticket booked successfully! Seat Number: " << seat_number << "\n";
    }

    void cancel_ticket() {
        int seat_number;
        cout << "Enter seat number to cancel: ";
        cin >> seat_number;

        Passenger* temp = head, *prev = nullptr;
        while (temp != nullptr && temp->seat_number != seat_number) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "No booking found for this seat.\n";
            return;
        }

        if (prev == nullptr)
            head = temp->next;
        else
            prev->next = temp->next;

        seats[seat_number - 1] = 0;
        delete temp;
        cout << "Ticket cancelled successfully.\n";
    }

    void change_reservation() {
        int old_seat, new_seat;
        cout << "Enter current seat number: ";
        cin >> old_seat;

        Passenger* temp = head;
        while (temp != nullptr && temp->seat_number != old_seat) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "No reservation found for this seat.\n";
            return;
        }

        do {
            cout << "Enter new seat number (1-" << total_seats << "): ";
            cin >> new_seat;
        } while (new_seat < 1 || new_seat > total_seats || seats[new_seat - 1] == 1);

        seats[old_seat - 1] = 0;
        seats[new_seat - 1] = 1;
        temp->seat_number = new_seat;
        cout << "Reservation updated successfully.\n";
    }

    void display_passenger_details() {
        Passenger* temp = head;
        if (!temp) {
            cout << "No passengers booked yet.\n";
            return;
        }

        cout << "Passenger List:\n";
        while (temp) {
            cout << "Name: " << temp->name << ", Age: " << temp->age << ", Gender: " << temp->gender
                 << ", Seat: " << temp->seat_number << "\n";
            temp = temp->next;
        }
    }

    void display_seat_map() {
        cout << "Seat Availability:\n";
        for (int i = 0; i < total_seats; i++) {
            cout << "Seat " << i + 1 << ": " << (seats[i] ? "Booked" : "Available") << "\n";
        }
    }

    ~Flight() {
        Passenger* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void display_menu() {
    cout << "\n╔════════════════════════════════════════╗\n";
    cout << "║     AIRLINE RESERVATION SYSTEM        ║\n";
    cout << "╠════════════════════════════════════════╣\n";
    cout << "║ 1. Book Ticket                         ║\n";
    cout << "║ 2. Cancel Ticket                       ║\n";
    cout << "║ 3. Change Reservation                  ║\n";
    cout << "║ 4. Display Passenger Details           ║\n";
    cout << "║ 5. Display Seat Map                    ║\n";
    cout << "║ 6. Exit                                ║\n";
    cout << "╚════════════════════════════════════════╝\n";
    cout << "Enter your choice: ";
}

int main() {
    Flight flight(10);
    int choice;

    while (true) {
        display_menu();
        cin >> choice;

        switch (choice) {
            case 1:
                flight.book_ticket();
                break;
            case 2:
                flight.cancel_ticket();
                break;
            case 3:
                flight.change_reservation();
                break;
            case 4:
                flight.display_passenger_details();
                break;
            case 5:
                flight.display_seat_map();
                break;
            case 6:
                cout << "Exiting system.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
