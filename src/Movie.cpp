#include "Movie.hpp"
#include <iostream>

Movie::Movie(const std::string& title="", const std::string& genre="", int duration=0) //constructor with list initialization
    : title(title), genre(genre), duration(duration) {
    std::cout << "Movie \"" << title << "\" created.\n\n";
}

Movie::~Movie() { //destructor
    std::cout << "Movie \"" << title << "\" destroyed.\n\n";
}

//assignment operator
Movie& Movie::operator=(const Movie& other){
    if(this==&other){
        return *this; //checking for self assignment
    }

    title=other.title;
    genre=other.genre;
    duration=other.duration;

    std::cout<<"Movie \"" <<title << "\" assigned from "<< other.title << "\" .\n\n";

    return *this;
}

std::string Movie::getTitle() const { //getters to apply the encapsulation principle
    return title; 
}

std::string Movie::getGenre() const { 
    return genre;
}
int Movie::getDuration() const { 
    return duration; 
}
