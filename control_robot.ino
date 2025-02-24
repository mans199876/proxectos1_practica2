#include "ultrasonidos.cpp"
#include "motores.cpp"

//Inicializamos las variables necesarias para el funcionamiento del coche
int trig1 = 2, trig2 = 4, echo1 = 3, echo2 = 5;
int enableA = 6, in1 = 7, in2 = 8;
int enableB = 9, in3 = 10, in4 = 11;
int velocidad_recta = 150, velocidad_curva = 125;
//Inicializamos los sensores
ultrasonidos ultrasonidos1(trig1, echo1);
ultrasonidos ultrasonidos2(trig2, echo2);

//Inicializamos el coche
coche robot(enableA, enableB, in1, in2, in3, in4);

//Funcion para la demostracion del coche
void demostracion()
{
  robot.moverAdelante(velocidad_recta);
  delay(4000);
  robot.parar();
  delay(1000);
  robot.moverAtras(velocidad_recta);
  delay(4000);
  robot.parar();
  delay(1000);
  robot.moverDerecha(velocidad_curva);
  delay(4000);
  robot.parar();
  delay(1000);
  robot.moverIzquierda(velocidad_curva);
  delay(4000);
  robot.parar();
  delay(1000);
}

//Programa principal del arduino
void setup() {
  // Inicializamos la conexion serie y las clases de control del robot
  Serial.begin(9600);
  ultrasonidos1.iniciar();
  ultrasonidos2.iniciar();
  robot.iniciarCoche();
  //Esta es una espera para poder colocar el robot
  delay(5000);
  //Esta funcion se encarga de mover el robot de la forma indicada en el apartado 2 de la practica
  demostracion();
}

void loop() {
  // Realizamos las meidciones delantera y trasera del robot
  long medicionAdelante = ultrasonidos2.medicion();
  long medicionAtras = ultrasonidos1.medicion();
  //Mostramos por el monitor serie los resultados
  Serial.print("Medicion de distancia delantera: "); Serial.println(medicionAdelante);
  Serial.print("Medicion de distancia trasera: "); Serial.println(medicionAtras);
  //Movemos el robot como se indica en el apartado 3 de la practica.
  if ((medicionAdelante > 50)){
    robot.moverAdelante(velocidad_recta);
  }else if(medicionAtras > 50)
  {
    robot.parar();
    delay(500);
    robot.moverAtras(velocidad_recta);
    delay(1000);
    robot.parar();
    delay(500);
    robot.moverDerecha(velocidad_curva);
    delay(2000);
  }else robot.parar();

}