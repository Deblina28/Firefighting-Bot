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

if(x<300)
alarm();


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
