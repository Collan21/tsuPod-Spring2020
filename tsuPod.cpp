/****************************************************
Name: Collan Parker
Date: 23 April 2020
Problem Number: 6
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
#include <ctime>   // necessary for shuffle function

#include "tsuPod.h"

using namespace std;

int total_size = 0,
    song_count = 0;

tsuPod tpod ( 256 );

/*
function: tsuPod::addSong, this int function adds the size from the song object
                           to the total memory counter. If the maximum memory
                           has not been reached, then two pointers is created.
                           One pointer stores the current position, and the
                           other pointer holds the next node. Then the data for
                           the song is added to the linked list and the song
                           count is increased by 1. If the linked list is empty,
                           then the head pointer is set to NULL. If the list is
                           not open, then the next position in the list is
                           checked to see if it is empty, if the next space is
                           available, then the pointer points to the next set
                           of data. If the maximum memory is reached then the
                           passed song wont be added.

parameters: Song s, the s instance of the Song class holds a title, artist, and
            size of the song in megabytes.

returns: 0, if the new song is added successfully
         1, if the new song cannot be added due to lack of available memory
*/

int tsuPod::addSong( Song s )
{
    total_size += s.getSize();

    if ( total_size <= tpod.max_size )
    {
        song_count++;

        SongNode *newNode;
        SongNode *nodePtr;

        newNode = new SongNode;
        newNode->title = s.getTitle();
        newNode->artist = s.getArtist();
        newNode->size = s.getSize();

        newNode->nextSong = NULL;

        if ( !headNode )
            headNode = newNode;

        else
        {
            nodePtr = headNode;
            while ( nodePtr->nextSong )
                nodePtr = nodePtr->nextSong;

            nodePtr->nextSong = newNode;
        }

        return 0;
    }

    else
    {
        total_size -= s.getSize();

        return 1;
    }
}

/*
function: tsuPod::removeSong, this int function creates a boolean variable that
                              stores whether or not the song is found, found is
                              initialized to false. If the title, artist, and
                              size of the song thats been passed to be deleted
                              is the same as the data in the first node, the
                              first node has to be reassigned to the next node
                              in the list. If the song's memory location is
                              removed then, its memory also needs to be
                              subtracted from the total memory, and the song
                              count subtracts one from its total. IF the data is
                              not found in the first node, then the rest of the
                              nodes will be searched similarly to the first. If
                              the data is found the, node's data will be deleted
                              and the previous pointer will skip that node.

parameters: Song s, the s instance of the Song class holds a title, artist, and
            size of the song in megabytes.


returns: 0, if the song is removed successfully
         1, if the song cannot be found
*/

int tsuPod::removeSong( Song s )
{
    bool found = false; //if Song s is found in linked list

    SongNode *nodePtr; //stores current node
    SongNode *previousNode;

    if ( !headNode )
        return 2; // if linked list is empty return 2

    if ( headNode->title == s.getTitle( ) && headNode->artist == s.getArtist( )
         && headNode->size == s.getSize( ) ) // if data in Song Object is
                                             // the same as the data in the
                                             // first node
    {
        total_size -= headNode->size;
        song_count--;
        found = true;

        nodePtr = headNode->nextSong;
        delete headNode;
        headNode = nodePtr;
    }

    else // data not found in first node
    {
        nodePtr = headNode;

        while ( nodePtr != NULL && ( nodePtr->title != s.getTitle( ) ) &&
                                   ( nodePtr->artist != s.getArtist( ) ) &&
                                   ( nodePtr->size != s.getSize( ) ) )
                                   //traverses list until the end or data found
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->nextSong;
        }

        if ( nodePtr ) // data found in any node but the first
        {
            total_size -= nodePtr->size;
            song_count--;
            found = true;

            previousNode->nextSong = nodePtr->nextSong;
            delete nodePtr;
        }
    }

    if( found )
        return 0;

    else
        return 1;
}

/*
function: tsuPod::showSongList, this void function creates a pointer to access
                                the data in the linked list, then if the linked
                                list is not empty, this function prints the
                                Title, Artist,and size of each song to the
                                console.

parameters: tsuPod song_storage[], is an array that stores instances of tsuPod
                                   classes

returns: nothing
*/

void tsuPod::showSongList( )
{
    SongNode *nodePtr;

    if ( !headNode )
        cout << "EMPTY LIST, unable to display" << endl;

    else
    {
        nodePtr = headNode;

        while ( nodePtr )
        {
            cout << "Title: " << nodePtr->title << " by " << nodePtr->artist
                 << ", " << nodePtr->size << " MB" << endl;

            nodePtr = nodePtr->nextSong;
        }
    }

    cout << endl;
}
/*
function: tsuPod::sortSongList, this void function counts the number of times
                                a swap of two tsuPods in the list occurs, if
                                at least one swap occurs then another iteration
                                of the sorting algorithm will loop. This
                                function also initializes a boolean variable
                                that determines if a swap needs to occur. If two
                                titles are equivalent then the artist and size
                                are organized. Then two pointers are created one
                                to access the current node in the list and one
                                to hold the next node. For each item in the
                                tsuPod array will be initially set to not be
                                swapped. Once the number of letters to campare
                                between two words is determined, by counting the
                                length of the shorter of the two words. Then a
                                comparison based on the ASCII values of each
                                letter in the two words is completed, to
                                determine alphabetical order. If they are out of
                                order, then these two tsuPods will set the swap
                                variable to true. If swap has been set to true
                                then the number of swaps will increase by one,
                                and the two tsuPod instances will be swapped.

parameters: nothing

returns: nothing
*/

void tsuPod::sortSongList( )
{
    int char_to_comp,
        num_swaps;

    bool swapped;


    SongNode *nodePtr,
             *nextNode;

    do
    {
        nodePtr = headNode,
        nextNode = headNode->nextSong;

        for ( nodePtr = headNode; nodePtr != NULL; nodePtr = nodePtr->nextSong )
        {
            for ( nextNode = nodePtr->nextSong; nextNode != NULL;
                nextNode = nextNode->nextSong )
            {
                num_swaps = 0;
                swapped = false;
                char_to_comp = 0;

                if ( nodePtr->title != nextNode->title )
                {
                    if ( nodePtr->title.length( ) > nextNode->title.length( ) )
                        char_to_comp = nodePtr->title.length( );

                    else
                        char_to_comp = nextNode->title.length( );

                    for ( int i = 0; i < char_to_comp; i++ )
                    {
                        if( nodePtr->title[i] == nextNode->title[i] );

                        else if( nodePtr->title[i] < nextNode->title[i] )
                            i = char_to_comp;

                        else
                            swapped = true;
                    }
                }

                else if ( nodePtr->artist != nextNode->artist )
                {
                    if ( nodePtr->artist.length( ) > nextNode->artist.length( ) )
                        char_to_comp = nodePtr->artist.length( );

                    else
                        char_to_comp = nextNode->artist.length( );

                    for ( int i = 0; i < char_to_comp; i++ )
                    {
                        if( nodePtr->artist[i] == nextNode->artist[i] );

                        else if( nodePtr->artist[i] < nextNode->artist[i] )
                            i = char_to_comp;

                        else
                            swapped = true;
                    }
                }

                else
                {
                    if( nodePtr->size > nextNode->size )
                    {
                        swapped = true;
                    }
                }

                if ( swapped )
                    {
                        num_swaps++;

                        swap( nodePtr->title, nextNode->title );
                        swap( nodePtr->artist, nextNode->artist );
                        swap( nodePtr->size, nextNode->size );
                    }

            }
        }
    } while ( num_swaps );
}

/*
function: tsuPod::shuffle, this void function clears declares and initializes
                           a random value, as well as as max shuffle count.
                           A pointer to access the information is created. Then
                           for a random amount of iterations, each pair will be
                           randomly swapped.

parameters: nothing

returns: nothing
*/


void tsuPod::shuffle( )
{
    int rand_val = 0;
    int const SHUF_COUNT = 10;

    SongNode *nodePtr;

    srand( time ( NULL ) );

    rand_val = ( rand ( ) % SHUF_COUNT );

    for ( int i = 0; i < rand_val ; i++ )
    {
        nodePtr = headNode;
        while ( nodePtr != NULL && nodePtr->nextSong != NULL )
        {
            bool flip = 0;
            flip = rand ( ) % 2;

            if ( flip )
            {
                swap ( nodePtr->title, nodePtr->nextSong->title );
                swap ( nodePtr->artist, nodePtr->nextSong->artist );
                swap ( nodePtr->size, nodePtr->nextSong->size );
            }

            nodePtr = nodePtr->nextSong;
        }
    }
}

/*
function: tsuPod::getTotalMemory, this int function returns the global
                                  variable total_size

parameters: nothing

returns: int total_size, stores the total memory for all of the songs
*/

int tsuPod::getTotalMemory( )
{
    return total_size;
}

/*
function: tsuPod::getRemainingMemory, this int function declares the difference
                                      between the default constructor's max
                                      size and the total memory of the linked
                                      list.

parameters: nothing

returns: the difference between the max memory and total_size, stores the total
                                                              memory for all of
                                                              the songs
*/

int tsuPod::getRemainingMemory( )
{
    return tpod.max_size - total_size;
}

/*
function: tsuPod::clearSongList, this void function clears the Title, Artist,
                                 size, and pointer for each node.

parameters: nothing

returns: nothing
*/

void tsuPod::clearSongList( )
{
    SongNode *nodePtr;
    SongNode *nextNode;

    nodePtr = headNode;

    while ( nodePtr != NULL )
    {
        nextNode = nodePtr->nextSong;

        delete nodePtr;

        nodePtr = nextNode;
    }

    headNode = NULL;
}
