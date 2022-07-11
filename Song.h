/****************************************************
Name: Collan Parker
Date: 23 April 2020
Problem Number: 6
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef Song_h
#define Song_h

#include <iostream>
#include <fstream>

using namespace std;

class Song
{
private:

    char *title,
         *artist;

    int size;

public:

    void setTitle( char *t );
    void setArtist( char *a );
    void setSize( int s );
    string getTitle( );
    string getArtist( );
    int getSize( );

    Song ( )
    {
        setTitle( (char*)"empty" );
        setArtist( (char*)"empty" );
        setSize( 0 );
    }

    Song ( char* t, char* a, int s )
    {
        setTitle( t );
        setArtist( a );
        setSize( s );
    }


};
#endif
