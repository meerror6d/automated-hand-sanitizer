const int trigPin = 14;
const int echoPin = 15;
const int pumpPin = 8;

long duration;
int distance;

void dis(){
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
}
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin,HIGH);

  }




void loop() {

  dis();

  if(distance<17 && distance >14){
      digitalWrite(pumpPin,LOW);
    }
    else{
          digitalWrite(pumpPin,HIGH);

      }

  
  }