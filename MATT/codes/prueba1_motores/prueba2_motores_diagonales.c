/* En este código se intentará probar el movimiento de diagonales de los motores.

Debe de hacer: 
1-Diag arriba derecha 
2-alto 
3-diag sup izquierda
4-alto 
5-diag abajo derecha 
6-alto 
7-diag abajo izquierda 
8-alto 
9-repetir 

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

//Diagonales
void moverDiagonalSupDer(void);
void moverDiagonalSupIzq(void);
void moverDiagonalInfDer(void);
void moverDiagonalInfIzq(void);

//parar
void detenerX(void);
void detenerY(void);
void detenerTodo(void);

int main(void)
{
    motoresInit();

    while(1)
    {
        //diag arriba derecha
        moverDiagonalSupDer();
        delayMs(2000);

        detenerTodo();
        delayMs(1000);

        //diag arriba izquierda
        moverDiagonalSupIzq();
        delayMs(2000);

        detenerTodo();
        delayMs(1000);

        //diag abajo derecha
        moverDiagonalInfDer();
        delayMs(2000);

        detenerTodo();
        delayMs(1000);

        //diag abajo izquierda
        moverDiagonalInfIzq();
        delayMs(2000);

        detenerTodo();
        delayMs(2000);
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
    PTB->PSOR = (1<<0);
    PTB->PCOR = (1<<1);
}

void moverIzquierda(void)
{
    PTB->PCOR = (1<<0);
    PTB->PSOR = (1<<1);
}

void detenerX(void)
{
    PTB->PCOR = (1<<0);
    PTB->PCOR = (1<<1);
}


void moverArriba(void)
{
    PTB->PSOR = (1<<2);
    PTB->PCOR = (1<<3);
}

void moverAbajo(void)
{
    PTB->PCOR = (1<<2);
    PTB->PSOR = (1<<3);
}

void detenerY(void)
{
    PTB->PCOR = (1<<2);
    PTB->PCOR = (1<<3);
}

//DIAGONALES

void moverDiagonalSupDer(void)
{
    moverDerecha();
    moverArriba();
}

void moverDiagonalSupIzq(void)
{
    moverIzquierda();
    moverArriba();
}

void moverDiagonalInfDer(void)
{
    moverDerecha();
    moverAbajo();
}

void moverDiagonalInfIzq(void)
{
    moverIzquierda();
    moverAbajo();
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