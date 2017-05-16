/// Simulation Sketch I mention 

/* Code: */ 

bool playerOne_rock, playerTwo_rock;
bool playerOne_paper, playerTwo_paper;
bool playerOne_scizzors, playerTwo_scizzors;
bool playerOne_choice, playerTwo_choice;
bool playerOne_win, playerTwo_win;

int led = 13; // LED_BUILTIN;
int led_playerOne_lost = LED_BUILTIN;
int timer = 0;

void Main() {

    if (!playerOne_win) {
      digitalWrite(13, HIGH);
      // digitalWrite(led, LOW);
    } else {
      digitalWrite(13, LOW);
      // digitalWrite(led, HIGH);
    }


    playerOne_rock = false;
    playerTwo_rock = false;
    
    playerTwo_paper = false;
    playerOne_paper = false;
    
    playerOne_scizzors = false;
    playerTwo_scizzors = false;
    
    int _playerOne_choice = random(2); // Rock: (Button) 1, Paper: (Button) 2, Scizzors: (Button) 3
    int _playerTwo_choice = random(2);

    playerOne_choice = floor(_playerOne_choice);
    playerTwo_choice = floor(_playerTwo_choice);   
   
    playerOne_win = false;
    playerTwo_win = false;

    if (playerOne_choice == 0)
        playerOne_rock = true;
    else if  (playerOne_choice == 1)
        playerOne_paper = true;
    else if  (playerOne_choice == 2)
        playerOne_scizzors = true;
    
    if (playerTwo_choice == 0)
        playerTwo_rock = true;
    else if (playerTwo_choice == 1)
        playerTwo_paper = true;
    else if (playerTwo_choice == 2)
        playerTwo_scizzors = true;

    if (playerTwo_choice != playerOne_choice)
        if (playerOne_rock and playerTwo_paper)  
            playerOne_win = true;
        else if (playerOne_paper and playerTwo_rock)
            playerOne_win = true;
        else if (playerOne_scizzors and playerTwo_paper)
            playerOne_win = true;
        else
            playerOne_win = false;
    // else
       // printf "\n TIE"

    
    if (playerOne_win) {
        digitalWrite(led, HIGH);
        // print "\n PLAYER ONE WINS!"
        Serial.print("PLAYER ONE WINS!");
    } else if (playerOne_win and playerTwo_win) {
        // print "\n PLAYER ONE & PLAYER TWO WINS!"
        Serial.print("PLAYER ONE & PLAYER TWO WINS");
    } else if (playerTwo_win) {
          // print "\n PLAYER TWO WINS!"
          digitalWrite(led, LOW);
          Serial.print("PLAYER TWO WINS");
    } else {
          // print "Issue"
          digitalWrite(led, LOW);
          Serial.println("Issue");
    }
    
}   

void setup() {
  Serial.begin(9600);

      pinMode(13, OUTPUT);
}

void loop() {

  Main();
  delay(2000);
  
  /*
   if (timer > 40000) {
    Main();
    timer = 0;
  } else {
    timer+=1;
  }
  */
   
}

