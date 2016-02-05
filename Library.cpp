#include <iostream>
#include "Library.h"
using namespace std;
#include<sstream>

Library::Library(){

	arraysize=0;
	count=1;
	size=0;
	//start_time=0;
	cur_virtualtime= 0;
	hashkey=0;
	asci=0;
	//cout<<"Default Library Constructor"<<endl;
}

Library::Library(int i){
	arraysize=0;
	count=1;
	size=0;
	asci=0;
	//start_time=0;
	cur_virtualtime= i;
	hashkey=0;
}

void Library::setsize(int s){
	arraysize=s;
}

int Library::getsize(){
	return arraysize;
}

int Library::parent(int i){
	return i/2;
}

int Library::left(int i){
	return 2*i;
}

int Library::right(int i){
	return 2*i+1;
}

void Library::Array(int arraysize ){  

	content = new Song[arraysize];
	hashtable= new Song[arraysize];
	for(int i=1;i<=arraysize;i++){
		hashtable[i].hashindex=0;

	}
}

void Library::ADD(string info1,string info2, int info3,int info4){

	info4=cur_virtualtime;
	content[count]= Song(info1,info2,info3,info4,count);

	// get hash key and store hash index of corresponding song at the hash keyth position
	int i=getkey(info1);
	hashinsert(i);

	//content[count]= &content[count];
	//content_increasekey(count,content[count]->priority);
	//Max_contentinsert(content[count]->priority,count);

	Build_maxheap(content);
	count+=1;
}

void Library::hashinsert(int a){
	for(int b=1;b<size;b++){
		if(hashtable[a].hashindex!=NULL){
			hashtable[a].hashindex= count;
		}
		else a=a+1;
	}
}

void Library::heapinsert(int key,int n){
	/*int var=n;
	  var=var+1;
	  content[var].priority=0;
	  heap_increasekey(var,content[var].priority);   */                      
} 

void Library::moveup(Song*A, int i){

	//content[i].priority=key;
	while(i>1 && content[parent(i)].priority< content[i].priority){
		swap(i,parent(i));  
		i=parent(i);
	}
}

void Library::movedown(int i,int a){
	int largest;
	int l,r;
	l=left(i);
	r=right(i);

	if(l <= count)               
	{
		if(l == count)          // If this root has no right child then 
		{
			largest = l;         //     leftChild must hold max key
		}
		else
		{    
			if(content[l].priority <= content[r].priority)
				largest = r;
			else
				largest = l;
		}
		if(content[i].priority < content[largest].priority)
		{
			swap(i,largest);
			movedown(largest, count);
		}
	}
}

void Library::Build_maxheap(Song*A){

	for(int i=count/2;i>0;i--) heapify(A,i);       
}

void Library::heapify(Song*A,int i){                                              
	int l, r;
	l = left(i);
	r = right(i);
	int largest = 0;

	if (l <=count && content[l].priority > content[i].priority){  largest = l;
	}
	else largest=i;

	if( r <= count && content[r].priority > content[largest].priority)
	{
		largest = r;
	}

	if( largest != i)
	{       
		swap(i,largest);
		heapify(content,largest);
	}

}  

void  Library::swap(int a,int b){

	Song temp;

	hashtable[content[b].hashindex].hashindex = a;
	hashtable[content[a].hashindex].hashindex = b;
	temp=content[a];
	content[a]=content[b];
	content[b]=temp;
}

int Library::getkey(string info){
	for(int i=1;i<=info.length();i++){

		asci+= int(info[i]) ;
	}
	hashkey=asci%size;
	return hashkey;
}

void Library::LIKE(string Title){

	//hashfn(Title);

	int a =getkey(Title);
	int b= hashtable[a].hashindex;

	if(content[b].likability >=0){
		content[b].likability+=1;
		content[b].priority= (cur_virtualtime-content[b].lastplayed)+1000*content[b].likability;
		moveup(content,b);
		Build_maxheap(content);
	}
	else{
		content[b].likability =1;
		content[b].priority= (cur_virtualtime-content[b].lastplayed)+1000*content[b].likability;
		moveup(content,b);
		Build_maxheap(content);
	}

}

void Library::LIKE(){

	//cout<<"Test";
	if(content[1].likability >=0){
		content[1].likability+=1;
		content[1].priority= (cur_virtualtime-content[1].lastplayed)+1000*content[1].likability;
		//cout<<" for like";
		movedown(1,count);
		Build_maxheap(content);
	}
	else{
		content[1].likability =1;
		content[1].priority= (cur_virtualtime-content[1].lastplayed)+1000*content[1].likability;
		movedown(1,count);
		Build_maxheap(content);
	}
}

void Library::DISLIKE(string Title){

	int a =getkey(Title);
	int b= hashtable[a].hashindex;

	if(content[b].likability <=0){
		content[b].likability-=1;
		content[b].priority= (cur_virtualtime-content[b].lastplayed)+1000*content[b].likability;
		movedown(b,count);
		Build_maxheap(content);
	}
	else{
		content[b].likability =-1;
		content[b].priority= (cur_virtualtime-content[b].lastplayed)+1000*content[b].likability;
		movedown(b,count);
		Build_maxheap(content);
	}
} 

void Library::DISLIKE(){
	if(content[1].likability <=0){
		content[1].likability-=1;
		content[1].priority= (cur_virtualtime-content[1].lastplayed)+1000*content[1].likability;
		//cout<<" for like";
		movedown(1,count);
		Build_maxheap(content);
	}
	else{
		content[1].likability =-1;
		content[1].priority= (cur_virtualtime-content[1].lastplayed)+1000*content[1].likability;
		movedown(1,count);
		Build_maxheap(content);
	}
}

void Library::PLAY(int N){
	for(int i=1;i<=N;i++){

		int  h= cur_virtualtime/3600;
		int  m=(cur_virtualtime/60)%60;
		int  s=(cur_virtualtime)%60;


		cout<<"["<<"Day"<<t_obj.d<<":"<<" "<<h<<":"<<m<<":"<<s<<"]"<<" "<< content[1].title <<" "<<"by"<< content[1].artist <<endl;

		cur_virtualtime+=content[1].dur;
		content[1].lastplayed=cur_virtualtime;
		content[1].priority= (cur_virtualtime-content[1].lastplayed)+1000*content[1].likability;

		for(int i=2;i<=count;i++){

			content[i].priority=(cur_virtualtime-content[i].lastplayed)+1000*content[i].likability;
			//movedown(1,count);
		}
		movedown(1,count);
		//Build_maxheap(content);

	}

}

void Library:: INIT(int  a){

	cur_virtualtime= a;
	//s_obj.lastplayed=a;
	//Library(a);
}

void Library::REST(int x,int y,int  z){
	int  i = x+(cur_virtualtime/3600);
	int  j = y+((cur_virtualtime/60)%60);
	if(i>=24){

		t_obj.d+=1;
		cur_virtualtime= cur_virtualtime-x*3600+60*y+z;
	}
	else{
		cur_virtualtime += x*3600+60*y+z;
	}
}

Library::~Library(){

	//delete [] content;
}
