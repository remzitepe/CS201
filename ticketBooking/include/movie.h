//Remzi Tepe
//21802713
#ifndef MOVIE_H
#define MOVIE_H
#include <ctime>
class movie
{
    public:
        movie();
        movie(const long movieID, const int audienceRadius, const int numOfRow, const int numOfColumn, const time_t rawtime);
        ~movie();
        int allSeats();
        int avaliableSeatNum();
        int getSeat(int row, char col);
        int makeReserve( int row, char col);
        int** getArray();
        int getRadius();
        void initArray();
        void decrementSeat();
        long getID();
        time_t getTime();
        void cancelSeat( int row, char col);



    private:
        long movieID;
        int allSeatNum;
        int avaliableSeats;
        int audienceRadius;
        int numOfRow;
        time_t rawtime;
        int **movieArr;
        int** movieArrtemp;
        int numOfColumn;
        int columnNum;
        int rowNum;
        int realRow;
        int realColumn;
};

#endif // MOVIE_H
