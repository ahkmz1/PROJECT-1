#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
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

    cout << "\nEnter estimated trip distance (in km): ";
    cin >> distanceKm;

    if (distanceKm <= 0.0) {
        cout << "\n[ERROR] Distance must be greater than 0 km. Program exiting.\n";
        return 1;
    }

    cout << "Is this trip during peak hours? (y/n): ";
    cin >> peakHourInput;

    if (peakHourInput == 'y' || peakHourInput == 'Y') {
        surgeMultiplier = 1.35;
    } else if (peakHourInput == 'n' || peakHourInput == 'N') {
        surgeMultiplier = 1.00;
    } else {
        cout << "\n[NOTICE] Unrecognized peak hour response. Defaulting to standard rates.\n";
        surgeMultiplier = 1.00;
    }

    cout << "Enter Promo Code (type 'STUDENT', 'GRAB50', or 'NONE'): ";
    cin >> promoCode;

    if (promoCode == "GRAB50" || promoCode == "grab50") {
        discountAmount = 3.00;
    } else if (promoCode == "STUDENT" || promoCode == "student") {
        discountAmount = 2.00;
    } else {
        discountAmount = 0.00;
    }

    subtotal = baseFare + (distanceKm * ratePerKm);
    double fareAfterSurge = subtotal * surgeMultiplier;
    finalFare = fareAfterSurge - discountAmount;

    if (finalFare < 0.0) {
        finalFare = 0.0;
    }

    cout << "\n===================================================\n";
    cout << "                BOOKING RECEIPT                    \n";
    cout << "===================================================\n";
    cout << fixed << setprecision(2);
    cout << " Service Category  : " << serviceName << "\n";
    cout << " Trip Distance     : " << distanceKm << " km\n";
    cout << " Base Rate         : RM " << baseFare << "\n";
    cout << " Distance Charge   : RM " << (distanceKm * ratePerKm) << "\n";
    cout << " Subtotal          : RM " << subtotal << "\n";
    cout << " Peak Surge Factor : " << (surgeMultiplier > 1.0 ? "35% Surge Applied (1.35x)" : "Standard Rate (1.0x)") << "\n";
    if (discountAmount > 0.0) {
        cout << " Promo Discount    : -RM " << discountAmount << "\n";
    }
    cout << "---------------------------------------------------\n";
    cout << " TOTAL ESTIMATED FARE : RM " << finalFare << "\n";
    cout << "===================================================\n";
    cout << " Thank you for using Grab! Have a safe journey.\n\n";

    return 0;
}

