

#include "my_test.h"


#include "stdint.h"

#include "bike_defs.h"

#include "sampling.h"
#include "debug.h"
#include "api.h"


#define SIZE_DATA1  ( sizeof(seeds_t) )
#define SIZE_DATA2  ( sizeof(pad_e_t) )




unsigned char data1[SIZE_DATA1] = {0};
unsigned char data2[SIZE_DATA2] = {0};


void init_data()
{
  for(int i=0;i<sizeof(data1);i++) data1[i] = i;
  for(int i=0;i<sizeof(data2);i++) data2[i] = i;
}



///////////////////////////////////////////////


const char * speed1_name = "get_seeds()";

const char * speed2_name = "generate_error_vector((pad_e_t *)error, (const seed_t *)seeds )";



int speed1()
{
  get_seeds( (seeds_t*)data1 );

  return 0;
}


int speed2()
{
  generate_error_vector((pad_e_t *) data2, (const seed_t *)bike_seeds );

  return 0;
}


///////////////////////////////////////////////////////

const char * test1_name = "seeds == x86-seeds ?";
const char * test2_name = "pad_e==x86-pad_e";



static
uint8_t cmp_eq( const uint8_t *v1, const uint8_t *v2, unsigned len )
{
  uint8_t r = 0;
  for(unsigned i=0;i<len;i++) r |= v1[i]^v2[i];
  return 0==r;
}



int test1()
{
  //int r = cmp_eq( data1 , bike_seeds , sizeof(bike_seeds) );
  int r = generate_error_vector((pad_e_t *) data2, (const seed_t *)bike_seeds );
  return r;
}



int test2()
{
  int r = cmp_eq( data2 , bike_error , sizeof(bike_error) );
  return r;
}

