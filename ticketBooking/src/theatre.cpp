#include "theatre.h"

theatre::theatre()
{
    movieID = 0;
    numOfmovies = 0;
}
theatre::theatre( const theatre& obj)
{
    movieID = obj.movieID;
    columns = obj.columns;
    rows = new int[columns];
    for( int i = 0; i < columns; ++i){
        rows[i] = obj.rows[i];
    }
    reserved = new bool*[columns];
    for( int i = 0; i < columns; ++i){
        reserved[i] = new bool[rows[i]];
        for( int j = 0; j < rows[i]; ++j){
            reserved[i][j] = obj.reserved[i][j];
        }
    }
}

theatre::~theatre()
{
    //dtor
}
