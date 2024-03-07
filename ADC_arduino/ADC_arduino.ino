//Variables Globales -----------------------------------------
//double valor = 0;
int numero = 0;
int sensor = 0;

void setup() {
  for (int i=22; i<=40; i++)
  {
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}

//Función para convertir un número a binario ----------------------------------
int binario(int x)
{
  digitalWrite(22, bitRead(x,0)); //Escribimos en el PIN0 el valor del bit 0
  digitalWrite(24, bitRead(x,1)); //Escribimos en el PIN1 el valor del bit 1
  digitalWrite(26, bitRead(x,2)); //Escribimos en el PIN2 el valor del bit 2
  digitalWrite(28, bitRead(x,3)); //Escribimos en el PIN3 el valor del bit 3
  digitalWrite(30, bitRead(x,4)); //Escribimos en el PIN4 el valor del bit 4
  digitalWrite(32, bitRead(x,5)); //Escribimos en el PIN5 el valor del bit 5
  digitalWrite(34, bitRead(x,6)); //Escribimos en el PIN6 el valor del bit 6
  digitalWrite(36, bitRead(x,7)); //Escribimos en el PIN7 el valor del bit 7
  digitalWrite(38, bitRead(x,8)); //Escribimos en el PIN6 el valor del bit 8
  digitalWrite(40, bitRead(x,9)); //Escribimos en el PIN7 el valor del bit 9
}
//Ciclo Infinito -----------------------------------------------------------------
void loop() {
  sensor = analogRead(A0);
  //valor = sensor;
  Serial.print("Valor = ");
  Serial.println(sensor);
  numero = binario(sensor);
  delayMicroseconds(100);
}
