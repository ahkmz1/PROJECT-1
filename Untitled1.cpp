#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    cout << "===================================================\n";
    cout << "            GRAB RIDE & FARE ESTIMATOR             \n";
    cout << "       LDCW6123 Digital Competence Project         \n";
    cout << "===================================================\n\n";

    int serviceChoice = 0;
    double distanceKm = 0.0;
    char peakHourInput = 'n';
    string promoCode = "";

    string serviceName = "";
    double baseFare = 0.0;
    double ratePerKm = 0.0;
    double subtotal = 0.0;
    double surgeMultiplier = 1.0;
    double discountAmount = 0.0;
    double finalFare = 0.0;

    cout << "Select Grab Service Type:\n";
    cout << "  1. GrabBike / Budget (Base: RM 2.00, RM 0.80/km)\n";
    cout << "  2. GrabCar Standard  (Base: RM 3.00, RM 1.20/km)\n";
    cout << "  3. GrabCar Premium/XL(Base: RM 6.00, RM 2.00/km)\n";
    cout << "  4. GrabExpress Parcel(Base: RM 4.00, RM 1.50/km)\n";
    cout << "Enter service option (1-4): ";
    cin >> serviceChoice;

    switch (serviceChoice) {
        case 1:
            serviceName = "GrabBike / Budget";
            baseFare = 2.00;
            ratePerKm = 0.80;
            break;
        case 2:
            serviceName = "GrabCar Standard";
            baseFare = 3.00;
            ratePerKm = 1.20;
            break;
        case 3:
            serviceName = "GrabCar Premium / XL";
            baseFare = 6.00;
            ratePerKm = 2.00;
            break;
        case 4:
            serviceName = "GrabExpress Delivery";
            baseFare = 4.00;
            ratePerKm = 1.50;
            break;
        default:
            cout << "\n[ERROR] Invalid service option selected. Program exiting.\n";
            return 1;
    }
}