

#include "my_test.h"


#include "stdint.h"




#define SIZE_DATA1  (32)
#define SIZE_DATA2  (32)




uint32_t data1[SIZE_DATA1] = {0};
uint32_t data2[SIZE_DATA2] = {0};
uint32_t data3[SIZE_DATA2] = {0};




void init_data()
{
  for(int i=0;i<sizeof(data1)/4;i++) data1[i] = i;
  for(int i=0;i<sizeof(data1)/4;i++) data2[i] = i;
}


#include "gfv_tower_asm.h"

///////////////////////////////////////////////


const char * speed1_name = "gf232v_mul_gf16_asm";

const char * speed2_name = "gf232v_mul_gf256_asm";

//const char * speed1_name = "gf232v_mul_gf216_asm";

//const char * speed2_name = "gf232v_mul_asm";



int speed1()
{

  gf232v_mul_gf16_asm( data3 , data2 , data1 );
  //gf232v_mul_gf216_asm( data3 , data2 , data1 );
  return 0;
}



int speed2()
{
  gf232v_mul_gf256_asm( data3 , data2 , data1 );
  //gf232v_mul_asm( data3 , data2 , data1 );

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



