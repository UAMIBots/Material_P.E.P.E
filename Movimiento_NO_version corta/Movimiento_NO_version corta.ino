int entrada1 = 8;
int entrada2 = 9;
int T0=200;
int T1=200;

int arduinoUNO=5;

int switchIzquierda=2;
int switchDerecha=3;

int sentidoHorario=0;
int onGoing=LOW;
 
void setup() {

  Serial.begin(9600);
  pinMode(entrada1, OUTPUT);
  pinMode(entrada2, OUTPUT);

  pinMode(arduinoUNO, INPUT);

  pinMode(2, INPUT);
  pinMode(3, INPUT);

  digitalWrite(entrada1, LOW);
  digitalWrite(entrada2, LOW);

  attachInterrupt(digitalPinToInterrupt(3),activaCabeza, RISING);
  attachInterrupt(digitalPinToInterrupt(2),cambiaSentido, RISING);
  
}

void cambiaSentido(){
  //Debouncing
  if(T0>199 && onGoing==HIGH){
  sentidoHorario=!sentidoHorario;
  digitalWrite(entrada1, sentidoHorario);
  digitalWrite(entrada2, !sentidoHorario);
  Serial.println("Cambio de sentido");
  T0=0;
  }
  }

  void activaCabeza(){
  //Debouncing
  if(T1>199){
  onGoing=!onGoing;
  if(onGoing==LOW){
    digitalWrite(entrada1, LOW);
  digitalWrite(entrada2, LOW);
    }else{
      digitalWrite(entrada1, sentidoHorario);
  digitalWrite(entrada2, !sentidoHorario);
      }
  Serial.println("Activada");
  T1=0;
  }
  }
 
void loop() {    
  T0++;
  T1++;
  Serial.println(T0);
  
}
