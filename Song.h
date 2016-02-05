#ifndef Song_H
#define Song_H

#include "Time.h"
#include <iostream>
using namespace std;

class Song {
	public: 
	        
		string title,artist;
		int dur;
		int priority;
		int likability;
                long lastplayed;
                int hashindex;
                int getpriority(int a,int b);
		Song(); 
		Song(string info1,string info2, int info3,int info4,int info5);               

};

#endif
