

#include "my_test.h"


#include "stdint.h"

#include "bike_defs.h"
#include "types.h"



#include "gf2x.h"


pad_r_t c;
pad_r_t a;
pad_r_t b;




void init_data()
{
}



///////////////////////////////////////////////


const char * speed1_name = "gf2x_mod_mul() x 1";

int speed1()
{
  gf2x_mod_mul( &c , &a , &b );

  return 0;
}



const char * speed2_name = "dummy";

int speed2()
{

  return 0;
}




///////////////////////////////////////////////////////

const char * test1_name = "dummy";

const char * test2_name = "dummy";




int test1()
{
  return 0;
}



int test2()
{
  return 0;
}


