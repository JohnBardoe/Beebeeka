#include <Arduino.h>
#include "vector.h"

void turnAng(int ang){}

void setSpeed(int speed){}

struct Pair{
  int x, y;
};

struct Node{
  bool right = false, left = false, forward = false, back = false;
  
};


int map[4][8];

int adjList[4][8][4];

//adjList[0][0] = {0,0,0,0};

void dfs(){

}

void setup() {
	delay(1);
}

void loop() {

}