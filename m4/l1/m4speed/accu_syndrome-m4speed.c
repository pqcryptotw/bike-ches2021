

#include "my_test.h"


#include "stdint.h"

#include "bike_defs.h"
#include "types.h"




#include "decode.h"
#include "cleanup.h"
#include "utilities.h"

#include "rotate_cmov.h"



syndrome_t rotated_syndrome = {0};
upc_t upc;


syndrome_t _syndrome;
syndrome_t * syndrome = & _syndrome;
compressed_idx_d_ar_t wlist;


void init_data()
{
  memset(&upc, 0, sizeof(upc));
  for(int i=0;i<D;i++) wlist[0].val[i] = i;
}



///////////////////////////////////////////////


//void accumulate_unsat_syndrome(OUT upc_t *_upc,
//                               IN OUT syndrome_t *rotated_syndrome,
//                               IN const idx_t *wlist_val,
//                               IN const syndrome_t *syndrome)



const char * speed1_name = "accu symdrome x 1";

int speed1()
{
  accumulate_unsat_syndrome( &upc , &rotated_syndrome , &wlist , syndrome );

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


