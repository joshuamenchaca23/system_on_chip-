/* En este código lo que se busca implementar es probar los movimientos básicos de 
los motores de MATT, izquierda, derecha, calibrar y probar el movimiento con las 
llantas ominidireccionales 

Debe de hacer: derecha, izquieda, arriba, abajo y repetirlo

Autor: Joshua Menchaca 
Fecha: 17/05/26 */


#include "MKL25Z4.h"

void delayMs(int n);


void motoresInit(void);

//x
void moverDerecha(void);
void moverIzquierda(void);

//y
void moverArriba(void);
void moverAbajo(void);

//parar
void detenerX(void);
void detenerY(void);
void detenerTodo(void);

int main(void)
{
    motoresInit();

    while(1)
    {
        //mover derecha
        moverDerecha();
        delayMs(2000);
        detenerTodo();
        delayMs(1000);

        //mover izquierda
        moverIzquierda();
        delayMs(2000);
        detenerTodo();
        delayMs(1000);

        /mover arriba
        moverArriba();
        delayMs(2000);
        detenerTodo();
        delayMs(1000);

        //mover abajo
        moverAbajo();
        delayMs(2000);
        detenerTodo();
        delayMs(1000);
    }
}

void motoresInit(void)
{
    //reloj
    SIM->SCGC5 |= 0x400;

    //PTB0-PTB3
    PORTB->PCR[0] = 0x100;
    PORTB->PCR[1] = 0x100;
    PORTB->PCR[2] = 0x100;
    PORTB->PCR[3] = 0x100;

    //outs
    PTB->PDDR |= (1<<0);
    PTB->PDDR |= (1<<1);
    PTB->PDDR |= (1<<2);
    PTB->PDDR |= (1<<3);

    detenerTodo();
}

//movimientos de x 

void moverDerecha(void)
{
    //Motor X adelante
    PTB->PSOR = (1<<0);
    PTB->PCOR = (1<<1);
}

void moverIzquierda(void)
{
    //Motor X reversa
    PTB->PCOR = (1<<0);
    PTB->PSOR = (1<<1);
}

void detenerX(void)
{
    PTB->PCOR = (1<<0);
    PTB->PCOR = (1<<1);
}

//movimientos de y 

void moverArriba(void)
{
    // Motor Y adelante
    PTB->PSOR = (1<<2);
    PTB->PCOR = (1<<3);
}

void moverAbajo(void)
{
    // Motor Y reversa
    PTB->PCOR = (1<<2);
    PTB->PSOR = (1<<3);
}

void detenerY(void)
{
    PTB->PCOR = (1<<2);
    PTB->PCOR = (1<<3);
}

//alto todooo

void detenerTodo(void)
{
    detenerX();
    detenerY();
}


void delayMs(int n)
{
    int i;
    int j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 7000; j++)
        {
        }
    }
}