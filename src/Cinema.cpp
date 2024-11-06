#include "Cinema.hpp"
#include <iostream>

Cinema::Cinema(const std::string& name="", int seatCapacity=0) //constructor with initialization list
    : name(name), seatCapacity(seatCapacity) {
    std::cout << "Cinema \"" << name << "\" opened with " << seatCapacity << " seats.\n\n";
}

Cinema::~Cinema() { //destructor
    // for (Movie* movie : scheduledMovies) {
    //     delete movie; // free memory for each scheduled movie
    // }
    std::cout << "Cinema \"" << name << "\" closed.\n\n";
}

Cinema::Cinema(const Cinema& other) //copy constructor
    : name(other.name), seatCapacity(other.seatCapacity) {
    for (const auto& movie : other.scheduledMovies) {
        scheduledMovies.push_back(std::make_shared<Movie>(*movie));
    }
    std::cout << "Copy constructor called for Cinema \"" << name << "\".\n";
}


Cinema::Cinema(Cinema&& other) noexcept //move constructor
    : name(std::move(other.name)), 
      seatCapacity(other.seatCapacity), 
      scheduledMovies(std::move(other.scheduledMovies)) {
    std::cout << "Move constructor called for Cinema \"" << name << "\".\n";

    other.seatCapacity = 0;
}


//assignment operator
Cinema& Cinema::operator=(const Cinema& other){
    if(this == &other){
        return *this; //checking for self assignment
    }

    // for (const auto& movie : scheduledMovies) {
    //     delete movie;
    // }

    scheduledMovies.clear();

    name=other.name;
    seatCapacity=other.seatCapacity;

    //deep copy
    for (const auto& movie : scheduledMovies) {
        scheduledMovies.push_back(movie);
    }

    std::cout<<"Cinema \"" <<other.name << "\" assigned from "<< other.seatCapacity << "\" .\n\n";

    return *this;
}

void Cinema::scheduleMovie(std::shared_ptr<Movie> movie) { //create movie list
    scheduledMovies.push_back(movie);
    std::cout << "Movie \"" << movie->getTitle() << "\" scheduled at cinema \"" << name << "\".\n\n";
}

void Cinema::showMovies() const { //display movie list
    std::cout << "Movies scheduled at " << name << ":\n";
    for (const auto& movie : scheduledMovies) {
        std::cout << " - " << movie->getTitle() << " (" << movie->getGenre() 
                  << ", " << movie->getDuration() << " mins)\n";
    }
}


