#include <stdio.h>
#include "jpole.h"



void jpole_calc(float *f, float *unit_factor, float *lambda, float *l1, float *l2, float *l3, float *l4, float *raddiam){
    *lambda = ( 29971000 / *f ) / 100;
    *l1 = (0.96 * *lambda * 0.75) * *unit_factor;
    *l2 = (0.96 * *lambda * 0.25) * *unit_factor;
    *l3 = (0.96 * *lambda * 0.025) * *unit_factor;
    *l4 = (0.96 * *lambda * 0.026) * *unit_factor;
    *raddiam = (0.96 * *lambda * 0.01) * *unit_factor;
}

void jpole_print(float *f, float *unit_factor, float *lambda, float *l1, float *l2, float *l3, float *l4, float *raddiam, int *unit_index){
	printf(" Calculated for %f MHz\n", *f);
        printf("\n");
	printf("         Radiator Diam. is %f ", *raddiam); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
	printf("\n");
	printf("\n");
	printf("         [   ||\n");
	printf("         [   ||\n");
	printf("         [   ||\n");
	printf("         [   ||\n");
	printf("         [   ||\n");
	printf("         [   ||\n");
	printf("         [   ||\n");
	printf("         [L1 || %f ", *l1); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
	printf("         [   ||\n");
	printf("         [   ||\n");
	printf("         [   ||                       ||       ]\n");
	printf("         [   ||                       ||       ]\n");
	printf("         [   ||                       ||       ]\n");
	printf("         [   ||                       ||     L2]%f ", *l2); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
	printf("         [   ||      ______           ||       ]\n");
	printf("         [   ||     /   ___|___       ||       ]\n");
	printf("         [   ||____/   /'  |  '\\______||       ]\n");
	printf("         [   ||        \\.__|__./      ||    ]  ]\n");
	printf("         [   ||        |  50   |      ||  L4]  ]%f ", *l4); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
	printf("         [   ||        |  Ohm  |      ||    ]  ]\n");
	printf("         [   ||        ~~~~~~~~~      ||    ]  ]\n");
	printf("         [   ||                       ||    ]  ]\n");
	printf("              ========================= \n");
	printf("                        L3 %f ", *l3); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
	printf("\n");
	printf("\n");
	printf("\n");
}
