#include <Arduino.h>

void turnAng(int ang){}

void setSpeed(int speed){}

struct Pair{
  int x, y;
};

struct Node{
  bool right = false, left = false, forward = false, back = false;
  
};



int adjList[4][8][4];

//adjList[0][0] = {0,0,1,1} 
// {up, right, down, left}

void dfs(){

}

void setup() {
	delay(1);
}

void loop() {

}