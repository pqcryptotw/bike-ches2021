

#include "my_test.h"


#include "stdint.h"

#include "bike_defs.h"
#include "types.h"



#include "ring_ops.h"


pad_r_t c;
pad_r_t a;
pad_r_t b;
mul_internal_t b_fft;




void init_data()
{
}



///////////////////////////////////////////////


const char * speed1_name = "ring_mul() x 1";

int speed1()
{
  ring_mul( &c , &a , &b );

  return 0;
}



const char * speed2_name = "ring_mul_2() x 1";

int speed2()
{
  ring_mul_2( &c , &a , &b_fft );

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


