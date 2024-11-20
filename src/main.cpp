#include "Cinema.hpp"
#include "Movie.hpp"
#include "IMAXCinema.hpp"
#include <iostream>
#include <memory> // include for shared_ptr

int main(int argc, char *argv[]) {
    Cinema cinema("Cinema City", 150);

    auto movie1 = std::make_shared<Movie>("Inception", "Sci-Fi", 148);
    auto movie2 = std::make_shared<Movie>("The Godfather", "Crime", 175);
    auto movie3 = std::make_shared<Movie>("The Holy Mountain", "Fantasy", 113);
    auto movie4 = std::make_shared<Movie>("Taste of Cherry", "Drama", 99);

    IMAXCinema imaxCinema("IMAX", 300, true);
    IMAXCinema cinema2("Timis", 250); //both constructors are called
    Cinema *cinema3=new IMAXCinema("a", 100, true); //both constructors are called

    imaxCinema.scheduleMovie(movie1);

    cinema.scheduleMovie(movie1);
    cinema.scheduleMovie(movie2);
    cinema.scheduleMovie(std::make_shared<Movie>("Avatar", "Sci-Fi", 162));

    cinema.showMovies();

    printCinemaDetails(cinema); //copy constructor will be called because we send an obj as value

    Cinema movedCinema = std::move(cinema); //call move constructor
    std::cout << "\nMoved Cinema Movies:\n";
    movedCinema.showMovies();

    Cinema cinema4("Victoria", 5);

    // Book tickets
    cinema4.bookTicket();
    cinema4.bookTicket();

    // Display availability
    cinema4.displayAvailability();

    // Cancel a ticket
    cinema4.cancelTicket();

    // Display availability again
    cinema4.displayAvailability();

    // Attempt to book all tickets
    for (int i = 0; i < 6; ++i) {
        cinema4.bookTicket();
    }

    // Attempt to cancel beyond capacity
    cinema4.cancelTicket();
    cinema4.cancelTicket();

    return 0;
}
