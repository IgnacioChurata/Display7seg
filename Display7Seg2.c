#include "MKL25Z4.h"
#include "segmentos.h"
int pin[7] = {0, 1, 2, 3, 4, 5, 6};
int main(void) {
	Seg_Int();
	while (1){
		for(int i = 0; i < 10; i++){
			Segmentos(i);
			for(int i = 0; i < 700000; i++);
		}
	}


return 0 ;
}
