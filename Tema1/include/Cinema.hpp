#pragma once
#include "Movie.hpp"
#include <string>
#include <vector>

class Cinema {
private:
    std::string name;
    int seatCapacity;
    std::vector<Movie*> scheduledMovies; // Vector de pointeri la filme programate

public:
    Cinema(const std::string& name, int seatCapacity);
    ~Cinema();

    Cinema& operator=(const Cinema& other);

    void scheduleMovie(Movie* movie);
    void showMovies() const;
};
