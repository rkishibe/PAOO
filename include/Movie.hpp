#pragma once
#include <string>

class Movie {
private:
    std::string title;
    std::string genre;
    int duration; 

public:
//initializarea membrilor in constructor cu lista de initiliazare
    Movie(const std::string& title="", const std::string& genre="", int duration=0); 
    ~Movie();

    Movie& operator=(const Movie& other);

    // gettere - incapsulare
    std::string getTitle() const;
    std::string getGenre() const;
    int getDuration() const;
};
