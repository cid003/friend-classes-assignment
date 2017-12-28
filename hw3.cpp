#include "university.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


//----------------------------------------------------------------------------

int main() 
{
  University csusm;
  csusm.ProcessTransactionFile("transactionfile.txt");
  //do other stuff here to list everything?

  return 0;
}
//----------------------------------------------------------------------------
