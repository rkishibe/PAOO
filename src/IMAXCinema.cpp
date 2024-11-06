#include "IMAXCinema.hpp"
#include <iostream>

IMAXCinema::IMAXCinema(const std::string& name, int seatCapacity, bool is3D)
    : Cinema(name, seatCapacity), is3D(is3D) {
    std::cout << "IMAX Cinema \"" << name << "\" opened with " << seatCapacity 
              << " seats and " << (is3D ? "3D support.\n\n" : "no 3D support.\n\n");
}

IMAXCinema::~IMAXCinema() {
    //     for (Movie* movie : scheduledMovies) {
    //     delete movie; // free memory for each scheduled movie
    // }
    std::cout << "IMAX Cinema \"" << name << "\" closed.\n\n";
}

void IMAXCinema::showIMAXFeatures() const {
    std::cout << "IMAX Cinema \"" << name << "\" has " << seatCapacity << " seats.\n";
    std::cout << "3D Support: " << (is3D ? "Yes" : "No") << "\n";
    showMovies(); 
}
