#include "MKL25Z4.h"
#include "segmentos.h"
int pin[7] = {0, 1, 2, 3, 4, 5, 6};
int numero[10][8] =
{

  { 1, 1, 1, 1, 1, 1, 0, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1, 0 }, // 2
  { 1, 1, 1, 1, 0, 0, 1, 0 }, // 3
  { 0, 1, 1, 0, 0, 1, 1, 0 }, // 4
  { 1, 0, 1, 1, 0, 1, 1, 0 }, // 5
  { 1, 0, 1, 1, 1, 1, 1, 0 }, // 6
  { 1, 1, 1, 0, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1, 0 }, // 8
  { 1, 1, 1, 0, 0, 1, 1, 0 }  // 9
};


void Seg_Int()
{
	SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
	for(int i = 0; i < 10; i++){
		PORTD->PCR[pin[i]]|=(1<<8);
		PTD->PDDR|=(1<<pin[i]);
		PTD->PCOR|=(1u<<pin[i]);
	}
}

void Segmentos(int num)
{
	for(int i = 0; i < 8; i++){
		if(numero[num][i] == 0){
			PTD->PCOR|=(1u<<pin[i]);
		} else {
			PTD->PSOR|=(1u<<pin[i]);
		}
	}
}
