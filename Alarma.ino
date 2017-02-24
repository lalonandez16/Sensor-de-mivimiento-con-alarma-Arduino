int pirPin = 7;
int ledPin = 6;
int boton = 8;
boolean estado = false;
void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(boton, INPUT);

  digitalWrite(pirPin, HIGH);
  digitalWrite(ledPin, LOW);



}



void loop() {


  if (digitalRead(pirPin) == LOW)
  {
    Serial.println("** MOVEMENT DETECTED **");

    for (int i = 0; i <= 1000; i++) {
      Serial.println("WAITING FOR ACTION");
      if (digitalRead(boton) == HIGH) {
        estado = true;
        Serial.println("OVERPROGRESSED BUTTON");
        break;
      }
      i++;
    }


    if (digitalRead(estado) == LOW)
    {
      digitalWrite(ledPin, LOW);
      Serial.println("ALARM OFF");
      estado = false;

    }
    else {
      while (digitalRead(boton) == LOW)
      {
        digitalWrite(ledPin, HIGH);

        Serial.println("||||||INTRUDE ALERT||||||");


      }
      Serial.println("** ALARM OFF **");

      digitalWrite(ledPin, LOW);
    }

  }

  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("** ALL RIGHT **");

  }

}

