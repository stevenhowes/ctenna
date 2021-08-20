/*
ctenna - a multi antenna calulator for console, written in C
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
#include "jpole.h"
#include "groundplane.h"
//#include <stdlib.h>

void clear_scr(void){
	printf("\033[H");  //brings cursor home
	printf("\x1b[2J"); //clears screen
}

void printunit (int *unit_index){ // prints the selected unit
    switch(*unit_index){
    	case 1: printf("mm"); break;
    	case 2: printf("inch"); break;
    }
}

void myflush ( FILE *in )
{
  int ch;

  do
    ch = fgetc ( in );
  while ( ch != EOF && ch != '\n' );

  clearerr ( in );
}

void mypause ( void )
{
  printf ( "Press [Enter] to continue . . ." );
  fflush ( stdout );
  getchar();
}

void set_freq(float *f){ // change the MHz
    float input;
    printf("Please input an f in MHz value: e.G. 432.2 \n");
    scanf("%f", &input);
    *f = input;
    printf("\n");
}

void set_units_system(float *unit_factor ,int *unit_index ){ // change betweenn units
    int input;
    printf("Please choose (1)Metric or (2)Imperial units \n");
    scanf("%i", &input);
    *unit_index = input;
    printf("\n");
    switch(*unit_index){
    	case 1: *unit_factor = 1; break; // for metric
    	case 2: *unit_factor = 0.039; break; // for inch
    	default: *unit_factor = 1; *unit_index = 1;  printf("Invalid input! Guessing! \n"); printf("\n"); break; // a fool, ... we go metric
    }
}

void main_menu(float *f, int *unit_index){
	printf("\n");
	printf("===========================================================\n");
	printf("--                       MAIN MENU                       --\n");
	printf("===========================================================\n");
	printf("-- (1) Set Frequncy in MHz  %f \n", *f);
	printf("\n");
	printf("-- (2) Choose units system  ( set to: "); printunit(&*unit_index); printf(" )\n");
	printf("\n");
	printf("--= Omnidirectional Antennas =--\n");
	printf("\n");
    printf("-- (3) J-pole antenna\n");
	printf("\n");
	printf("-- (4) Groundplane\n");
	printf("\n");
	printf("--= Directional Antennas =--\n");
	printf("\n");
    printf("-- (5) HB9CV antenna\n");
   	printf("\n");
	printf("-----------------------------------------------------------\n");
    printf("-- (0) Quit                                              --\n");
	printf("-----------------------------------------------------------\n");
	}

int menu_select(){
    int input;
    printf("Enter your choice: ");
    scanf("%i",&input);
    return input;
}

int main(){

    float f = 435,unit_factor = 1, lambda, l1, l2, l3, l4, l5, bdiam, raddiam; //startup with a 70cm QRG and metric system
    int main_menu_sel = -1, unit_index = 1;

    while (main_menu_sel != 0){ // main menu loop runs until "0" for quit

        main_menu(&f, &unit_index); //prints menu
        main_menu_sel = menu_select(); 


        switch(main_menu_sel){

	    case 0: return 0;
            case 1: clear_scr();set_freq(&f);
                    break;
            case 2: clear_scr();set_units_system(&unit_factor ,&unit_index );
                    break;
            case 3: clear_scr();
                    jpole_calc(&f, &unit_factor,&lambda, &l1, &l2, &l3, &l4, &raddiam);
                    jpole_print(&f ,&unit_factor, &lambda, &l1, &l2, &l3, &l4, &raddiam, &unit_index);
                    myflush ( stdin );
                    mypause();
                    break;
            case 4: clear_scr();
                    gp_calc(&f, &unit_factor,&lambda, &l1, &l2);
                    gp_print(&f ,&unit_factor, &lambda, &l1, &l2, &unit_index);
                    myflush ( stdin );
                    mypause();
                    break;
            case 5: clear_scr();
                    hb9cv_calc(&f ,&unit_factor, &lambda, &l1, &l2, &l3, &l4, &l5, &bdiam, &raddiam);
                    hb9cv_print(&f ,&unit_factor, &lambda, &l1, &l2, &l3, &l4, &l5, &bdiam, &raddiam, &unit_index);
                    myflush ( stdin );
                    mypause();
                    break;
            default:printf("And then?");return 1; //maybe easteregg in future
    	}
    }
    clear_scr();
    printf("\n");
    printf(" 73! \n");
    printf("\n");
    return 0;
}
