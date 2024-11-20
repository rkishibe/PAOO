#include "Movie.hpp"
#include <iostream>

Movie::Movie(const std::string& titleStr, const std::string& genre, int duration)
    : title(std::make_unique<std::string>(titleStr)), genre(genre), duration(duration) {
    std::cout << "Movie \"" << *title << "\" created.\n";
}

Movie::~Movie() { //destructor
    std::cout << "Movie \"" << *title << "\" destroyed.\n";
}

Movie::Movie(Movie&& other) noexcept
    : title(std::move(other.title)), genre(std::move(other.genre)), duration(other.duration) {
    std::cout << "Movie \"" << *title << "\" moved.\n";
}

Movie& Movie::operator=(Movie&& other) noexcept {
    if (this != &other) {
        title = std::move(other.title);
        genre = std::move(other.genre);
        duration = other.duration;
        std::cout << "Movie \"" << *title << "\" move-assigned.\n";
    }
    return *this;
}

std::string Movie::getTitle() const { //getters to apply the encapsulation principle
    return *title; 
}

std::string Movie::getGenre() const { 
    return genre;
}
int Movie::getDuration() const { 
    return duration; 
}
