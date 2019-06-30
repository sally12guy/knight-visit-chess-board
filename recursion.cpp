/*
Author¡G§d²»³Ô B053040044 
   Date : 11/5/2017
   Purpose¡Ghw4
*/ 
#include<iostream>
using namespace std;
int recursive(int x,int y,int move,int i,int **re){
	move=move+1;//move+1
	re[x][y]=move;//record which step it is
	//8 kinds of direction
	if(x-2>=0&&y+1<i&&re[x-2][y+1]==0){
		move=recursive(x-2,y+1,move,i,re);
	}
	if(x-1>=0&&y+2<i&&re[x-1][y+2]==0){
		move=recursive(x-1,y+2,move,i,re);
	}
	if(x+1<i&&y+2<i&&re[x+1][y+2]==0){
		move=recursive(x+1,y+2,move,i,re);
	}
	if(x+2<i&&y+1<i&&re[x+2][y+1]==0){
		move=recursive(x+2,y+1,move,i,re);
	}
	if(x+2<i&&y-1>=0&&re[x+2][y-1]==0){
		move=recursive(x+2,y-1,move,i,re);
	}
	if(x+1<i&&y-2>=0&&re[x+1][y-2]==0){
		move=recursive(x+1,y-2,move,i,re);
	}
	if(x-1>=0&&y-2>=0&&re[x-1][y-2]==0){
		move=recursive(x-1,y-2,move,i,re);
	}
	if(x-2>=0&&y-1>=0&&re[x-2][y-1]==0){
		move=recursive(x-2,y-1,move,i,re);
	}
	//if move=i*i over recursive
	if(move==i*i){
		return move;
	}
	//if all of the 8 directions can't work, this record clear and go back to previos step
	re[x][y]=0;
	return --move;
}
int main(){
	for(int i=1;i<=6;i++){
		int x=0,y=0,move=0;//x,y,move
		int **record=new int *[i];//pointer array
		for(int j=0;j<i;j++)
			record[j]=new int[i];//make array[]
		for (int j=0;j<i;j++)//make array[][]
			for (int k=0;k<i;k++)
				record[j][k]=0;//initialize
		move=recursive(x,y,move,i,record);//recursive
		cout<<i<<":"<<endl;//output
		if(move==i*i){
			for(int j=0;j<i;j++){
				for(int k=0;k<i;k++){
					if(record[j][k]<10)
						cout<<" ";
					cout<<record[j][k]<<" ";
				}
				cout<<endl;
			}
		}
		else
			cout<<"no solution"<<endl;
	}
	return 0;
}
