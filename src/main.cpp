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

    imaxCinema.scheduleMovie(movie1);

    cinema.scheduleMovie(movie1);
    cinema.scheduleMovie(movie2);
    cinema.scheduleMovie(std::make_shared<Movie>("Avatar", "Sci-Fi", 162));

    cinema.showMovies();

    printCinemaDetails(cinema); //copy constructor will be called because we send an obj as value

    Cinema movedCinema = std::move(cinema); //call move constructor
    std::cout << "\nMoved Cinema Movies:\n";
    movedCinema.showMovies();

    return 0;
}
