

#include "my_test.h"


#include "stdint.h"

#include "bike_defs.h"
#include "types.h"
#include "decode.h"

#define SIZE_DATA1  ( sizeof(syndrome_t) )
#define SIZE_DATA2  ( sizeof(syndrome_t) )




unsigned char data1[SIZE_DATA1] = {0};
unsigned char data2[SIZE_DATA2] = {0};
unsigned char data3[SIZE_DATA2] = {0};



void init_data()
{
  for(int i=0;i<sizeof(data1);i++) data1[i] = i;
  for(int i=0;i<sizeof(data2);i++) data2[i] = i;
}



///////////////////////////////////////////////


#if 0
const char * speed1_name = "rotate_right_u32 x 1";

int speed1()
{
  rotate_right_u32( (syndrome_t*) data2 , (syndrome_t*) data1 , 12322 );

  return 0;
}
#else

#include "rotate_cmov.h"

const char * speed1_name = "rotate_cmov_right x 1";

int speed1()
{
  rotate_cmov_right( (syndrome_t*) data2 , (syndrome_t*) data1 , 12322 );

  return 0;
}


#endif





#if 0
const char * speed2_name = "rotate_right x 1";
//const char * speed2_name = "rotate_right_u32_2 x 1";

int speed2()
{
  rotate_right( (syndrome_t*) data3 , (syndrome_t*) data1 , 12322 );
  //rotate_right_u32_2( (syndrome_t*) data3 , (syndrome_t*) data1 , 12322 );

  return 0;
}
#elif 1
const char * speed2_name = "rotr_cshift x 1";

int speed2()
{
  rotr_cshift( (uint32_t*) data3 , (uint32_t*) data1 , 12322 );
  //rotate_right_u32_2( (syndrome_t*) data3 , (syndrome_t*) data1 , 12322 );

  return 0;
}
#else
const char * speed2_name = "dummy";

int speed2()
{
  return 0;
}

#endif

///////////////////////////////////////////////////////

const char * test1_name = "test 2 rotate equal?";

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

  uint32_t r = cmp( data2 , data3 , R_QWORDS*2 );

  return r;
}



int test2()
{
  return 0;
}


