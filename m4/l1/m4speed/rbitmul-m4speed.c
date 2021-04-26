

#include "my_test.h"


#include "stdint.h"

#include "bike_defs.h"



#define SIZE_DATA1  ( R_PADDED_BYTES )
#define SIZE_DATA2  ( R_PADDED_BYTES )




unsigned char data1[SIZE_DATA1] = {0};
unsigned char data2[SIZE_DATA2] = {0};
unsigned char data3[SIZE_DATA2] = {0};
uint16_t sk[D] = {0};



void init_data()
{
  for(int i=0;i<sizeof(data1);i++) data1[i] = i;
  for(int i=0;i<sizeof(data2);i++) data2[i] = i;
  for(int i=0;i<D;i++) sk[i] = i%R_BITS;
}



///////////////////////////////////////////////


const char * speed1_name = "gf2x_mod_mul x 1 : R_PADDED_BYTES (2048bytes?)";

const char * speed2_name = "mul with rotate";


#include "gf2x.h"

int speed1()
{
// c = a*b mod (x^r - 1)
//void gf2x_mod_mul(OUT pad_r_t *c, IN const pad_r_t *a, IN const pad_r_t *b);
  gf2x_mod_mul( (void*)data3 , (void*)data1 , (void*) data2 );

  return 0;
}


#include "rot_mul.h"


int speed2()
{
//mul(uint32_t out[NBLOCKS], uint32_t in[NBLOCKS], uint16_t sk[SYS_W]);
  mul( (void*)data3 , (void*)data1 , sk );

  return 0;
}


///////////////////////////////////////////////////////

const char * test1_name = "dummy";

const char * test2_name = "dummy";




int test1()
{
  unsigned char r = 0;
  return r;
}



int test2()
{
  return 0;
}


