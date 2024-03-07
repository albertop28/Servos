# 2DOF camera positioner using 2 servomotors and a joystick
Primero que todo aqúi se ocupó un ADC de 10 bits programado en un arduino:
//Variables Globales ---------------------------------------------------------------------------------- 
int numero = 0;
int numero1 = 0;
int sensor = 0;
int sensor1 = 0;

//Definición de pines digitales de salida y velocidad de transmisión serial-------------- 
void setup() { 
    for (int i=2; i<=40; i++) { 
        pinMode(i,OUTPUT); 
    } 
    Serial.begin(9600); 
}

//Función para convertir un número a binario -------------------------------------------------- 
int binario (int x) {//graba el número leído en el puerto analógico en los siguientes pines 
    digitalWrite(22, bitRead(x,0)); //Escribimos en el PIN22 el valor del bit 0 
    digitalWrite(24, bitRead(x,1)); //Escribimos en el PIN24 el valor del bit 1 
    digitalWrite(26, bitRead(x,2)); //Escribimos en el PIN26 el valor del bit 2 
    digitalWrite(28, bitRead(x,3)); //Escribimos en el PIN28 el valor del bit 3 
    digitalWrite(30, bitRead(x,4)); //Escribimos en el PIN30 el valor del bit 4 
    digitalWrite(32, bitRead(x,5)); //Escribimos en el PIN32 el valor del bit 5 
    digitalWrite(34, bitRead(x,6)); //Escribimos en el PIN34 el valor del bit 6 
    digitalWrite(36, bitRead(x,7)); //Escribimos en el PIN36 el valor del bit 7 
    digitalWrite(38, bitRead(x,8)); //Escribimos en el PIN38 el valor del bit 8 
    digitalWrite(40, bitRead(x,9)); //Escribimos en el PIN40 el valor del bit 9 
}

int binario1 (int y) {//graba el número leído en el puerto analógico en los siguientes pines 
    digitalWrite(2, bitRead(y,0)); //Escribimos en el PIN2 el valor del bit 0 
    digitalWrite(3, bitRead(y,1)); //Escribimos en el PIN3 el valor del bit 1 
    digitalWrite(4, bitRead(y,2)); //Escribimos en el PIN4 el valor del bit 2 
    digitalWrite(5, bitRead(y,3)); //Escribimos en el PIN5 el valor del bit 3 
    digitalWrite(6, bitRead(y,4)); //Escribimos en el PIN6 el valor del bit 4 
    digitalWrite(7, bitRead(y,5)); //Escribimos en el PIN7 el valor del bit 5 
    digitalWrite(8, bitRead(y,6)); //Escribimos en el PIN8 el valor del bit 6 
    digitalWrite(9, bitRead(y,7)); //Escribimos en el PIN9 el valor del bit 7 
    digitalWrite(10, bitRead(y,8)); //Escribimos en el PIN10 el valor del bit 8 
    digitalWrite(11, bitRead(y,9)); //Escribimos en el PIN11 el valor del bit 9 
}
//Ciclo Infinito ------------------------------------------------- 
void loop() { 
    sensor = analogRead(A0); //se toman los
    sensor1 = analogRead(A1); //valores analógicos 
    Serial.print("Valor = "); Serial.println(sensor); //se imprime la señal para el monitoreo en el plotter 
    numero = binario(sensor); //se llama la función binario 
    numero1 = binario1(sensor1); //se llama la función binario1 
    delayMicroseconds(100); 
}

• Para el servomotor con 360° de libertad fue un poco más fácil que para el de 180° de libertad, con este cuando la señal digital es menor que un valor dado de 150 (010010110 en binario) la señal PWM de control tiene un periodo positivo de 1 milisegundos que hace girar al motor en un sentido antihorario a máxima velocidad. Si el valor de la señal digital es mayor al valor de 900 (1110000100 en binario) el periodo positivo de la señal es de 2 milisegundo que hace girar al motor en sentido horario a máxima velocidad. Y cuando no es ninguno de los dos el periodo positivo de la señal se queda en 1.5 milisegundos la cual deja inmóvil al motor. Cabe mencionar que el periodo total de la señal se manejó de 20 milisegundos.
• Para el servomotor con 180° de libertad el proceso de programación fue un poco más tardado. El recorrido de 180° se dividió en 20 (9° de definición en el recorrido). Cuando la señal del ADC es menor a 150 la FPGA va haciendo el periodo de la señal PWM más pequeña hasta llegar a un tope de 0.4 milisegundos y si el valor del ADC es mayor que 900 entonces el periodo positivo de la señal PWM de control se va haciendo más grande hasta llegar a un tope de 2.3 milisegundos. Esto fue así porque el modelo de servomotor que se ocupó tiene como límite inferior 0.6 milisegundo y límite máximo de 2.3 milisegundos. Si el valor obtenido del ADC no supera ninguno de los dos limites el periodo positivo de la señal PWM no se modifica.

El video de implementación del proyecto:
https://www.youtube.com/watch?v=xTHE_vo7brk