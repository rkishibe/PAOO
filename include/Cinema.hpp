#pragma once
#include "Movie.hpp"
#include <string>
#include <vector>
#include<memory>

class Cinema {
protected:
    std::string name;
    int seatCapacity;
    std::vector<std::shared_ptr<Movie>> scheduledMovies; // Vector de pointeri la filme programate

public:
    Cinema(const std::string& name="", int seatCapacity=0);
    Cinema(const Cinema& other);
    Cinema(Cinema&& other) noexcept; 
    ~Cinema();

    // Cinema(const Cinema&) = delete;
    // Cinema& operator=(const Cinema&) = delete;

    Cinema& operator=(const Cinema& other);

    void scheduleMovie(std::shared_ptr<Movie>);
    void showMovies() const;

    std::string getName() const { return name; }
    int getSeatCapacity() const { return seatCapacity; }
};

void printCinemaDetails(Cinema cinema);