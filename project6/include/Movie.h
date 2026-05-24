#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

class Movie {
private:
    std::string id;
    std::string title;
    std::string genre;
    int durationMinutes;
    double imdbRating;
    std::string language;
    std::string releaseDate;
    std::string director;

public:
    Movie();
    Movie(const std::string& id, const std::string& title, const std::string& genre,
          int duration, double rating, const std::string& language,
          const std::string& releaseDate, const std::string& director);

    // Getters
    std::string getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getGenre() const { return genre; }
    int getDurationMinutes() const { return durationMinutes; }
    double getImdbRating() const { return imdbRating; }
    std::string getLanguage() const { return language; }
    std::string getReleaseDate() const { return releaseDate; }
    std::string getDirector() const { return director; }

    // Setters
    void setRating(double rating);
    void setLanguage(const std::string& lang);

    // Display
    void displayInfo() const;
};

#endif
