#include "Adafruit_Thermal/Adafruit_Thermal.h"

Adafruit_Thermal printer;
int led1 = D6;
int inPin = D0;
int val = 0;
// int buzzerPin = A0;


bool hasPrinted = false;

char const *sentenceIntro[] = {"There's an emergency at"};
char const *sentenceWhere[] = {"Bella's Cafe ","Ponty Pandy railway station ","Bessie's shed ","the general store ","the lighthouse ","Ponty Pandy mountain ","Sam's house ","the firestation"};
char const *sentenceWho[] = {"Norman Price","Mandy Flood","Elvis","Sarah","James","Bella Lasagne","Station Office Steele","Elvis","Bronwyn ","Charlie ","Moose ","Norris the Guinea Pig ","Lion the Cat ","Mr Fox ","Trevor ","Dilys ","The Pope ","Granny ","Silly Poppa"};
char const *sentenceIncident[] = {"is stuck in a cupboard ","is trapped under a boulder ","is on fire ","is missing ","is being attacked by a dinosaur ","has upset Mrs Polar Bear ","spontaenously combusted ","impaled themeselves on a spork ","is being eaten by a rabbit ","is very stinky ","is stuck up a tree ","has gone missing ","needs help changing a lightbulb ","has discovered an unexploded sea mine ","is running around with no clothes on ","has lost their marbles ","is talking to a sock ","voted for Brexit ","started a chip fire ","fell down a well ","is wedged in the chimney"};

void setup(){
  Serial.begin(9600);
  Serial1.begin(19200);
  printer.begin(&Serial1);

  pinMode(led1, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
    digitalWrite(led1, LOW); 
    val = digitalRead(inPin);
    
    if (val == HIGH) {
        digitalWrite(led1, HIGH);
    }
    else {
        digitalWrite(led1, LOW); 
    }
}

void printMessage() {
  
  int where = random(0, 7);
  int who = random(0,17);
  int incident = random(0,20);
  
  printer.setSize('S');        // Set type size, accepts 'S', 'M', 'L'
  printer.println(sentenceIntro[0]);
  printer.println(sentenceWhere[where]);
  printer.println(sentenceWho[who]);
  printer.println(sentenceIncident[incident]);
  printer.println();
  printer.println();
  printer.println();
  printer.println();
}
