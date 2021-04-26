

#include "my_test.h"


#include "stdint.h"


#define SIZE_DATA1  ( 32 )




uint32_t data0[SIZE_DATA1] = {0};
uint32_t data1[SIZE_DATA1] = {0};
uint32_t data2[SIZE_DATA1] = {0};



void init_data()
{
  for(int i=0;i<SIZE_DATA1;i++) data1[i] = 0x12345678*(i+1);
}



///////////////////////////////////////////////


const char * speed1_name = "x v17 C code";

const char * speed2_name = "x v17 ASM code";



int speed1()
{
  gft_mul_v17_C( data1 , data0 );

  return data1[0];
}



int speed2()
{
  gft_mul_v17( data2 , data0 );

  return data2[0];
}


///////////////////////////////////////////////////////

const char * test1_name = "test equal?";

const char * test2_name = "dummy";


static
uint32_t cmp( const uint32_t * vec1, const uint32_t * vec2, int len )
{
  uint32_t r = 0;
  for(int i=0;i<len;i++) r |= vec1[i]^vec2[i];
  return r;
}


int test1()
{
  speed1();
  speed2();

  uint32_t r = cmp( data1 , data2 , SIZE_DATA1 );

  return r;
}



int test2()
{
  return 0;
}


