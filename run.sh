#provide the policies that you want to run as arguments (popt, lru, drrip, srrip) (ship takes too long to run)
./build_champsim.sh bimodal no no no no $1 1
./run_champsim.sh bimodal-no-no-no-no-$1-1core 10 20 graph_15_100.trace.xz

./build_champsim.sh bimodal no no no no $2 1
./run_champsim.sh bimodal-no-no-no-no-$2-1core 10 20 graph_15_100.trace.xz

./build_champsim.sh bimodal no no no no $3 1
./run_champsim.sh bimodal-no-no-no-no-$3-1core 10 20 graph_15_100.trace.xz

./build_champsim.sh bimodal no no no no $4 1
./run_champsim.sh bimodal-no-no-no-no-$4-1core 10 20 graph_15_100.trace.xz


