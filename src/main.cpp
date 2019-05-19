#include <Arduino.h>
#include "Pair.h"

#define startX 3
#define startY 3

#define ML 5
#define DIRECTIONL 2
#define MR 10
#define DIRECTIONR 8
#define LEFT_COL A0
#define RIGHT_COL A1

#define TOP_SPEED 5
#define LOW_SPEED 0
#define DEG90TURN 700
#define sensitivity 600

#define getLeftColor() analogRead(LEFT_COL) > sensitivity
#define getRightColor() analogRead(RIGHT_COL) > sensitivity

int* getSensorData(){
  int data[] = {getLeftColor(), getRightColor()};
  return data;
  
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

void lineFollow(){
  bool left = getLeftColor(), right = getRightColor();
  Serial.print(left);
  Serial.println(right);
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

int* convertScanData(int x, int y, int i){
  int* result = new int[2];
  result[0] = x;
  result[1] = y;
  switch(i){
    case 0:
      result[1]++;
    break;
    case 1:
      result[0]++;
    break;
    case 2:
    result[1]--;
    break;
    case 3:
    result[0]--;
    break;
  };
  return result;
}

///dfs
void scan(int x, int y){
  adjList[x][y] = spin();
  if(!visited[x][y]){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
      if(adjList[x][y][i] == 1){
        int* gt = convertScanData(x, y, i);
        scan(gt[0], gt[1]);
      }
    }
  }
  
}

void setup() {
	delay(10);
   pinMode(ML, OUTPUT);
   pinMode(DIRECTIONL, OUTPUT);
   pinMode(MR, OUTPUT);
   pinMode(DIRECTIONR, OUTPUT);
   
   pinMode(LEFT_COL, INPUT);
   pinMode(RIGHT_COL, INPUT);
   
}

void loop() {
   lineFollow();
}