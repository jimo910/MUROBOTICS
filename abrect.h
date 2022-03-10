#include<iostream>
#include<vector>
using namespace std;
#include <stdio.h>
#include <string.h>
class board {
	public:		
		explicit board(int , int , int );	
		void drawboard();
		void scoreboard();
		int winner();
		void placemarker( int x);
		string getmarker(int slot);
		int check_win();
		int che(int x, int y);
		string slos();
		void getscores(size_t i);
		void game();
		void play(size_t i);
		void sot();
		int get_words(char *word ){
			FILE *fptr;
			char name[30];
			//char love[5] = "Lov";
			//char lovs[5] = "Lover";
			if ((fptr= fopen("words.txt","r") ) == NULL) {
				puts("File could not be opened");
			 } else {
 			while (!feof(fptr)) { 
 				fscanf(fptr, "%29s",  &name);
 		//printf("%s", name);
				if (strcmp(word, name)==0 ){
				return 1;
			}

		 } 
 		return 0;
	}
		
}
		
	
	private:
		 int r;
	 	 int c;
		 int no_of_player;
		 vector<vector< string > > matrix;
		 vector <int> win;
		 vector <int> scores;
		 vector<int> chr;
			//int bptr[];
};


