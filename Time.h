#ifndef Time_H
#define Time_H

#include <iostream>
using namespace std;
#include "Song.h"

class Time {

	public:

		//int secs;
		int d;                                  //day
		//long cur_virtualtime;                   //time when its added to library
		int gettime();
		void settime(int z); 
		Time();
		Time (int time);

};

#endif
