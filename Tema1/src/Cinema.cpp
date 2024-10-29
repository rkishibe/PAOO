#include "Cinema.hpp"
#include <iostream>

Cinema::Cinema(const std::string& name, int seatCapacity)
    : name(name), seatCapacity(seatCapacity) {
    std::cout << "Cinema \"" << name << "\" opened with " << seatCapacity << " seats.\n";
}

Cinema::~Cinema() {
    for (Movie* movie : scheduledMovies) {
        delete movie; // Eliberăm memoria pentru fiecare film programat
    }
    std::cout << "Cinema \"" << name << "\" closed.\n";
}

//assignment operator
Cinema& Cinema::operator=(const Cinema& other){
    if(this == &other){
        return *this; //checking for self assignment
    }

    for (Movie * movie: scheduledMovies){
        delete movie;
    }

    scheduledMovies.clear();

    name=other.name;
    seatCapacity=other.seatCapacity;

    //deep copy
    for (Movie* movie: other.scheduledMovies){
        scheduledMovies.push_back(new Movie(*movie));
    }

    std::cout<<"Cinema \"" <<other.name << "\" assigned from "<< other.seatCapacity << "\" .\n";

    return *this;
}

void Cinema::scheduleMovie(Movie* movie) {
    scheduledMovies.push_back(movie);
    std::cout << "Movie \"" << movie->getTitle() << "\" scheduled at cinema \"" << name << "\".\n";
}

void Cinema::showMovies() const {
    std::cout << "Movies scheduled at " << name << ":\n";
    for (const Movie* movie : scheduledMovies) {
        std::cout << " - " << movie->getTitle() << " (" << movie->getGenre() << ", " << movie->getDuration() << " mins)\n";
    }
}
