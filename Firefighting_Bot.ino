void setup()
{
Serial.begin(9600);

DDRB|=0xff;
PORTB=0x00;
  
pinMode(A0, INPUT_PULLUP);
}

float x=0;
int x[4], y[4];
int n=4;

void loop()
{
x=0.5*analogRead(A0) + 0.5*x;
Serial.println(x);

for(byte addr=0;addr<7;addr++)
{
  PORTB=addr;
  x[addr]=analogRead(A0);
  y[addr]=analogRead(A0)&(addr&2|addr&3|addr&4|addr&5);
}
  centroid();
if(cx&&cy<300)
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



void centroid()
{
float a, cx, cy, t;
int i, i1;

a = 0.0;
i1 = 1;
for (i=0; i<n; i++) {
a += x[i] * y[i1] - x[i1] * y[i];
i1 = (i1 + 1) % n;
}
a *= 0.5;
cx = cy = 0.0;
i1 = 1;
for (i=0; i<n; i++) 
{
t = x[i]*y[i1] - x[i1]*y[i];
cx += (x[i]+x[i1]) * t;
cy += (y[i]+y[i1]) * t;
i1 = (i1 + 1) % n;
}
cx = cx / (6.0 * a);
cy = cy / (6.0 * a);
}


