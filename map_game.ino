int curPosition = 9;
int exitPosition = 4;
int null = -1;
boolean isGameOver = 0;
//                          n     e    s   w 
int mapGrid[14][4] = {   { null, null, 1, null},
                         { 0, 2, 5, null},
                         { null, 3, null, 1},
                         { null, 4, 6, 2},
                         { null, null, null, 3},
                         { 1, null, 7, null},
                         { 3, null, null, null},
                         { 5, 8, 9, null},
                         { null, null, 10, 7},
                         { 7, 10, null, null},
                         { 8, 11, null, 9},
                         { null, 12, null, 10},
                         { 13, null, null, 11},
                         {null, null, 12, null}  };
                         
                         
char* description [14] = {  "",
                            "there is a wall to the west and a huge stalagtite",
                            "there are walls to the north and south",
                            "there is a wall to the north",
                            "",
                            "there are walls to the east and west",
                            "",
                            "there is a wall to the west",
                            "there are walls to the north and east",
                            "there are walls to the south and west",
                            "there is a wall to the south",
                            "there are walls to the north and south",
                            "",  
                            ""};
                            
int trap [14] = { 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3};
// 0 = nothing
// 1 = pit fall trap
// 2 = chained deamon
// 3 = magic flames


// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600);
  Serial.println("you awaken in a cavern. scrawled on the ground in front of you are the words 'welcome to the labyrinth!'");
  Serial.println("Type N, E, S, or W to move through the labyrinth.");
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available()){
    char command = Serial.read();
    
    if (isGameOver){
      Serial.println("sorry your game is over");
    } else {
      command = toupper(command);
      switch(command){
        case 'N':
          if( mapGrid[curPosition][0] > -1){  
            Serial.println("I will move north");
            curPosition = mapGrid[curPosition][0];
          } else {
            Serial.println("I can't move north, there is a wall there.");
          }
          break;
          
        case 'E':
          if( mapGrid[curPosition][1] > -1){  
            Serial.println("I will move east");
            curPosition = mapGrid[curPosition][1];
          } else {
            Serial.println("I can't move east, there is a wall there.");
          }
          break;
          
        case 'S':
          if( mapGrid[curPosition][2] > -1){  
            Serial.println("I will move south");
            curPosition = mapGrid[curPosition][2];
          } else {
            Serial.println("I can't move south, there is a wall there.");
          }
          break;
          
        case 'W':
          if( mapGrid[curPosition][3] > -1){  
            Serial.println("I will move west");
            curPosition = mapGrid[curPosition][3];
          } else {
            Serial.println("I can't move west, there is a wall there.");
          }
          break;
        default:
          Serial.println("command not recognized");
      }
      whereAmI();
    }    
  }
}

void gameOver(){
  isGameOver = 1;
}

void whereAmI(){
  if (! isGameOver){
    Serial.print("Your current possition is: "); Serial.println(curPosition);
    Serial.println(description[curPosition]);
    
    if (curPosition == exitPosition){
      Serial.println("wow, you made it. good job");
      gameOver();
    }
    
    switch(trap[curPosition]){
      // 1 = pit fall trap
      // 2 = chained deamon
      // 3 = magic flames
      case 1:
        Serial.println("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa! a pit fall trap! game over");
        gameOver();
        break;
      case 2:       
        Serial.println("oh no, a chained deamon! game over");
        gameOver();
        break;
      case 3: 
        Serial.println("bad luck, there are magic flames here. game over");
        gameOver();
        break;     
      default:
        if (! isGameOver) Serial.println("where to now?");
    }
  }  
}
