int valor = 0;      // Variable donde almacenaremos el valor del potenciómetro
float voltaje = 0;  // Variable para almacenar el voltaje
void setup() {
  Serial.begin(9600); // Inicializamos la comunicación serial
}
void loop() {
  valor = analogRead(A0);           // Leemos del pin A0 valor
  voltaje = (valor*5.00/1023.00);   // Calculamos el voltaje
  Serial.print("valor analogico: ");
  Serial.print(valor);
  Serial.print(" Voltaje: ");
  Serial.print(voltaje);
  Serial.println("V");
  delay(1000);
}
