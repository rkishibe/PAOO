#include "Cinema.hpp"
#include <iostream>

Cinema::Cinema(const std::string& name, int seatCapacity) //constructor with initialization list
    : name(name), seatCapacity(seatCapacity) {
    std::cout << "Cinema \"" << name << "\" opened with " << seatCapacity << " seats.\n\n";
}

Cinema::~Cinema() { //destructor
    // for (Movie* movie : scheduledMovies) {
    //     delete movie; // free memory for each scheduled movie
    // }
    std::cout << "Cinema \"" << name << "\" closed.\n\n";
}

Cinema::Cinema(const Cinema& other)
    : name(other.name), seatCapacity(other.seatCapacity), scheduledMovies(other.scheduledMovies) {
    std::cout << "Copy constructor called for Cinema \"" << name << "\".\n";
}


void printCinemaDetails(Cinema cinema) { //va fi apelat copy constructorul pentru ca transmitem un obiect ca valoare
    std::cout << "Details of cinema \"" << cinema.getName() << "\" with seat capacity: " << cinema.getSeatCapacity() << "\n";
    cinema.showMovies();
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
    std::cout << "Movie \"" << movie->getTitle() << "\" scheduled at cinema \"" << name << "\".\n";
}

void Cinema::showMovies() const { //display movie list
    std::cout << "Movies scheduled at " << name << ":\n";
    for (const auto& movie : scheduledMovies) {
        std::cout << " - " << movie->getTitle() << " (" << movie->getGenre() 
                  << ", " << movie->getDuration() << " mins)\n";
    }
    std::cout<<"\n";
}

//we use a mutex in these 2 methods to lock the seat capacity so no other operations can
//interfere with the booking causing a booking with no seats available
bool Cinema::bookTicket() {
    std::lock_guard<std::mutex> lock(bookingMutex);
    if (seatCapacity > 0) {
        --seatCapacity;
        std::cout << "Ticket booked! Remaining seats: " << seatCapacity << "\n";
        return true;
    } else {
        std::cout << "Booking failed! No seats available.\n";
        return false;
    }
}


bool Cinema::cancelTicket() {
    std::lock_guard<std::mutex> lock(bookingMutex);
    if (seatCapacity < seatCapacity) {
        ++seatCapacity;
        std::cout << "Ticket canceled! Available seats: " << seatCapacity << "\n";
        return true;
    } else {
        std::cout << "Cancellation failed! All seats are already available.\n";
        return false;
    }
}


void Cinema::displayAvailability() const {
    std::lock_guard<std::mutex> lock(bookingMutex);
    std::cout << "Seats available in \"" << name << "\": " << seatCapacity << "\n";
}


