/****************************************************
Name: Collan Parker
Date: 23 April 2020
Problem Number: 6
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <fstream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "tsuPod.h"
#include "Song.h"

using namespace std;

void testTsuPodDeletion ( tsuPod &Library ) {
    Library.clearSongList( );
    Library.showSongList( );
}

void testMemCalcs ( tsuPod Library ) {
    int return_value = Library.getTotalMemory( );
    cout << "Total Used Memory: " << return_value << endl;
    return_value = Library.getRemainingMemory( );
    cout << "Total Remaining Memory: " << return_value << endl << endl;
}

void testShuffle( tsuPod Library ) {
    Library.shuffle( );
    Library.showSongList( );
}

void testSort( tsuPod Library ) {
    Library.sortSongList( );
    Library.showSongList( );
}

void testSongRemoval( Song s, tsuPod &Library ) {
    int return_value = ( Library.removeSong( s ) );

    if( return_value == 0 )
        cout << "Successful song removal for: " << s.getTitle( ) << endl
             << endl;

    else if( return_value == 1 )
        cout << "Unsuccessful song removal for: " << s.getTitle( ) << endl
             << endl;

    else
        cout << "Other error, most likely list is empty.\n";

    cout << "Updated Song List:\n";
    Library.showSongList( );
}

void testDisplay( tsuPod Library ) {
    Library.showSongList( );
}

void testSongAddition( Song s, tsuPod &Library ) {
    int return_value = ( Library.addSong( s ) );

    if( return_value == 0 )
        cout << "Successful song addition for: " << s.getTitle( ) << endl
             << endl;

    else if( return_value == 1 )
        cout << "Unsuccessful song addition for: " << s.getTitle()
             << "\nMaximum memory exceeded.\n\n";

    else
        cout << "Other error\n";
}

int main( )
{
    int return_value;

    Song one( ( char* )"ABCs", ( char* )"Michael Jordan", 26 );
    Song two( ( char* )"Silent Night", ( char* )"Groot", 16 );
    Song three( ( char* )"ZYXs", ( char* )"Jordan Michael", 62 );
    Song four( ( char* )"ABCs", ( char* )"Bugs Bunny", 47 );
    Song five( ( char* )"Itsy Bitsy", ( char* )"Spider", 27 );
    Song six( ( char* )"Twinkle Twinkle", ( char* )"Lil Star", 36 );
    Song seven( ( char* )"ABCs", ( char* )"Lebron James", 18 );
    Song eight( (char*)"Monster Mash", ( char* )"Bobby Pickett", 19);
    Song nine( ( char* )"Fruit Salad", ( char* )"The Wiggles", 22 );

    tsuPod Library;

    cout << "Testing Successful Song Addition: \n";
    testSongAddition( one, Library );

    cout << "Testing Successful Song Addition: \n";
    testSongAddition( two, Library );

    Library.addSong( three );
    Library.addSong( four );
    Library.addSong( five );
    Library.addSong( six );
    Library.addSong( seven );
    Library.addSong( eight );

    cout << "Testing Unsuccessful Song Addition: \n";
    testSongAddition( nine, Library );

    cout << "Testing Successful Traversal and Display: \n";
    testDisplay( Library );

    cout << "Testing Successful Song Removal: \n";
    testSongRemoval( two, Library );

    cout << "Testing Unsuccessful Song Removal: \n";
    testSongRemoval( two, Library );

    cout << "Testing Successful Song Sort: \n";
    testSort( Library );

    cout << "Testing Successful Song Shuffle: \n";
    testShuffle( Library );

    cout << "Testing memory calculation:\n";
    testMemCalcs( Library );
    
    cout << "Testing Successful List Deletion: " << endl;
    testTsuPodDeletion( Library );

    return 0;
}
