#include<iostream>
#include "gapbs/src/graph.h"
#include "gapbs/src/benchmark.h"
#include "gapbs/src/builder.h"
#include "gapbs/src/command_line.h"
#include "gapbs/src/pvector.h"

using namespace std;
static int vertex[5] = {1,2,3,4,5};
void __attribute__((noinline)) __attribute__((optimize("O0"))) PIN_Init()
{
    //assert(false); //on successful replacement - this shouldnt be executed
    asm("");
}

/* dummy functions used by pin */
void __attribute__((noinline)) __attribute__((optimize("O0"))) PIN_StartProgram()
{
    //assert(false); //on successful replacement - this shouldnt be executed
    asm("");
}

/* dummy functions used by pin */
void __attribute__((noinline)) __attribute__((optimize("O0"))) PIN_helloWorld(int function_name)
{
    //assert(false); //on successful replacement - this shouldnt be executed
    cout << "hello world from test" << endl;
    asm("");
}


int main(int argc, char* argv[]){
    // Initialize PIN library. Print help message if -h(elp) is specified
    // in the command line or the command line is invalid 
    // PIN_Init();
    int whatever  = 78;
    PIN_helloWorld(whatever);

    char *args[] = {
        (char *)"",
        (char *)"-g",
        (char *)"12"
    };

    CLPageRank cli(3, args, "pagerank", 1e-4, 20);
    cli.ParseArgs();
    Builder g(cli);
    Graph g1 = g.MakeGraph();
    // file_obj.close();
    cout << "g.num_vertices: " << g1.num_nodes()  << " " << g1.num_edges_directed() << endl;


    
    __asm__("nop\nnop\nnop\n");
    cout << "here" << endl;
    
    vertex[0] = vertex[0];
    cout << "here" << endl;
    // cout << (&vertex[0]) << endl;
    __asm__("nop\nnop\nnop\n");
    for(int j = 0; j < int(5); j++){
        for(int i = 0; i < int(5); i++){
            // cout << "here" << endl;
            continue;
        }
    }
    cout << "here" << endl;
    // PIN_helloWorld("hello2");
    // PIN_StartProgram();


    return 0;

}