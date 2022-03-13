unsigned int Ts=20000; // Periodo de muestreo [us]
unsigned int t, t0;
int valor = 0,valor2=0;      // Variable donde almacenaremos el valor del potenciómetro
float voltaje = 0;  // Variable para almacenar el voltaje
int digPin5 = 5; // pin digital 5
int digPin6 = 6; // pin digital 6
int pot2;
float setpoint, k=1;
float error, voltajeinicial;
int PWM;
//----------------------------------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  pinMode(digPin5, OUTPUT);     // pin en modo salida
  pinMode(digPin6, OUTPUT);     // pin en modo salida
  Serial.begin(9600);
  t0=micros();

  valor2 = analogRead(A0);           // Leemos del pin A0 valor
  voltajeinicial = (valor2*5.00/1023.00);   // Calculamos el voltaje
}
//----------------------------------------------------------------------------------------

void loop() {
  // put your main code here, to run repeatedly:
  t=micros();

  if(t - t0 >= Ts){
   
   Planta();
  // printSerial();
    t0 = t;
  }

}

//----------------------------------------------------------------------------------------
//Funciones
void printSerial(){
  Serial.print("Ts: ");
  //Serial.print((t-t0)/1000);
  Serial.println(" [ms]");
}

//----------------------------------------------------------------------------------------

void Planta(){

   pot2= analogRead(A1);
   setpoint=(pot2*5.00/1023.00);
   
    valor = analogRead(A0);           // Leemos del pin A0 valor
    voltaje = (valor*5.00/1023.00);   // Calculamos el voltaje
    Serial.print(" Voltaje: ");
    Serial.print(voltaje);
    Serial.println("V");
    //delay(100);
   error=-k*(setpoint - voltaje);
   PWM=map(abs(error),0,5,0,255);

   if (PWM>=255){
    PWM=255;
   }
        if (error>0){
        digitalWrite(digPin6, HIGH); // asigna el valor HIGH al pin    
        digitalWrite(digPin5, LOW); // asigna el valor LOW al pin
        //delay(100);
        }

        if (error<0){
        digitalWrite(digPin5, HIGH); // asigna el valor HIGH al pin    
        digitalWrite(digPin6, LOW); // asigna el valor LOW al pin   
        //delay(100);
        }

        if (error==0){
        digitalWrite(digPin5, LOW); // asigna el valor HIGH al pin    
        digitalWrite(digPin6, LOW); // asigna el valor LOW al pin   
        //delay(100);
        }
   Serial.print("\n Error: ");
  Serial.print(error);

     Serial.print("   PWM: ");
  Serial.print(PWM);

  Serial.print("   setpoint: ");
  Serial.print(setpoint);
}
