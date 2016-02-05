#include <iostream>
#include "Song.h"
#include <sstream>
using namespace std;

Song::Song(){

	title="\0";
	artist="\0";
	dur=0;
	likability=0;
	lastplayed=0;     
	priority=0;
	hashindex=1;
}

Song::Song(string info1,string info2, int info3,int info4,int info5){

	title= info1;
	artist= info2;
	dur= info3;
        likability=0;
        lastplayed=info4;
        priority= info4;
        hashindex=info5;
}

int Song::getpriority(int a,int b){
	int c =a+ 1000*b;
	return priority;
}


