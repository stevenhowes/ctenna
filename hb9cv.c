/*
Reference: https://de.wikipedia.org/wiki/HB9CV-Antenne
The HB9CV antenna is related with the "ZL-Special"

HB9CV Antanna Calculator
Copyright (C) 2021  Thomas Kummer
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include "hb9cv.h"
/*
void printunits (int *unit_index){
    switch(*unit_index){
    	case 1: printf("mm\n"); break;
    	case 2: printf("inch\n"); break;
    }
}
*/

void hb9cv_calc (float *f, float *unit_factor, float *lambda, float *l1, float *l2, float *l3, float *l4, float *l5, float *bdiam, float *raddiam){
    *lambda = ( 30000000 / *f) / 100;
    *l1 = (( 0.92 * *lambda * 5) / 10) * *unit_factor;
    *l2 = (( *lambda * 5) / 10) * *unit_factor;
    *l3 = (( *lambda * 1.25) / 10) * *unit_factor;
    *l4 = (( *lambda * 1.25) / 20) * *unit_factor;
    *l5 = (( *lambda * 1.35) / 20) * *unit_factor;
    *bdiam = ( *lambda * 0.0072) * *unit_factor;
    *raddiam = ( *lambda * 0.0036) * *unit_factor;
}

void hb9cv_print (float *f, float *unit_factor, float *lambda, float *l1, float *l2, float *l3, float *l4, float *l5, float *bdiam, float *raddiam, int *unit_index){
    printf(" Calculated for %f mHz\n", *f);
    printf("\n");
    printf(" Lambda is %f mm\n", *lambda);
    printf(" L1 Driven Element is %f ", *l1); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
    printf(" L2 Reflector is %f ", *l2); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
    printf(" L3 element spaceing is %f ", *l3); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
    printf(" L4 Matching on dr. element is %f ", *l4); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
    printf(" L5 Matching on reflector is %f ", *l5); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
    printf(" Boom Diam. is %f ", *bdiam); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
    printf(" Radiator Diam. is %f ", *raddiam); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
    printf("\n");
    printf("  connect feed on this side \n");
    printf("  --------------------------L1 \n");
    printf("          L4|--\\| \n");
    printf("               || \n");
    printf("              L3| \n");
    printf("                || \n");
    printf("                | \\--|L5 \n");
    printf(" ----------------------------L2 \n");
    printf("\n");
    printf("\n");
    printf(" ===============================================\n");
    printf("                        || \\     |\n");
    printf("                        || C1 ___\\______\n");
    printf("                        ||  \\____/   ___|__\n");
    printf("                        ||   |      /'  |  '\\ \n");
    printf("                        ||---)------\\.__|__./\n");
    printf("                        ||   |      |  50   |\n");
    printf("                        ||   |      |  Ohm  |\n");
    printf("\n");
    printf(" C1 10m-Band 50pF 6m-Band 30pF 2m band 12pF \n");
    printf("\n");
    printf("\n");
}




