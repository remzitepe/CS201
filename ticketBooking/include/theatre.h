#ifndef THEATRE_H
#define THEATRE_H


class theatre
{
    public:
        theatre();
        theatre( const theatre& obj);
        ~theatre();
        int isReserved( const int column, const int row);
        void init( const long movieID, const int numColumn, const int *numRow);
        void reservations( bool **p);

        int numOfmovies;
        long movieID;
        int columns;
        int *rows;
        bool **reserved;


    private:
};

#endif // THEATRE_H
