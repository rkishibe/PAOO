#pragma once
#include <string>
#include <memory>
#include <iostream>

class Movie {
private:
    std::unique_ptr<std::string> title;
    int duration;
    std::string genre;

public:
    Movie(const std::string& title = "", const std::string& genre = "", int duration = 0);
    ~Movie();

    //delete copy constructor and copy assignment operator
    Movie(const Movie&) = delete;
    Movie& operator=(const Movie&) = delete;

    Movie(Movie&& other) noexcept;
    Movie& operator=(Movie&& other) noexcept;

    std::string getTitle() const;
    std::string getGenre() const;
    int getDuration() const;

    void printDetails() const;
};
