void setup()
{
Serial.begin(9600);
pinMode(A0, INPUT_PULLUP);
}
float x=0;

void loop()
{
x=0.5analogRead(A0) + 0.5x;
Serial.println(x);
}
}
