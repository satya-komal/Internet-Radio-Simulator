#ifndef Library_H
#define Library_H

#include <iostream>
using namespace std;
#include <string>
#include"Time.h" 
#include"Song.h" 
#include<algorithm>
class Library{
	private:


		//Time lastplayed;
	public: 
	        	        
		Song*content;
		Song*hashtable;
		//Song**heap;
		Time t_obj;
		Song s_obj;
		int size;
		int hashkey;
		int count;
		int asci;
		int arraysize;
		int cur_virtualtime;

		void setsize(int s);
		int getsize();
		void Array(int count);
		void heapinsert(int key,int n);
		void moveup(Song*A,int i);
		void movedown(int i,int a);
		void Build_maxheap(Song*A);
		void heapify(Song*A,int i);                  // Heap down
 		void PLAY(int N );
 		int getkey(string info);
 		void hashinsert(int a);

		int parent(int i);
		int left(int i);
		int right(int i);
		void swap(int a,int b);

		void INIT(int  a);
		void REST(int  x,int  y,int z);

		Library();
		Library(int i);
		~Library();
		void ADD(string info1,string info2, int info3,int info4 );
		void LIKE(string Title);
		void LIKE();
		void DISLIKE();
		void DISLIKE(string Title);
};

#endif
