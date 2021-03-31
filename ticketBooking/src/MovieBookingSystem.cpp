//Remzi Tepe
//21802713
#include <iostream>
using namespace std;
#include "MovieBookingSystem.h"
#include <cmath>
MovieBookingSystem::MovieBookingSystem()
{
    numOfmovies = 0;
    numOfRes = 0;
    this->movies = NULL;
    this->booked = NULL;
    this->allMovies = NULL;
    this->allBooked = NULL;
    deleted = 0;
}

MovieBookingSystem::~MovieBookingSystem()
{
    if( allMoviestemp != NULL)
        delete[] allMoviestemp;
    if( booked != NULL)
        delete[] booked;
    if( movies != NULL)
        delete[] movies;
    if( allMovies != NULL)
    delete[] allMovies;

    if( allBooked != NULL)
        delete[] allBooked;
    if( allBookedtemp != NULL)
        delete[] allBookedtemp;
}

void MovieBookingSystem::addMovie ( const long movieID, const int audienceRadius ){
    if( audienceRadius > 7 || audienceRadius < 0){
        cout << "The audience radius must be in between 0-7" << endl;
    }
    else{
        numOfmovies = numOfmovies + 1;
        time_t rawtime;
        movies = new movie(movieID, audienceRadius, numOfRow, numOfColumn, rawtime);
        allMoviestemp = new movie[numOfmovies];
        for( int i = 0; i < numOfmovies; i++){
            if( i < (numOfmovies - 1))
                allMoviestemp[i] = allMovies[i];
            else
                allMoviestemp[numOfmovies - 1] = *movies;
        }
        allMovies = NULL;
        allMovies = new movie[numOfmovies];
        for(int i = 0; i < numOfmovies; i++){
            allMovies[i] = allMoviestemp[i];
        }
        allMoviestemp = NULL;
        cout << "The Movie at ";
        time_t movie_time = (*movies).getID();
        char* tm = ctime(&movie_time);
        cout <<  tm;
        cout << " has been added" << endl;
    }
}
void MovieBookingSystem::cancelMovie(const long movieID){
        for( int i = 0; i < numOfmovies; i++){
            if( allMovies[i].getID() == movieID){
                allMoviestemp = new movie[numOfmovies - 1];
                for( int j = 0; j < i; j++){
                    allMoviestemp[j] = allMovies[j];
                }
                for( int j = i + 1; j < numOfmovies-1; j++){
                    allMoviestemp[j-1] = allMovies[j];
                }
                allMovies = NULL;
                allMovies = new movie[numOfmovies-1];
                for(int j = 0; j < numOfmovies - 1; j++){
                    allMovies[j] = allMoviestemp[j];
                }
                allMoviestemp = NULL;
                deleted = deleted + 1;
                numOfmovies = numOfmovies - 1;
                cout << "The Movie at ";
                time_t movie_time = movieID;
                char* tm = ctime(&movie_time);
                cout <<  tm;
                cout << " has been deleted" << endl;
            }

        }
        if( deleted == 0){
            cout << "There is no movie with that ID " << endl;
        }
        else
            deleted = 0;
    }
void MovieBookingSystem::showAllMovies(){
    if( numOfmovies == 0)
        cout << "No movie on show" << endl;
    else{
    for( int i = 0; i < numOfmovies; i++){
        time_t movie_time = allMovies[i].getID();
        char* tm = ctime(&movie_time);
        cout << "Movie at ";
        cout << tm;
        cout << " (" << allMovies[i].allSeats() << " avaliable seats)" << endl;

    }
    }
}
void MovieBookingSystem::showMovie(const long movieID){
    for( int i = 0; i < numOfmovies; i++){
        if( deleted < 1){
        if( allMovies[i].getID() == movieID){
            deleted++;
            cout << "   ";
            for( int j = 1; j <= numOfColumn ; j++){
                if( (j - 1) % (allMovies[i].getRadius() + 1) == 0){
                    char c = (char)(j+64);
                    cout << c;
                    cout << " ";
                }
            }
            cout << endl;
            for( int j = 1; j < numOfRow; j++){
                if( (j - 1) % (allMovies[i].getRadius() + 1) == 0){
                    cout << j;
                    if( j > 9){
                        cout << "";
                    }
                    else
                        cout << " ";
                    for( int k = 1; k <= numOfColumn; k++){
                        if( (k - 1) % (allMovies[i].getRadius() + 1) == 0){
                            int xRow = (j-1) / (allMovies[i].getRadius()+1);
                            int xColumn = (k-1)/ (allMovies[i].getRadius() + 1);
                            if( allMovies[i].getArray()[xRow][xColumn] == 0){
                                cout << " x";
                            }
                            else
                                cout << " o";
                        }
                    }
                    cout << endl;
                }
            }
        }
    }
    }
    deleted = 0;
}
int MovieBookingSystem::makeReservation ( const long movieID, const int row, const char col){
    if( row > numOfRow || row < 1 || col < 'A' || col > 'Z')
        cout << "Please make the reservation on the given seats" << endl;
    else{
    for( int i = 0; i < numOfmovies; i++){
        if( allMovies[i].getID() == movieID){
          if( allMovies[i].makeReserve( row, col) == allMovies[i].getID()/10000 + (row+(int(col-64)))){
            numOfRes = numOfRes + 1;
            cout << "You made a reservation for the seat:";
            cout << col;
            cout << row;
            cout << " in the movie at ";
            time_t movie_time = allMovies[i].getID();
            char* tm = ctime(&movie_time);
            cout <<  tm <<endl;
            booked = new booking(allMovies[i].getID(), row, col, allMovies[i].getID()/10000 + (row+(int(col-64))));
            allBookedtemp = new booking[numOfRes];
            for( int j = 0; j < numOfRes; j++){
            if( j < (numOfRes - 1))
                allBookedtemp[j] = allBooked[j];
            else
                allBookedtemp[numOfRes- 1] = *booked;
            }
            allBooked = NULL;
            allBooked = new booking[numOfRes];
            for(int j = 0; j < numOfRes; j++){
                allBooked[j] = allBookedtemp[j];
            }
            allBookedtemp = NULL;
            return allMovies[i].getID()/10000 + (row+(int(col-64)));
          }
          else if(allMovies[i].makeReserve( row, col) == 2){
             cout << "The seat ";
            cout << col;
            cout << row;
            cout << " is not occupiable" << endl;
            return 2;
          }
          else{
            cout << "Seat ";
            cout << col;
            cout << row;
            cout << "is not available" << endl;
            return 1;
          }

           }

        }
    }
}
void MovieBookingSystem::cancelReservations( const int numRes, const int* resCode){
    for( int i = 0; i < numOfRes; i++){
        if( resCode[ numRes - 1] == allBooked[i].getResCode()){
            deleted = deleted + 1;
            for( int j = 0; j < numOfmovies; j++){
                if( allMovies[j].getID() == allBooked[i].getMovieID()){
                    numOfRes = numOfRes - 1;
                    allMovies[j].cancelSeat( allBooked[i].getRow(), allBooked[i].getCol());
                    cout << "Reservation on Code";
                    cout << i;
                    cout << " is canceled: ";
                    allBookedtemp = new booking[numOfRes];
                    for( int k = 0; k < i; k++){
                    allBookedtemp[k] = allBooked[k];
                }
                for( int k = i + 1; k < numOfRes; k++){
                    allBookedtemp[k-1] = allBooked[k];
                }
                allBooked = NULL;
                allBooked = new booking[numOfRes];
                for(int k = 0; k < numOfRes; k++){
                    allBooked[k] = allBookedtemp[k];
                }
                    allBookedtemp = NULL;
                    time_t movie_time = allMovies[j].getID();
                    char* tm = ctime(&movie_time);
                    cout <<  tm << endl;
            }
        }

    }
    }
    if( deleted == 0){
        cout << "Reservation is failed please select a valid resCode" << endl;
    }
    else
        deleted = 0;


}
void MovieBookingSystem::showReservation( const int resCode){
    for( int i = 0; i < numOfRes; i++){
        if( allBooked[i].getResCode() == resCode){
            cout << "Reservation with Code ";
            cout << numOfRes;
            cout << " Seat ";
            cout << allBooked[i].getCol();
            cout << allBooked[i].getRow();
            cout << " in movie at ";
            time_t movie_time = allBooked[i].getMovieID();
            char* tm = ctime(&movie_time);
            cout <<  tm << endl;

        }
    }
}





