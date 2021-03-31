//Remzi Tepe
//21802713
#include "movie.h"
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;
movie::movie()
{
    this->audienceRadius = 0;
     this->numOfRow = 0;
     this->numOfColumn = 0;
     this->rawtime = 0;
    this->movieArr = NULL;
    movieArrtemp = movieArr;
    this->realColumn = 0;
    this->realRow = 0;
}
movie::movie( const long movieID, const int audienceRadius, const int numOfRow, const int numOfColumn, const time_t rawtime){
    this->movieID = movieID;
    this->audienceRadius = audienceRadius;
    this->rawtime = rawtime;
    this->numOfRow = numOfRow;
    this->numOfColumn = numOfColumn;
    realRow = (int)(ceil( (double)numOfRow / (audienceRadius+1)));
    realColumn = (int)(ceil(( (double)numOfColumn / (audienceRadius+1))));
    avaliableSeats = realRow * realColumn;
     this->realColumn = realColumn;
     this->avaliableSeats = avaliableSeats;
    this->realRow = realRow;
    this->movieArr = new int*[realRow];
    for( int i = 0; i < realRow; i++){
        this->movieArr[i] = new int[realColumn];
    }
    movieArrtemp = movieArr;
    for( int i = 0; i < realRow; i++){
        for( int j = 0; j < realColumn; j++){
            movieArr[i][j] = 0;
        }
    }
}
movie::~movie()
{
   for (int i = 0; i < realRow; i++)
		if (movieArr[i] != NULL)
			delete[] movieArr[i];
	if(movieArr != NULL)
		delete[] movieArr;
     for (int i = 0; i < realRow; i++)
		if (movieArrtemp[i] != NULL)
			delete[] movieArrtemp[i];
	if(movieArrtemp != NULL)
		delete[] movieArrtemp;
}

int movie::allSeats(){
    return avaliableSeats;
}
void movie::decrementSeat(){
    avaliableSeats = avaliableSeats - 1;
}
int movie::avaliableSeatNum(){
    return avaliableSeats;
}
long movie::getID(){
    return this->movieID;
}
int movie::getRadius(){
    return audienceRadius;
}
int** movie::getArray(){
    return movieArrtemp;
}

int movie::makeReserve( int row, char col){
    int col_int = (int)col;
    columnNum = col_int - 64;
    if( (row - 1) % (audienceRadius + 1) != 0){
        return 2;
    }
    else if( (columnNum - 1) % (audienceRadius + 1) != 0){
        return 2;
    }
    else{
    rowNum = (row-1) / (audienceRadius+1);
    columnNum = (columnNum-1)/ (audienceRadius + 1);
    if( movieArr[rowNum][columnNum] == 1){
        return 1;
    }
    else{
        movieArr[rowNum][columnNum] = 1;
        return movieID/10000 + ( row +((int)col-64));
    }
    }
}
void movie::cancelSeat( int row, char col){
    rowNum = (row-1) / (audienceRadius+1);
    int col_int = (int)col;
    columnNum = col_int - 64;
    columnNum = (columnNum-1)/ (audienceRadius + 1);
    movieArr[rowNum][columnNum] = 0;
}
