/****************************************************
Name: Collan Parker
Date: 23 April 2020
Problem Number: 6
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef tsuPod_h
#define tsuPod_h

#include <string>
#include <fstream>
#include "Song.h"

using namespace std;

class tsuPod
{
private:

    struct SongNode
    {
        string title;
        string artist;
        int size;

        SongNode *nextSong;
    };

    SongNode *headNode;

public:

    int max_size;

    tsuPod( int msize )
    {
        max_size = msize;
    }

    tsuPod( )
    {
        headNode = NULL;
    }

    int addSong( Song s );
    int removeSong( Song s );
    void showSongList( );
    void shuffle( );
    void sortSongList( );
    int getTotalMemory( );
    int getRemainingMemory( );
    void clearSongList( );
};
 #endif

