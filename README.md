# Airline Reservation System

## Description

The **Airline Reservation System** is a simple C++ console application that allows users to book, cancel, and modify flight reservations. It maintains a list of passengers and their seat allocations while providing an interactive menu-driven interface.

## Features

- **Book a Ticket**: Allows passengers to book a seat on the flight.
- **Cancel a Ticket**: Cancels an existing reservation.
- **Change Reservation**: Allows passengers to modify their seat allocation.
- **Display Passenger Details**: Lists all booked passengers along with their details.
- **Display Seat Map**: Shows available and booked seats.
- **Memory Management**: Ensures proper handling of dynamic memory.

## Technologies Used

- **C++**
- **OOP (Object-Oriented Programming)**
- **Linked List** for passenger management
- **Vectors** for seat availability tracking

## How to Run

1. **Compile the code** using a C++ compiler like g++:
   ```sh
   g++ airline_reservation.cpp -o airline
   ```
2. **Run the executable**:
   ```sh
   ./airline
   ```
3. **Follow the on-screen menu** to interact with the system.

## Usage Instructions

Upon running the program, the user will be presented with the following menu:

```
╔════════════════════════════════════════╗
║     AIRLINE RESERVATION SYSTEM         ║
╠════════════════════════════════════════╣
║ 1. Book Ticket                         ║
║ 2. Cancel Ticket                       ║
║ 3. Change Reservation                  ║
║ 4. Display Passenger Details           ║
║ 5. Display Seat Map                    ║
║ 6. Exit                                ║
╚════════════════════════════════════════╝
Enter your choice:
```

### Booking a Ticket

- Enter passenger details (name, age, gender, seat preference).
- If the seat is available, the booking is confirmed.

### Canceling a Ticket

- Enter the seat number of the reservation to cancel.
- The system will remove the passenger and mark the seat as available.

### Changing a Reservation

- Enter the current seat number.
- Choose a new available seat.
- The system updates the reservation.

### Displaying Passenger Details

- Lists all booked passengers with their details.

### Displaying Seat Map

- Shows available and booked seats for reference.

## Author

Varun Mangla

