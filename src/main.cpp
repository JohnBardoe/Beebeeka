#include <Arduino.h>
#include "Pair.h"

#define startX 3
#define startY 3

#pragma region PORTS
#define ML 5
#define DIRECTIONL 2
#define MR 10
#define DIRECTIONR 7

#define LEFT_COL 0
#define RIGHT_COL 1

#pragma endregion PORTS

#pragma region constansts
#define TOP_SPEED 150
#define LOW_SPEED 120
#define DEG90TURN 700
#pragma endregion

#define getLeftColor() digitalRead(LEFT_COL)
#define getRightColor() digitalRead(RIGHT_COL)

void driveCells(int cells){

}

void turnLeft(int angle){
      rightMotor(LOW_SPEED);
      leftMotor(-LOW_SPEED);
      delay(DEG90TURN * (angle/90));
      rightMotor(LOW_SPEED);
      leftMotor(LOW_SPEED);
}

void turnRight(int angle){
      rightMotor(-LOW_SPEED);
      leftMotor(LOW_SPEED);
      delay(DEG90TURN * (angle/90));
      rightMotor(LOW_SPEED);
      leftMotor(LOW_SPEED);
}

int* getSensorData(){

}

struct Node{
  bool right = false, left = false, forward = false, back = false;
  
};


void leftMotor(int _speed){
  analogWrite(ML, abs(_speed));
  digitalWrite(DIRECTIONL, _speed > 0);
}

void rightMotor(int _speed){
  analogWrite(MR, abs(_speed));
  digitalWrite(DIRECTIONR, _speed < 0);
}

void lineFollow(){
  bool left = getLeftColor(), right = getRightColor();
      if(left && !right){
        leftMotor(TOP_SPEED);
        rightMotor(LOW_SPEED);
      }
      else if(!left && right){
        leftMotor(LOW_SPEED);
        rightMotor(TOP_SPEED);
      }
      else{
        leftMotor(TOP_SPEED);
        rightMotor(TOP_SPEED);
      }
}

int* adjList[4][8];
bool visited[4][8];
//adjList[0][0] = {0,0,1,1} 
// {up, right, down, left}

int* spin(){
  int* ans = new int[4];
  for(int j = 0; j < 4; j++)
    for(int i = 0; i < 90; i++){
      turnLeft(1);
      int* d = getSensorData();
      if(d[0] || d[1]){
        ans[j] = 1;
        turnLeft(90-i);
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
   pinMode(ML, OUTPUT);
   pinMode(DIRECTIONL, OUTPUT);
   pinMode(MR, OUTPUT);
   pinMode(DIRECTIONR, OUTPUT);
   
   pinMode(LEFT_COL, INPUT);
   pinMode(RIGHT_COL, INPUT);
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 4; j++)
      visited[j][i] = false;
  
  
}

void loop() {

}