#include<iostream>
#include<fstream>
#include<cstdlib>
#include "abrect.h"
//#include "use.h"
int cl = 8;
char Board[8][8];
board::board(int rows, int cols, int no_of ) {	
	r = rows;
	c= cols;
	no_of_player = no_of;
	
}

 void board::drawboard(){
	  	size_t i, j, k;
	 	matrix.resize(r);
	  	for (int i =0; i<r; i++){
	  		matrix[i].resize(c, "0");
	  		 
		  }
		  for(j=0; j<r; j++ ){
		  		cout<< " " ;
		  		for(k=0; k<c; k++){
		  			cout<< matrix[j][k]<<" |";
			  }
			   cout<< "\n_________________________\n";
		  }
 		
	}
	
	

void board::placemarker(int slot){
	int rowe;
	int cole;
		if(slot%r==0){
			rowe = (slot/r) -1;
			cole=  c-1;
		}else{
			rowe = slot/r; 
			cole = (slot%c)-1;
		}
		string  c;
		cout<< "enter value";
 		cin>> c;
 		int x = c.size();
 		if(matrix[rowe][cole]=="0"){
 			if(x==1){
 			matrix[rowe][cole]= c;	
 			}else{
 				cout<< "enter only one string";
 				placemarker(slot);
	   }
	}else{
		cout<< " slot has already been taken";
	}
}


string board::getmarker(int slot){
	int rowe;
	int cole;
		if(slot%r==0){
			rowe = (slot/r) -1;
			cole=  c-1;
		}else{
			rowe = slot/r; 
			cole = (slot%c)-1;
		}
	string  ch;
 		if(matrix[rowe][cole] != "0"){
 			ch= matrix[rowe][cole];
		 }else{
		 	cout<< " value cannot be used";
		 }
 		
 		return ch;
 	
}

int board::che(int slot, int slots){
	int rowe1, cole1, rowe, cole;
	int rays =r;
	int cays= c;
	if(slot != slots){
		

	if(slot%rays==0){
			int y = slot/rays;
			rowe  = y-1;
			cout<< "rowe :" << rowe <<endl;
		
		}else{
			rowe = slot/rays;
			cout<< "rowe :" << rowe <<endl;
		}
		
		
	if(slots%rays==0){
			int y = slots/rays;
			cout <<y;
			rowe1 = y-1;
			cout<< "rowe1 :" << rowe1 <<endl;
		}else{
			rowe1 = slots/rays;
			cout<< "rowe1: " << rowe1 <<endl; 
		}
		
		
		
	if(slots%cays==0){
			cole1 = cays -1;
			cout<< "cole1: " << cole1 <<endl;
		}else{
			cole1 = (slots%cays)-1; 
			cout<< "cole1 :" << cole1 <<endl;
		}
		
	if(slot%cays==0){
			cole = cays-1;
			cout<< "cole :" << cole <<endl;
		}else{
			cole = (slot%cays)-1;
			cout<< "cole :" << cole <<endl; 
		}
		
	if( (rowe1== rowe) || (cole1 == cole)){
				if(rowe1==rowe){
					unsigned int x;
					 int xy = cole1 - cole;
					 x= abs(xy);
					 if (x==1){
					 	return 1;
					 }else{
					 	return 0;
					 }
			
	}else{
			unsigned int x;
			 int xy= rowe1 - rowe;
			 x= abs(xy);
			if (x==1){
					return 1;
			 }else{
				return 0;
			 }
	}
	
}else{
	return 0;
}

}else{
	cout<< "pointer should be different";
	return 0;
}

}



int board::check_win(){	
	int x= chr.size();
	cout<< x<<endl;
	size_t i, j;
	 	for (i=0; i<x-1; i++){
			int value = che(chr[i], chr[1+i]);
			if (value== 0){
				cout<<"this is not part of a rectangle";
				return 0;
		}	 	
		
	 }
	// cout<< "your values went well";	
	return 1;	
}


void board::sot(){	
//	chr.push_back(0);
	vector<int> arey;
	chr = arey;
	//chr = {0};		
	int  res;
	cout<<"res: ";
	cin>> res;
	chr.push_back(res);
//	cout<<" vector size: "<< chr.size();	
	while(res!= 0){
//	cout<< "res:"<<res;
		cout<<endl;
		cout<<"res: ";
		cin>> res;
		if(res!=0){
			chr.push_back(res);
		//cout<<" vector size:"<< chr.size();	
	}	
	
}
//	chr[0] = chr.size()-1;
//	int *bptr = &chr[0];
//	int y = bptr[0];
//	return bptr;
}

void board::getscores(size_t i){
	scores.resize(no_of_player, 0);	
	size_t j;
	for(j=0; j<no_of_player; j++){
		if(j==i){
			scores[j] = scores[j] +5;
			break;
		}else{
			continue;
		}
	}
}

string board::slos(){
	int x= chr.size();
	size_t i;
	string al;
	cout<< x;
	for(i=0; i<x; i++){
		string cou = getmarker(chr[i]) ;
		//cout<< cou;
		al = al + cou;	
	}
	//cout<< "al";
	return  al;
}
	
void board::scoreboard(){
	size_t j;
	 for(j=0; j<no_of_player; j++ ){
		  	int x = scores[j];
		  		cout<<"_______ \n";
		  		cout<<"| ";
				 cout<<j+1 <<"    "<< x<< "|\n" ;    
			//	 cout<< " 7\n" ;      
			 
				//cout<<"_______\n";
		  	
		  }
 		
	
}
 void board::play(size_t i){
 		drawboard();
 		int slot;
 		cin>> slot;
 		placemarker(slot);
 		cout<< "willing to continue press 1; else 0";
 		int xa;
 		cin>> xa;
 		if (xa == 0){
 			int *x;
 			 sot();
 			int xy = check_win();
 			cout<<"\n"<< xy;
 			string str = slos();
 			//cout<< str;
 			char arry [75];
  			strcpy(arry, str.c_str());
 			int xz  = get_words(arry);
 			cout<< xz;
			  if(xy==1 && xz==1){
			  		getscores(i);
			  		//cout<< "win";
			  		scoreboard();
			  		//drawboard();
			  }else{
			  //	drawboard();
			  }
 			
		 }else{
		 	//drawboard();
		 }
 }
 void board::game(){
 		size_t i, j, k, l ;
 		int x = r*c;
 		while(x!=0){
 		for( i=0; i<no_of_player; i++){
 			play(i);
 			x= x-1;
		 }
 }
 
}
 int main(){
 	board myboard(6,6,3);
  	//myboard.drawboard();
//	myboard.placemarker(6);
 //	myboard.placemarker(12);
 //	myboard.placemarker(18);
 //	myboard.placemarker(24);
 //	myboard.drawboard();
  ///	cout<<endl;
 	//size_t i;
 //	int *x = sot();
 	//myboard.sot();
	//for(i=1; i<=x[0]; i++){
	//	cout<< x[i]<<endl;
	 //}
	 //int xy = myboard.check_win();
	 //cout<< xy;
	 //myboard.scoreboard();
	//check_words mywords;
	//char love[30] = "Love";
//	myboard.sot();
	//string  str;
	//str= myboard.slos();
	//cout<< str;
//	char arry [75];
  //	strcpy(arry, str.c_str());
 //	int xz  = myboard.get_words(arry);
 //	printf("%d", xz);
	myboard.game();
 }
