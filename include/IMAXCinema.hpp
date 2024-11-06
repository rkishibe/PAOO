#pragma once
#include "Cinema.hpp"

class IMAXCinema : public Cinema {
private:
    bool is3D;

public:
    IMAXCinema(const std::string& name = "", int seatCapacity = 0, bool is3D = true);
    ~IMAXCinema();

    void showIMAXFeatures() const;
};

