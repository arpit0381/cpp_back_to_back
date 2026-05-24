#include "../include/Movie.h"
#include <iostream>

Movie::Movie() : id(""), title(""), genre(""), durationMinutes(0),
                 imdbRating(0.0), language(""), releaseDate(""), director("") {}

Movie::Movie(const std::string& id, const std::string& title, const std::string& genre,
             int duration, double rating, const std::string& language,
             const std::string& releaseDate, const std::string& director)
    : id(id), title(title), genre(genre), durationMinutes(duration),
      imdbRating(rating), language(language), releaseDate(releaseDate), director(director) {}

void Movie::setRating(double rating) {
    if (rating >= 0.0 && rating <= 10.0) {
        imdbRating = rating;
    }
}

void Movie::setLanguage(const std::string& lang) {
    language = lang;
}

void Movie::displayInfo() const {
    std::cout << "\n=== MOVIE INFORMATION ===" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Director: " << director << std::endl;
    std::cout << "Duration: " << durationMinutes << " minutes" << std::endl;
    std::cout << "Language: " << language << std::endl;
    std::cout << "Release Date: " << releaseDate << std::endl;
    std::cout << "IMDB Rating: " << imdbRating << "/10" << std::endl;
    std::cout << "========================\n" << std::endl;
}
