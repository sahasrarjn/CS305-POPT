#ifndef APP_DATA_H_
#define APP_DATA_H_

#include <iostream>
#include <stdlib.h>

struct app_data_format{
    int info_type; // function to be called among registerDataType, updateIrregRanges etc
    intptr_t addr; // start address for the registerDataType function
    int dType; // datatype being registered for registerDataType
    int numElements; // number of elements to be registered  in registerDataType
    size_t elemSz; // size of each element being registered
    int totalDataTypes; // Data types : {REGDATA, IRREGDATA, FRONTIER, ...}

    // for updateRegIndex
    int32_t index;  // node index for currVertex

    // for updateIrregRanges
    int32_t startID; // Base
    int32_t endID; // Bound

    int32_t simulateAccesses; // use LLC only for irregular data

    // default values for above variables to avoid any errors
    app_data_format(){
      info_type = -1;
      addr = 0;
      dType = 0;
      numElements = 0;
      elemSz = 0;
      totalDataTypes = 0;
      
      startID = 0;
      endID = 0;
      index = 0;
      simulateAccesses = 0;
    }
};

#endif