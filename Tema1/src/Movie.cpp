#include "Movie.hpp"
#include <iostream>

Movie::Movie(const std::string& title, const std::string& genre, int duration)
    : title(title), genre(genre), duration(duration) {
    std::cout << "Movie \"" << title << "\" created.\n";
}

Movie::~Movie() {
    std::cout << "Movie \"" << title << "\" destroyed.\n";
}

//assignment operator
Movie& Movie::operator=(const Movie& other){
    if(this==&other){
        return *this; //checking for self assignment
    }

    title=other.title;
    genre=other.genre;
    duration=other.duration;

    std::cout<<"Movie \"" <<title << "\" assigned from "<< other.title << "\" .\n";

    return *this;
}

std::string Movie::getTitle() const { return title; }
std::string Movie::getGenre() const { return genre; }
int Movie::getDuration() const { return duration; }
