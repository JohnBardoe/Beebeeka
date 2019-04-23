#include <Arduino.h>
#include "Pair.h"

#define startX 3
#define startY 3

void driveCells(int cells){

}

void turn(int angle){
  
}

struct Node{
  bool right = false, left = false, forward = false, back = false;
  
};


int* adjList[4][8];
bool visited[4][8];
//adjList[0][0] = {0,0,1,1} 
// {up, right, down, left}

int* spin(){
  
}

void scan(int x, int y){
  adjList[x][y] = spin();
  visited[x][y] = true;
  for(int i = 0; i < 4; i++){
    Pair coord = Pair(x + (int)(i % 2 != 0), y + (int)(i % 2 == 0));
    if(adjList[x][y][i] == 1)
      if(!visited[coord.x][coord.y]){
        turn(i*90);
        driveCells(1);
      }
        
      
  }

}

void setup() {
	delay(1);
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 4; j++)
      visited[j][i] = false;
}

void loop() {

}