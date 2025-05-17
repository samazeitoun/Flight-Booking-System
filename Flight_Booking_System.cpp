#include <iostream>
#include <string>
using namespace std;


int seatPrice = 0;
int foodPrice = 0;
int servicesPrice = 0;
int baggagePrice = 0;
int ticketsPrice = 0;


void printTicket(string name, int phone, string mail,
                 string origin, string destination,
                 int dyear, int dmonth, int dday, int dhour, int dminute,
                 int ayear, int amonth, int aday, int ahour, int aminute,
                 string bagSize, int bagWeight, int bagCost, int seatNumber) {
    cout << "+------------------------------------------+\n";
    cout << "|              TICKET RECEIPT              |\n";
    cout << "+------------------------------------------+\n";
    cout << "| Name      : " << name << "\n";
    cout << "| Phone     : " << phone << "\n";
    cout << "| Email     : " << mail << "\n";
    cout << "| Route     : " << origin << " ----> " << destination << "\n";
    cout << "| Departure : " << dyear << "-";
    if (dmonth < 10) cout << "0";
    cout << dmonth << "-";
    if (dday < 10) cout << "0";
    cout << dday << "  ";
    if (dhour < 10) cout << "0";
    cout << dhour << ":";
    if (dminute < 10) cout << "0";
    cout << dminute << "\n";
    cout << "| Arrival   : " << ayear << "-";
    if (amonth < 10) cout << "0";
    cout << amonth << "-";
    if (aday < 10) cout << "0";		
    cout << aday << "  ";
    if (ahour < 10) cout << "0";
    cout << ahour << ":";
    if (aminute < 10) cout << "0";
    cout << aminute << "\n";
    cout << "| Baggage   : " << bagSize << " (" << bagWeight << " KG)\n";
    cout << "| Seat      : " << seatNumber << "\n";
    cout << "+------------------------------------------+\n";
}


void showSeats(const bool seats[], int totalSeats) {
    cout << "Available seats:\n";
    for (int i = 0; i < totalSeats; i++) {
        cout << "Seat " << (i + 1);
        if (seats[i]) cout << " (Taken)"; 
        else cout << " (Available)";
        cout << "\n";
    }
}


bool reserveSeat(bool seats[], int totalSeats, int seatNumber) {
    if (seatNumber < 1 || seatNumber > totalSeats) {
        cout << "Invalid seat number!\n";
        return false;
    }
    else if (seats[seatNumber - 1]) {
        cout << "Seat already taken!\n";
        return false;
    }
    else {
        seats[seatNumber - 1] = true;
        cout << "Seat " << seatNumber << " reserved successfully!\n";
        return true;
    }
}


double orderFood() {
    int Typefood, Num_Typefood, quantity;
    double price = 0, total = 0;

    while (true) {
        price = 0;
        cout << "\n====== Choose Category ======\n";
        cout << "1. Fast Food\n";
        cout << "2. Healthy Food\n";
        cout << "3. Drinks\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> Typefood;

        if (Typefood == 0) break;

        cout << "\n";
        if (Typefood == 1) {
            cout << "-- Fast Food Menu --\n";
            cout << "1. Burger - 70 EGP\n";
            cout << "2. Fried Chicken - 75 EGP\n";
            cout << "3. Shawarma - 60 EGP\n";
            cout << "4. Fries - 30 EGP\n";
            cout << "Enter item number: ";
            cin >> Num_Typefood;
            cout << "Enter quantity: ";
            cin >> quantity;

            if (Num_Typefood == 1) price = 70;
            else if (Num_Typefood == 2) price = 75;
            else if (Num_Typefood == 3) price = 60;
            else if (Num_Typefood == 4) price = 30;
            else {
                cout << "Invalid item number. Try again.\n";
                continue;
            }
        }
        else if (Typefood == 2) {
            cout << "-- Healthy Food Menu --\n";
            cout << "1. Grilled Chicken - 90 EGP\n";
            cout << "2. Salad - 40 EGP\n";
            cout << "3. Caesar Salad - 70 EGP\n";
            cout << "4. Chicken Caesar Salad - 170 EGP\n";
            cout << "5. Quinoa Bowl - 120 EGP\n";
            cout << "6. Avocado Toast - 80 EGP\n";
            cout << "Enter item number: ";
            cin >> Num_Typefood;
            cout << "Enter quantity: ";
            cin >> quantity;
           
            if (Num_Typefood == 1) price = 90;
            else if (Num_Typefood == 2) price = 40;
            else if (Num_Typefood == 3) price = 70;
            else if (Num_Typefood == 4) price = 170;
            else if (Num_Typefood == 5) price = 120;
            else if (Num_Typefood == 6) price = 80;
            else {
                cout << "Invalid item number. Try again.\n";
                continue;
            }
        }
        else if (Typefood == 3) {
            cout << "-- Drinks Menu --\n";
            cout << "1. Orange Juice - 25 EGP\n";
            cout << "2. Mango Juice - 30 EGP\n";
            cout << "3. Pepsi - 15 EGP\n";
            cout << "4. 7Up - 15 EGP\n";
            cout << "Enter item number: ";
            cin >> Num_Typefood;
            cout << "Enter quantity: ";
            cin >> quantity;
            
            if (Num_Typefood == 1) price = 25;
            else if (Num_Typefood == 2) price = 30;
            else if (Num_Typefood == 3) price = 15;
            else if (Num_Typefood == 4) price = 15;
            else {
                cout << "Invalid item number. Try again.\n";
                continue;
            }
        }
        else {
            cout << "Invalid category. Try again.\n";
            continue;
        }
        total += price * quantity;
    }
    return total;
}


void services() {
    const int taxiPrice = 50 * 50; 
    const int carRentalPrice = 100 * 50;
    const int tourGuidePrice = 80 * 50;
    string hotelNames[] = {"Hilton", "Movenpick", "Marriott", "Four Seasons"};
    int hotelBasePrices[] = {150 * 50, 130 * 50, 140 * 50, 200 * 50};
    string roomTypes[] = {"Single", "Double", "Triple"};
    int roomExtraPrices[] = {0, 50 * 50, 100 * 50};

    cout << "Welcome! Please choose a hotel to book (or enter 0 to skip):\n";
    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << ". " << hotelNames[i] << " - " << hotelBasePrices[i] << " EGP per night\n";
    }
    cout << "0. Skip\n";

    int hotelChoice;
    cout << "Enter hotel number (0-4): ";
    cin >> hotelChoice;

    if (hotelChoice == 0) {
        cout << "No hotel booked.\n";
        return;
    }
    if (hotelChoice < 1 || hotelChoice > 4) {
        cout << "Invalid hotel choice. No hotel booked.\n";
        return;
    }

    string selectedHotel = hotelNames[hotelChoice - 1];
    int baseHotelPrice = hotelBasePrices[hotelChoice - 1];

    cout << "\nSelect room type:\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ". " << roomTypes[i] << " (+" << roomExtraPrices[i] << " EGP)\n";
    }

    int roomChoice;
    cout << "Enter room type number (1-3): ";
    cin >> roomChoice;

    if (roomChoice < 1 || roomChoice > 3) {
        cout << "Invalid room type. No hotel booked.\n";
        return;
    }

    string selectedRoomType = roomTypes[roomChoice - 1];
    int roomExtra = roomExtraPrices[roomChoice - 1];

    int numDays;
    cout << "\nEnter number of days to stay: ";
    cin >> numDays;

    if (numDays <= 0) {
        cout << "Invalid number of days. No hotel booked.\n";
        return;
    }

    string taxiChoice, carRentalChoice, tourGuideChoice;
    cout << "\nDo you want a taxi from the airport? (yes/no): ";
    cin >> taxiChoice;
    cout << "Would you like to rent a car during your stay? (yes/no): ";
    cin >> carRentalChoice;
    cout << "Would you like a city tour with a local guide? (yes/no): ";
    cin >> tourGuideChoice;

    int roomPricePerNight = baseHotelPrice + roomExtra;
    int hotelTotal = roomPricePerNight * numDays;
    servicesPrice += hotelTotal;

    bool withTaxi = (taxiChoice == "yes" || taxiChoice == "Yes");
    bool withCarRental = (carRentalChoice == "yes" || carRentalChoice == "Yes");
    bool withTourGuide = (tourGuideChoice == "yes" || tourGuideChoice == "Yes");

    if (withTaxi) servicesPrice += taxiPrice;
    if (withCarRental) servicesPrice += carRentalPrice;
    if (withTourGuide) servicesPrice += tourGuidePrice;

    cout << "\n===== Booking Summary =====\n";
    cout << "Hotel: " << selectedHotel << "\n";
    cout << "Room Type: " << selectedRoomType << "\n";
    cout << "Nights: " << numDays << "\n";
    cout << "Price per Night: " << roomPricePerNight << " EGP\n";
    cout << "Hotel Total: " << hotelTotal << " EGP\n";
    if (withTaxi) cout << "Taxi Price: " << taxiPrice << " EGP\n";
    if (withCarRental) cout << "Car Rental: " << carRentalPrice << " EGP\n";
    if (withTourGuide) cout << "City Tour: " << tourGuidePrice << " EGP\n";
    cout << "Total Services Price: " << servicesPrice << " EGP\n";
    cout << "===========================\n";
}

void seats(int seatType) {
    if (seatType == 1) seatPrice += 500; // Economy
    else if (seatType == 2) seatPrice += 1000; // Business
}


void tickets(int persons) {
    ticketsPrice = persons * 1500;
}


void PAYMENT() {
    int total = seatPrice + foodPrice + servicesPrice + baggagePrice + ticketsPrice;

    cout << "======= PAYMENT DETAILS =======" << endl;
    cout << "Tickets      : " << ticketsPrice << " EGP" << endl;
    cout << "Seats        : " << seatPrice << " EGP" << endl;
    cout << "Food         : " << foodPrice << " EGP" << endl;
    cout << "Services     : " << servicesPrice << " EGP" << endl;
    cout << "Baggage      : " << baggagePrice << " EGP" << endl;
    cout << "-------------------------------" << endl;
    cout << "TOTAL PRICE  : " << total << " EGP" << endl;
    cout << "===============================" << endl;
}

int main() {
    const int totalSeats = 6;
    bool seatArr[totalSeats] = {false}; 
    string origin, destination;
    int dyear, dmonth, dday, dhour, dminute;
    int ayear, amonth, aday, ahour, aminute;

  
    cout << "Where are you from: ";
    cin >> origin;
    cout << "Where are you going: ";
    cin >> destination;

    cout << "Enter Arrival year (YYYY): ";
    cin >> ayear;
    cout << "Enter Arrival month (MM): ";
    cin >> amonth;
    cout << "Enter Arrival day (DD): ";
    cin >> aday;
    cout << "Enter Arrival hour (HH): ";
    cin >> ahour;
    cout << "Enter Arrival minutes (MM): ";
    cin >> aminute;

    cout << "Choose Departure time:\n";
    cout << "(1) 2025-05-19 21:30\n";
    cout << "(2) 2030-06-07 10:45\n";
    cout << "(3) 2035-09-15 12:15\n";
    cout << "Enter your choice (1-3): ";
    int dtime;
    cin >> dtime;
    if (dtime == 1) {
        dyear = 2025; dmonth = 5; dday = 19; dhour = 21; dminute = 30;
    } else if (dtime == 2) {
        dyear = 2030; dmonth = 6; dday = 7; dhour = 10; dminute = 45;
    } else if (dtime == 3) {
        dyear = 2035; dmonth = 9; dday = 15; dhour = 12; dminute = 15;
    } else {
        cout << "Invalid departure time choice.\n";
        return 1;
    }

    int peopleCount;
    cout << "How many people: ";
    cin >> peopleCount;
    cin.ignore(); 
    tickets(peopleCount); 

  
    int seatNumbers[peopleCount];

    for (int i = 0; i < peopleCount; i++) {
        string name, mail;
        int phone;
        string bagSize;
        int bagWeight = 0, bagCost = 0;
        int seatNumber;

        cout << "\nEnter details for person " << i+1 << ":\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Phone: ";
        cin >> phone;
        cin.ignore();
        cout << "Email: ";
        getline(cin, mail);

       
        cout << "Choose seat type:\n";
        cout << "(1) Economy - 500 EGP\n";
        cout << "(2) Business - 1000 EGP\n";
        cout << "Enter your choice (1-2): ";
        int seatType;
        cin >> seatType;
        seats(seatType); 
    
        bool seatReserved = false;
        while (!seatReserved) {
            showSeats(seatArr, totalSeats);
            cout << "Choose a seat number (1-" << totalSeats << ") for person " << i+1 << ": ";
            cin >> seatNumber;
            seatReserved = reserveSeat(seatArr, totalSeats, seatNumber);
        }
        seatNumbers[i] = seatNumber;

        cout << "Choose baggage size:\n";
        cout << "(1) Small (10 KG) - 100 EGP\n";
        cout << "(2) Medium (20 KG) - 150 EGP\n";
        cout << "(3) Large (32 KG) - 300 EGP\n";
        cout << "Enter your choice (1-3): ";
        int bagChoice;
        cin >> bagChoice;
        cin.ignore();

        if (bagChoice == 1) {
            bagSize = "Small";
            bagWeight = 10;
            bagCost = 100;
        } else if (bagChoice == 2) {
            bagSize = "Medium";
            bagWeight = 20;
            bagCost = 150;
        } else if (bagChoice == 3) {
            bagSize = "Large";
            bagWeight = 32;
            bagCost = 300;
        } else {
            cout << "Invalid baggage choice. No baggage added.\n";
            bagSize = "None";
        }
        baggagePrice += bagCost;

        cout << "Would you like to order food for person " << i+1 << "? (y/n): ";
        char foodChoice;
        cin >> foodChoice;
        if (foodChoice == 'y' || foodChoice == 'Y') {
            foodPrice += orderFood();
        }

        printTicket(name, phone, mail, origin, destination,
                    dyear, dmonth, dday, dhour, dminute,
                    ayear, amonth, aday, ahour, aminute,
                    bagSize, bagWeight, bagCost, seatNumber);
    }

    cout << "Would you like to book additional services (hotel, taxi, etc.)? (y/n): ";
    char serviceChoice;
    cin >> serviceChoice;
    if (serviceChoice == 'y' || serviceChoice == 'Y') {
        services();
    }

  
    PAYMENT();

    cout << "Thank you for using the flight booking system!\n";
    return 0;
}