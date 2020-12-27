#include <iostream>

inline constexpr double milesInKm { 1.6 };

// TYPEDEF - Type Definition
typedef double distance_t;  // TIP: Use '_t' suffix to declare typedef names.
distance_t g_distance;      // Using typedef name 'distance_t' instead of double.

// TYPE ALIASES
using miles_t = distance_t; // NOTE: This is functionally equivalent to previous notation.
using kms_t = distance_t;

// TIP: Returning 'miles_t' makes it obvious that this function returns distance in miles;
// rather than, returning 'double'.
miles_t getMiles(kms_t distance) {
    return distance / milesInKm;
}

kms_t getKms(miles_t distance) {
    return distance * milesInKm;
}

int main() {
    std::cout << "Enter distance in Kilometers : ";
    std::cin >> g_distance;
    std::cout << "Distance in Miles : " << getMiles(g_distance);
    return 0;
}