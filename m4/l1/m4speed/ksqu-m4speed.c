

#include "my_test.h"


#include "stdint.h"

#include "bike_defs.h"
#include "types.h"


#define SIZE_DATA1  ( R_PADDED_BYTES )
#define SIZE_DATA2  ( R_PADDED_BYTES )




unsigned char data1[SIZE_DATA1] = {0};
unsigned char data2[SIZE_DATA2] = {0};



void init_data()
{
  for(int i=0;i<sizeof(data1);i++) data1[i] = i;
  for(int i=0;i<sizeof(data2);i++) data2[i] = i;
}



///////////////////////////////////////////////

#define _GF2X_

#if defined(_GF2X_)
const char * speed1_name = "gf2x_mod_sqr x 64";
#else
const char * speed1_name = "ring_squ x 64";
#endif

const char * speed2_name = "k squ x 1";


#include "gf2x_internal.h"


// c = a^2^2^num_sqrs
_INLINE_ void repeated_squaring(OUT pad_r_t *c,
                                IN pad_r_t *    a,
                                IN const size_t num_sqrs,
                                OUT dbl_pad_r_t *sec_buf)
{
  c->val = a->val;

  for(size_t i = 0; i < num_sqrs; i++) {
#if defined(_GF2X_)
    gf2x_mod_sqr_in_place(c, sec_buf);
#else
    ring_squ(c , c);
#endif
  }
}



int speed1()
{
  dbl_pad_r_t buf;
  repeated_squaring( (pad_r_t*)data2, (pad_r_t*)data1, 64 , &buf );

  return 0;
}



int speed2()
{

  k_squaring( (pad_r_t*)data2, (pad_r_t*)data1, 5717 );

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


