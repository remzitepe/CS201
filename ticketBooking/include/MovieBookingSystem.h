//Remzi Tepe
//21802713
#ifndef __MOVIEBOOKINGSYSTEM_H
#define __MOVIEBOOKINGSYSTEM_H
#include <string>
#include "movie.h"
#include "booking.h"
using namespace std;

class MovieBookingSystem {
    public :
        const static int numOfRow = 30;
        const static int numOfColumn = 26;
        MovieBookingSystem();
        ~MovieBookingSystem();
        void addMovie ( const long movieID, const int audienceRadius );
        void cancelMovie ( const long movieID);
        void showAllMovies ();
        void showMovie ( const long movieID);
        int makeReservation ( const long movieID, const int row, const char col);
        void cancelReservations ( const int numRes, const int * resCode);
        void showReservation ( const int resCode);
        int numOfmovies;
        int numOfRes;
    private :
        int deleted;
        booking *booked;
        booking *allBooked;
        booking *allBookedtemp;
        movie   *movies;
        movie   *allMovies;
        movie* allMoviestemp;
};

#endif // MOVIEBOOKINGSYSTEM_H
