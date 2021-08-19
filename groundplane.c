/*
Lambda/4 Groundplane Antanna Calculator
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
#include "groundplane.h"

void gp_calc(float *f, float *unit_factor, float *lambda, float *l1, float *l2){
    *lambda = ( 29971000 / *f ) / 100;
    *l1 = (0.96 * *lambda * 0.25) * *unit_factor;
    *l2 = (0.96 * *lambda * 0.28) * *unit_factor;
}

void gp_print(float *f, float *unit_factor, float *lambda, float *l1, float *l2, int *unit_index){
    printf(" Calculated for %f mHz\n", *f);
    printf("\n");
    printf("   Vertical Radiator %f ", *l1); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
    printf("             Radials %f ", *l2); switch(*unit_index){ case 1: printf("mm\n"); break; case 2: printf("inch\n"); break; };
    printf("\n");
    printf("\n");
    printf("                           O\n");
    printf("                           I\n");
    printf("                           I\n");
    printf("                 Radiator  I\n");
    printf("                           I\n");
    printf("                           I\n");
    printf("                           I\n");
    printf("                           I\n");
    printf("                        ___|___         \n");
    printf("                       /'  |  '\\       \n");
    printf("                       \\.__|__./       \n");
    printf("                      /|  50   |\\      \n");
    printf("                     / |  Ohm  | \\     \n");
    printf("            Radial  /  ~~~~~~~~~  \\    \n");
    printf("                   /               \\   \n");
    printf("                  /                 \\  \n");
    printf("\n");
    printf("                3 - 6 radials are usual \n");
    printf("\n");
}
