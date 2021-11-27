import os
import matplotlib.pyplot as plt
import numpy as np

data = ["Coverage wrt LRU"] 
where = [(22, 7)]
prog = ["srrip", "drrip", "popt"]
graph = ["graph_15_100",]
base = "{}.trace.xz-bimodal-no-no-no-no-{}-1core.txt"

result = np.zeros((len(data), len(prog), len(graph)))

if __name__ == "__main__":
    os.makedirs("images/", exist_ok=True)

    for i, g in enumerate(graph):
        with open(base.format(g, "lru")) as f:
            lines = f.readlines()
            popt_miss = float(lines[where[0][0]].split()[where[0][1]])

        for j, p in enumerate(prog):
            filename = base.format(g, p)
            with open(filename, "r") as f:
                lines = f.readlines()
                for k, d in enumerate(data):
                    miss = float(lines[where[k][0]].split()[where[k][1]])
                    result[k][j][i] = abs((popt_miss - miss) / popt_miss)

    for i, d in enumerate(data):
        barWidth = 0.1
        gap = 0.2
        fig = plt.subplots(figsize =(6, 4))

        for j, p in enumerate(prog):
            plt.bar(j*(barWidth+gap), result[i][j][0], barWidth, label=p)

        plt.xlabel('policies', fontweight='bold')
        plt.ylabel(d, fontweight='bold')
        plt.xticks([(barWidth+gap)*i for i in range(len(prog))], prog)
        plt.savefig(f"images/{d}.png")
        
        