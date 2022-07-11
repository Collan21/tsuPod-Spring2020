/****************************************************
Name: Collan Parker
Date: 23 April 2020
Problem Number: 6
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

#include "Song.h"

using namespace std;

/*
function: Song::setTitle, this void function sets the variable "title" in an
                          instance of a specific song object to the data in the
                          pointer passed into the function.

parameters: char *t, stores the address of character/ string data

returns: nothing
*/

void Song::setTitle( char *t )
{
    title = t;
}

/*
function: Song::getTitle, this int function returns the variable "title" in an
                          instance of a song object.

parameters: none

returns: string title, stores the title of a song object
*/

string Song::getTitle( )
{
    return title;
}

/*
function: Song::setArtist, this void function sets the variable "artist" in an
                           instance of a specific song object to the data in the
                           pointer passed into the function.

parameters: char *a, stores the address of character/ string data

returns: nothing
*/

void Song::setArtist( char *a )
{
    artist = a;
}

/*
function: Song::getArtist, this int function returns the variable "artist" in an
                           instance of a song object.

parameters: none

returns: string artist, stores the artist of a song object
*/

string Song::getArtist( )
{
    return artist;
}

/*
function: Song::setSize, this void function sets the variable "size" in an
                         instance of a specific song object to the data passed
                         into the function.

parameters: int s, stores a whats soon to be a size of a song object

returns: nothing
*/

void Song::setSize( int s )
{
    size = s;
}

/*
function: Song::getSize, this int function returns the variable "size" in an
                         instance of a specific song object.

parameters: none

returns: int size, stores the size of a song object
*/

int Song::getSize( )
{
    return size;
}
