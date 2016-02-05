#include <iostream>
#include "Time.h"
#include "Song.h"
#include "Library.h"
//#include<cstring>
#include "string.h"
#include <fstream>
#include<sstream>

using namespace std;

Time t;
Time t1;                                                                        // t - Time obj to hold current time
Song so;
Library lib;
Library lib1;
int start_time,size;

int main(){
	string word,Title,info,N,init;
	string command,next;
	string line,temp1,temp2, temp3,temp4;
	long d,h,m,s;

	int Max;
	//string mil_time;
	int maxsongs;
	char colon;

	cout<<"Type one of the following commands: RUN,INIT,ADD,PLAY,LIKE,DISLIKE,PLAY,QUIT"<<endl;

	cin>>word;
	while (word != "QUIT") {
		if (word=="RUN"){
			string filename;
			cin>> filename;
			if (filename=="input.txt"){
				ifstream readfile;
				readfile.open("input.txt");
				while(  getline(readfile,line)){
					istringstream ab(line);
					//cin>> command>>temp2>>temp3>>temp4;
					while(ab>>command){
						if(command=="INIT"){
							getline(ab,temp1,':');
							istringstream(temp1)>>h;
							//cout<<h<<endl;

							getline(ab,temp2,':');
							istringstream(temp2)>>m;
							//cout<<m<<endl;

							ab>>s;
							//cout<<s<<endl;

							ab>>Max;
							lib.size=Max;
							lib.Array(Max);
							//cout<<Max<<endl;

							long secs=h*3600+m*60+s;
							//cout<<secs<<endl;      
							lib.INIT(secs); 
							start_time=secs;
							//t.cur_virtualtime= secs;

						}

						else if(command=="ADD"){

							//getline(ab,temp1);
							//lib.ADD(temp1);

							getline(ab,temp1,',');
							//cout<< temp1;
							so.title= temp1;

							getline(ab,temp2,',');
							//cout<<temp2;
							so.artist= temp2;

							getline(ab,temp3,':');
							istringstream(temp3)>>m;
							//cout<<temp3;

							getline(ab,temp4,'\n');
							istringstream(temp4)>>s;
							//cout<<temp4;

							so.dur =60*m+s;
							//cout<<so.dur;

							lib.ADD(temp1,temp2,so.dur,start_time);         
						}

						else if(command=="REST"){
							getline(ab,temp1,':');
							istringstream(temp1)>>h;
							//cout<<h<<endl;

							getline(ab,temp2,':');
							istringstream(temp2)>>m;
							//cout<<m<<endl;

							ab>>s;
							//cout<<s<<endl;

							lib.REST(h,m,s);
						}

						else if(command=="LIKE"){

							getline(ab,temp2);
							if(temp2.length()>1) lib.LIKE(temp2);
							else lib.LIKE();							

						}
						else if(command=="DISLIKE"){
							getline(ab,temp2);
							if(temp2.length()>1) lib.DISLIKE(temp2);
							else lib.DISLIKE();

						}
						else if(command=="PLAY"){
							int num;
							ab>>num;
							lib.PLAY(num);
						}
						else if(command=="QUIT"){
							return 0;
						}
					}


				}
			}

		}

		else if (word=="INIT"){
			string init;
			getline(cin, init);
			istringstream ab(init);
			getline(ab,temp1,':');
			istringstream(temp1)>>h;
			getline(ab,temp2,':');
			istringstream(temp2)>>m;
			ab>>s;
			ab>>Max;
			lib.size=Max;
			lib.Array(Max);
			int secs=h*3600+m*60+s;
			lib.INIT(secs); 
			start_time=secs;


		}
		else if (word=="REST"){
			string info;
			getline(cin, info);
			istringstream ab(info);
			getline(ab,temp1,':');
			istringstream(temp1)>>h;
			getline(ab,temp2,':');
			istringstream(temp2)>>m;
			ab>>s;
			lib.REST(h,m,s);
		}
		else if (word=="ADD"){

			string info;
			getline(cin,info);
			istringstream ab(info);
			getline(ab,temp1,',');
			so.title= temp1;
			getline(ab,temp2,',');
			so.artist= temp2;
			getline(ab,temp3,':');
			istringstream(temp3)>>m;
			getline(ab,temp4,'\n');
			istringstream(temp4)>>s;
			so.dur =60*m+s;
			lib.ADD(temp1,temp2,so.dur,start_time); 

		}
		else if (word=="LIKE"){
			string Title;
			getline(cin, Title);
			if(Title.length()>1) lib.DISLIKE(Title);
			else lib.DISLIKE();
		}
		else if (word=="DISLIKE"){
			string Title;
			getline(cin, Title);
			if(Title.length()>1) lib.DISLIKE(Title);
			else lib.DISLIKE();
		}
		else if (word=="PLAY"){
			int N;
			string info;
			getline(cin,info);
			istringstream ab(info);
			ab>>N;
			lib.PLAY(N);
		}
		cout<<"Type one of the following commands: RUN,INIT,ADD,PLAY,LIKE,DISLIKE,PLAY,QUIT"<<endl;
		cin >> word;
	}
}


