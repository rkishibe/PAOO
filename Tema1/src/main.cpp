#include "Cinema.hpp"
#include "Movie.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Cinema cinema("Cinema City", 150);

    Movie* movie1 = new Movie("Inception", "Sci-Fi", 148);
    Movie* movie2 = new Movie("The Godfather", "Crime", 175);
    
    cinema.scheduleMovie(movie1);
    cinema.scheduleMovie(movie2);

    cinema.showMovies();

    // Destructorul va fi apelat automat la ieșirea din funcție și va elibera memoria
    return 0;
}
