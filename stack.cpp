#include<iostream>
using namespace std;
//class loc use to record x,y and direction
class loc{
	public:
		loc(){
			a=-1;
			b=-1;
			c=-1;
		}
		loc(int x,int y,int z){
			a=x;
			b=y;
			c=z;
		}
		int a;//x
		int b;//y
		int c;//direction
}; 
//class locs use to record a stack
class locs{
	public:
		locs(int n){
			stack=new loc[n];//allocate memory to stack
			this->n=n;
			count=0;
		}
		//push one data to stack
		void push(int a,int b,int c){
			if(count<n)
				stack[count++]=loc(a,b,c);
		}
		//pop one data from stack	
		loc pop(){
			if(count>0){
				count=count-1;
				return stack[count];
			}
		}
		int count;//count
	private:
		loc *stack;//stack
		int n;//size of stack
};
int main(){
	//r frem 1~6
	for(int r=1;r<=6;r++){
		locs record(r*r);//use to stack
		loc getpop;//use to save pop data
		int re[6][6]={0};//use to record the step
		re[0][0]=1;//start from the matrix[0][0] 
		//x,y,direction,move is to record which step is it
		int x=0,y=0,direc=0,move=1;
		while(move<r*r){
			//1 deirection
			if(direc<1&&x-2>=0&&y+1<r&&re[x-2][y+1]==0){
				//record x,y,direction to stack
				record.push(x,y,1);
				x=x-2;
				y=y+1;
				move=move+1;
				re[x][y]=move;
				direc=0;
				continue; 
			}
			//2
			if(direc<2&&x-1>=0&&y+2<r&&re[x-1][y+2]==0){
				//record x,y,direction to stack
				record.push(x,y,2);
				x=x-1;
				y=y+2;
				move=move+1;
				re[x][y]=move;
				direc=0;
				continue; 
			}
			//3
			if(direc<3&&x+1<r&&y+2<r&&re[x+1][y+2]==0){
				//record x,y,direction to stack
				record.push(x,y,3);
				x=x+1;
				y=y+2;
				move=move+1;
				re[x][y]=move;
				direc=0;
				continue; 
			}
			//4
			if(direc<4&&x+2<r&&y+1<r&&re[x+2][y+1]==0){
				//record x,y,direction to stack
				record.push(x,y,4);
				x=x+2;
				y=y+1;
				move=move+1;
				re[x][y]=move;
				direc=0;
				continue; 
			}
			//5
			if(direc<5&&x+2<r&&y-1>=0&&re[x+2][y-1]==0){
				//record x,y,direction to stack
				record.push(x,y,5);
				x=x+2;
				y=y-1;
				move=move+1;
				re[x][y]=move;
				direc=0;
				continue; 
			}
			//6
			if(direc<6&&x+1<r&&y-2>=0&&re[x+1][y-2]==0){
				//record x,y,direction to stack
				record.push(x,y,6);
				x=x+1;
				y=y-2;
				move=move+1;
				re[x][y]=move;
				direc=0;
				continue; 
			}
			//7
			if(direc<7&&x-1>=0&&y-2>=0&&re[x-1][y-2]==0){
				//record x,y,direction to stack
				record.push(x,y,7);
				x=x-1;
				y=y-2;
				move=move+1;
				re[x][y]=move;
				direc=0;
				continue; 				
			}
			//8
			if(direc<8&&x-2>=0&&y-1>=0&&re[x-2][y-1]==0){
				////record x,y,direction to stack
				record.push(x,y,8);
				x=x-2;
				y=y-1;
				move=move+1;
				re[x][y]=move;
				direc=0;
				continue; 
			}
			//if stack is empty than break
			if(record.count==0)
				break;
			//if the directoim fail than back to the previos siuation and try next
			getpop=record.pop();
			re[x][y]=0;
			x=getpop.a;
			y=getpop.b;
			direc=getpop.c;
			move--;
		}
		cout<<r<<":"<<endl;
		//cout the final siuation
		if(move==r*r){
			for(int i=0;i<r;i++){
				for(int j=0;j<r;j++){
					if(re[i][j]<10)
						cout<<" ";
					cout<<re[i][j];
					cout<<" ";
				}
				cout<<endl;
			}		
		}
		//if fail cout no solution
		else
			cout<<"no solution"<<endl;
		cout<<endl;
	}
	return 0;
}
