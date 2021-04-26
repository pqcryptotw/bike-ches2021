

#include "my_test.h"


#include "stdint.h"



#define SIZE_DATA1  ( 4*32 )
#define SIZE_DATA2  ( 4*32 )




unsigned char data1[SIZE_DATA1] = {0};
unsigned char data2[SIZE_DATA2] = {0};



void init_data()
{
  for(int i=0;i<sizeof(data1);i++) data1[i] = i;
  for(int i=0;i<sizeof(data2);i++) data2[i] = i;
}



///////////////////////////////////////////////


const char * speed1_name = "transpose_32x32_in() x 32";

const char * speed2_name = "new transpose_32x32_in() x 32";


#include "transpose.h"

int speed1()
{
  for(int i=0;i<32;i++) transpose_32x32_in( data1 );

  return 0;
}



int speed2()
{
  for(int i=0;i<32;i++) transpose_32x32_in2( data2 );

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


