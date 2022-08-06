#include <iostream>

#include <conio.h>

using namespace std;

struct user {
    string name;
    long long mobileNumber;
    struct user * nextUser;
};

class Bus {
    public:
    int current_seat_no;
    int bus_no;
    string departure_time;
    string arrival_time;
    string bus_name;
    string startpoint, endpoint;
    user * front = NULL;
    user * rear = NULL;
    Bus() {
        current_seat_no = 0;
    }

};
Bus buses[10] = {};
int numberOfBuses = 0;

void Registration() {
    Bus temp;
    cout << "\n \t \t \t \t Enter bus number to be registered ";
    cin >> temp.bus_no;
    cout << "\n \t \t \t \t Enter Bus name ";
    cin >> temp.bus_name;
    cout << "\n \t \t \t \t Enter Bus Starting Point ";
    cin >> temp.startpoint;
    cout << "\n \t \t \t \t Enter Bus End Point ";
    cin >> temp.endpoint;
    cout << "\n \t \t \t \t Enter Departure Time ";
    cin >> temp.departure_time;
    cout << "\n \t \t \t \t Enter Arrival Time ";
    cin >> temp.arrival_time;
    buses[numberOfBuses++] = temp;

}
void CheckAvailableBuses() {
    cout << "\t \t \t \t LIST OF BUSES:- \n";
    cout << "------------------------------------------------------------------------------------------------------------\n\n";

    for (int i = 0; i < numberOfBuses; i++) {
        cout << "\t \t \t \t \t" << buses[i].bus_no << " BUS DETAILS ARE \n \n";

        cout << "\t \t \t \t BUS NUMBER       \t" << buses[i].bus_no;
        cout << "\n";
        cout << "\t \t \t \t BUS NAME          \t" << buses[i].bus_name;
        cout << "\n";
        cout << "\t \t \t \t BUS START POINT   \t" << buses[i].startpoint;
        cout << "\n";
        cout << "\t \t \t \t BUS END POINT    \t" << buses[i].endpoint;
        cout << "\n";
        cout << "\t \t \t \t BUS DEPARTURE TIME \t" << buses[i].departure_time;
        cout << "\n";
        cout << "\t \t \t \t BUS ARRIVAL TIME \t" << buses[i].arrival_time;
        cout << "\n";
        cout << "\n";

    }

}

void Reservation() {

    int bus_number;
    cout << "\n \t \t \t \t Enter bus number: ";
    cin >> bus_number;

    for (int i = 0; i < 10; i++) {
        if (buses[i].bus_no == bus_number) {
            struct user * temp = new user;
            cout << "\n \t \t \t \t Please enter your name: ";
            cin >> temp -> name;
            cout << "\n \t \t \t \t Please enter your mobile number to confirm the seat: ";
            cin >> temp -> mobileNumber;
            temp -> nextUser = NULL;
            if (buses[i].front == NULL) {

                buses[i].front = buses[i].rear = temp;
            } 
			
			else {
                buses[i].rear -> nextUser = temp;
                buses[i].rear = temp;

            }

            int counter = buses[i].current_seat_no + 1;
            buses[i].current_seat_no++;

            cout << "\n \t \t \t \t Congrats! Your seat number is: " << counter;
            cout << "\n";

        }
    }
    int i = 0;
    while (buses[i].bus_no != bus_number) {
        if (i == 10) {
            cout << "\n \t \t \t \t Enter Correct Bus Number";
            break;
        }
        i++;
    }

}
void viewPassengerList() {
    int bus_number;
    cout << "\n \t \t \t \t Enter bus number: ";
    cin >> bus_number;
    int i;
    for (i = 0; i < 10; i++) {
        if (buses[i].bus_no == bus_number) {
            user * temp;
            temp = buses[i].front;
            int counter = 1;
            cout<<"\n \t \t \t \t Passenger Lists are \n";
            while (temp != NULL) {
                cout << "\n \t \t \t \t Name: " << temp -> name;
                cout << "\n \t \t \t \t MobileNumber: " << temp -> mobileNumber;
                cout << "\n \t \t \t \t Seat Number: " << counter++;
                cout << "\n\n";
                temp = temp -> nextUser;
            }
            break;
        }
    }
    if (i >= 10) {
        cout << "\n \t \t \t \Enter correct bus number";
    }
}

int main() {
    cout << "\t \t WELCOME TO THE BUS RESERVATION MANAGEMENT SYSTEM \n";
    cout << "\n";

    Bus mumbaiToNashik;

    mumbaiToNashik.bus_no = 101;
    mumbaiToNashik.bus_name = "VRL Travels";
    mumbaiToNashik.startpoint = "Mumbai";
    mumbaiToNashik.endpoint = "Nashik";
    mumbaiToNashik.departure_time = "8:40 AM";
    mumbaiToNashik.arrival_time = "10:45 PM";

    buses[numberOfBuses++] = mumbaiToNashik;

    Bus lucknowToAgra;
    lucknowToAgra.bus_no = 102;
    lucknowToAgra.bus_name = "Sahara Travels";
    lucknowToAgra.startpoint = "Lucknow";
    lucknowToAgra.endpoint = "Agra";
    lucknowToAgra.departure_time = "9:40 AM";
    lucknowToAgra.arrival_time = "6:45 PM";
    buses[numberOfBuses++] = lucknowToAgra;
    int choice;
    while (1) {
        cout << "\n \t \t \t \t 1. Check Available Bus";
        cout << "\n \t \t \t \t 2. Reservation";
        cout << "\n \t \t \t \t 3. View Passenger List";
        cout << "\n \t \t \t \t 4. Register a new bus";
        cout << "\n \t \t \t \t 5. Quit \n \n";
        cout << " \t \t \t \t Enter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            CheckAvailableBuses();
            break;
        case 2:
            Reservation();
            break;
        case 3:
            viewPassengerList();
            break;
        case 4:
            Registration();
            break;
        case 5:
            exit(1);
        default:
            cout << "\n";
            cout << "\n \t \t \t \t Incorrect choice of input ";
        }
    }
}





