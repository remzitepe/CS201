//Remzi Tepe
//21802713
#ifndef BOOKING_H
#define BOOKING_H


class booking
{
    public:
        booking();
        booking( const long movieID, const int row, const char col, const int resCode);
        ~booking();
        int getResCode();
        long getMovieID();
        int getRow();
        char getCol();


    private:
        long movieID;
        int row;
        char col;
        int resCode;
};

#endif // BOOKING_H
