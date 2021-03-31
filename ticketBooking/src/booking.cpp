//Remzi Tepe
//21802713
#include "booking.h"

booking::booking(){
    this->movieID = 0;
    this->row = 0;
}
booking::booking(const long movieID, const int row, const char col, const int resCode)
{
    this->movieID = movieID;
    this->row = row;
    this->col = col;
    this->resCode = resCode;
}

booking::~booking()
{
}
int booking::getResCode(){
    return resCode;
}
long booking::getMovieID(){
    return movieID;
}
int booking::getRow(){
    return row;
}
char booking::getCol(){
    return col;
}
