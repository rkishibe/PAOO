#include "Cinema.hpp"
#include <iostream>

Cinema::Cinema(const std::string& name, int seatCapacity) //constructor with initialization list
    : name(name), seatCapacity(seatCapacity) {
    std::cout << "Cinema \"" << name << "\" opened with " << seatCapacity << " seats.\n\n";
}

Cinema::~Cinema() { //destructor
    for (Movie* movie : scheduledMovies) {
        delete movie; // free memory for each scheduled movie
    }
    std::cout << "Cinema \"" << name << "\" closed.\n\n";
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

    std::cout<<"Cinema \"" <<other.name << "\" assigned from "<< other.seatCapacity << "\" .\n\n";

    return *this;
}

void Cinema::scheduleMovie(Movie* movie) { //create movie list
    scheduledMovies.push_back(movie);
    std::cout << "Movie \"" << movie->getTitle() << "\" scheduled at cinema \"" << name << "\".\n\n";
}

void Cinema::showMovies() const { //display movie list
    std::cout << "Movies scheduled at " << name << ":\n";
    for (const Movie* movie : scheduledMovies) {
        std::cout << " - " << movie->getTitle() << " (" << movie->getGenre() << ", " << movie->getDuration() << " mins)\n";
    }
}
