/*
Libreria para el control de motores con diferentes puentes H
Creada por Manuel Fernandez Uceira el 06/02/2025
Ultima modificacion: 06/02/2025 12:47
*/

#include <arduino.h>

class l298N{
  private:
    
    
  public:
  int enableA, enableB, in1, in2, in3, in4;
    l298N(){}
    l298N(int EnableA, int EnableB, int IN1, int IN2, int IN3, int IN4){
        enableA = EnableA;
        enableB = EnableB;
        in1 = IN1;
        in2 = IN2;
        in3 = IN3;
        in4 = IN4;
    }

    void initMotor1()
    {
        pinMode(in1, OUTPUT);
        pinMode(in2, OUTPUT);
        pinMode(enableA, OUTPUT);

        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enableA, 0);
    }
    
    void initMotor2()
    {
        pinMode(in3, OUTPUT);
        pinMode(in4, OUTPUT);
        pinMode(enableB, OUTPUT);

        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        analogWrite(enableB, 0);
    }
};

class coche : public l298N
{
    public:
    coche(){}
    coche(int EnableA, int EnableB, int IN1, int IN2, int IN3, int IN4)
    {
      enableA = EnableA;
      enableB = EnableB;
      in1 = IN1;
      in2 = IN2;
      in3 = IN3;
      in4 = IN4;
    }
    //Funcion para iniciar  los motores del coche
    void iniciarCoche()
    {
      initMotor1();
      initMotor2();
    }

    //Funciones de movimiento
    void moverAdelante(int velocidad)
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enableA, velocidad);
        analogWrite(enableB, velocidad);
    }
    void moverAtras(int velocidad)
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(enableA, velocidad);
        analogWrite(enableB, velocidad);
    }

    void moverDerecha(int velocidad)
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enableA, velocidad);
        analogWrite(enableB, velocidad);
    }
    void moverIzquierda(int velocidad)
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enableA, velocidad);
        analogWrite(enableB, velocidad);
    }

    //Funcion para parar el coche
    void parar()
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        analogWrite(enableA, 0);
        analogWrite(enableB, 0);
    }
    private:

};
