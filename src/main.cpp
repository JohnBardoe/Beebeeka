#include <Arduino.h>
#include "Pair.h"

#define startX 3
#define startY 3

void driveCells(int cells){

}

void turn(int angle){
  
}

int* getSensorData(){

}

struct Node{
  bool right = false, left = false, forward = false, back = false;
  
};


int* adjList[4][8];
bool visited[4][8];
//adjList[0][0] = {0,0,1,1} 
// {up, right, down, left}

int* spin(){
  int* ans = new int[4];
  for(int j = 0; j < 4; j++)
    for(int i = 0; i < 90; i++){
      turn(1);
      int* d = getSensorData();
      if(d[0] || d[1]){
        ans[j] = 1;
        turn(90-i);
        break;
      }
      delay(2);
    }
  
}

void scan(int x, int y){
  adjList[x][y] = spin();
  visited[x][y] = true;
  for(int i = 0; i < 4; i++){
    
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