void setup()
{
Serial.begin(9600);

pinMode(3, OUTPUT);
pinMode(5, OUTPUT);

pinMode(A0, INPUT_PULLUP);
}
float x=0;

void loop()
{
x=0.5*analogRead(A0) + 0.5*x;
Serial.println(x);

if(x<300)
alarm();

else
{
digitalWrite(3, LOW);
digitalWrite(5, LOW);
}

}

void alarm()
{
for(int i=0;i<256;i++, delay(4))
{
analogWrite(3, i);
analogWrite(5, i);
}

for(int i=255;i>0;i--, delay(4))
{
analogWrite(3, i);
analogWrite(5, i);
}

}
