#include <stdio.h>
#include <stdlib.h>

#include "headers/sonde.h"

#define true 1
#define false 0

t_sonde* init_sonde() {
	t_sonde* sonde = malloc(sizeof(t_sonde));
	sonde->x = 0;
	sonde->y = 0;
	sonde->a_tire = false;
	return sonde;
}