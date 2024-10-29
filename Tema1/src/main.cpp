#include "Cinema.hpp"
#include "Movie.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Cinema cinema("Cinema City", 150);

    Movie* movie1 = new Movie("Inception", "Sci-Fi", 148);
    Movie* movie2 = new Movie("The Godfather", "Crime", 175);
    Movie* movie3= new Movie("The Holy Mountain", "Fantasy", 113);
    Movie *movie4=new Movie("Taste of Cherry", "Drama", 99);
    
    cinema.scheduleMovie(movie1);
    cinema.scheduleMovie(movie2);
    cinema.scheduleMovie(movie3);

    cinema.showMovies();

    return 0;
}
