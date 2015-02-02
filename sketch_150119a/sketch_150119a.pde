void setup() {
  size(550, 550);
}

PImage img1;
PImage img2;

float x = 0;
float y = 0;
int num_Obj = 10;
boolean Uturn;

int time = 0;
boolean move_inv;

void draw() {
  img1 = loadImage("invador1.png");
  img2 = loadImage("invador2.png");
  background(0);

  time++;
  if(time > 60) time = 0;
  
  if(time/30 == 0){
    move_inv = true;
  }
  else{
    move_inv = false;
  }
  
  for (int i = 0; i < num_Obj; i++) {
    if(move_inv){
      image(img1, x+30*i, y, 30, 30);
    }
    else{
      image(img2, x+30*i, y, 30, 30);
    }
  }
  
  if (x < 0) {
    Uturn = true;
    y += 30;
  }
  if (x+(30*(num_Obj-1))+30 >= width) {
    Uturn = false;
    y += 30;
  }

  if (Uturn){
    x+=2;
  }
  else{
    x-=2;
  }
  
  if (y >= height - 30){
    y = 20;
  } 
}

void keyReleased(){
  if(key == '[' || key == '{'){
    if(num_Obj < 10){
      num_Obj++;
    }
  }

  if(key == ']' || key == '}'){
    if(num_Obj > 1){
      num_Obj--;
    }
  }
  
}

