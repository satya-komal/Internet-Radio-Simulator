# Internet-Radio-Simulator

The program reads from a text file which is shown below and performs the following actions:

INIT 23:59:59 100
ADD Song1, Artist1, 1:59
ADD Song 2, Artist 2, 2:00
PLAY 2
ADD Song Number 3, Artist 3, 3:03
PLAY 3
ADD Song Num 4, Art 4, 4:49
PLAY 1
PLAY 2
QUIT

1.Will initialise the current time to 23:59:59 and creates space to add upto 100 songs.
2.ADD command adds songs to the music library
3.PLAY command simulates the playing of songs(not the actual songs) by advancing a virtual clock.
4.PLAY followed by an integer a, plays the top a no of songs stored in the heap data structure.
5.QUIT command exits the program.

To compile and run the program:  Refer to the makefile
