#include "uncore.h"

// uncore
UNCORE uncore;

// constructor
UNCORE::UNCORE() {
    int argn = 3;
    char *args[] = {
        (char *)"",
        (char *)"-g",
        (char *)"15" //hardcoding graph params.
    };
    CLPageRank cli(argn, args, "pagerank", 1e-4, 20);
    cli.ParseArgs();
    Builder b(cli);
    g = b.MakeGraph();
    cout << "uncore.cc: num_nodes" << g.num_nodes() << endl;

    NodeID vtxPerLine    = 64 / sizeof(float);
    NodeID numCacheLines = (g.num_nodes() + vtxPerLine - 1) / vtxPerLine;
    NodeID numEpochs     = 256;
    
    //creating offset matrix (same as in application)
    pvector<uint8_t> offsetMatrix(numCacheLines * numEpochs);
    b.makeOffsetMatrix(g, offsetMatrix, vtxPerLine, numEpochs, true);

    //can be accessed as uncore.LLC.offset_matrix in the replacement code.
    LLC.offset_matrix[0] = offsetMatrix.data();
    LLC.num_epochs[0]             = numEpochs;
    LLC.num_clines[0]             = numCacheLines;
    LLC.vtx_per_line[0]           = vtxPerLine;

}

