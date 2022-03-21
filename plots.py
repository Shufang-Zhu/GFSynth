import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc
from matplotlib.lines import Line2D
import math

def getlines(filename):
    file_handle = open(filename, 'r')
    lines_list = file_handle.readlines()
    return lines_list



def plotdec2(vals, name, legend):
    rc('font', **{'family': 'serif', 'serif': ['Helvetica'], 'size': 16})
    rc('text', usetex=True)


    data = vals
    fig, ax = plt.subplots()

    workstation_resupply_x_label = ['1', '2', '3', '4', '5']
    finding_nemo_x_label = ['1', '2', '3', '4']
    ax.set_ylabel('Runnning time (seconds)', fontsize=24)
    plt.yscale('log')
    # print(name)

    if "workstation" in name:
    	xvalue = [1, 2, 3, 4, 5]
    	xticklables = ['1', '2', '3', '4', '5']
    	plot_name = "workstation_resupply"
    	ax.set_xlabel("\#Number of stations", fontsize=24)
    	
    else:
    	xvalue = [1, 2, 3, 4]
    	xticklables = ['1', '2', '3', '4']
    	plot_name = "finding_nemo"
    	ax.set_xlabel("\#Number of sections", fontsize=24)
    ax.set_xticks(xvalue)
    ax.set_xticklabels(xticklables)

    
    ax.plot(xvalue, data[1], '*--', linewidth=3, markersize=12, color="blue", label="Strix")
    ax.plot(xvalue, data[0], 'o-', linewidth=3, markersize=12, color="purple", label="GFSynth")
    
    ax.legend()
    plt.legend(loc='upper left')

    # plt.show()

    fig.savefig(plot_name + ".pdf", bbox_inches='tight')

    # plt.show()

def strix_collect_data(benchmark_name):
    benchmark_folder = "result/Strix/"+benchmark_name+"/"
    res = []
    if "workstation" in benchmark_name:
    	range_value = range(1, 6)
    else:
    	range_value = range(1, 5)
    for i in range_value:
        result_file = benchmark_folder+str(i)+".res"
        lines = getlines(result_file)
        result = lines[len(lines)-1].strip('\n')
        if "Strix" not in result:
            time = 7200
        else:
            substrs = result.split(' ')
            time = (float(substrs[-2]))
        res.append(time)
    return  res

def syft_collect_data(benchmark_name):
    benchmark_folder = "result/Gfsynth/" + benchmark_name + "/"
    res = []
    if "workstation" in benchmark_name:
    	range_value = range(1, 6)
    else:
    	range_value = range(1, 5)
    for i in range_value:
        result_file = benchmark_folder + str(i) + ".res"
        lines = getlines(result_file)
        result = lines[len(lines) - 1].strip('\n')
        if "Total" not in result:
            time = 7200
        else:
            substrs = result.split(' ')
            time = float(substrs[-2])
            time = (time / 1000)
        res.append(time)
    return res


if __name__ == '__main__':
    benchmark_name = "workstation_resupply"
    syft_data = syft_collect_data(benchmark_name)
    print(syft_data)
    strix_data = strix_collect_data(benchmark_name)
    vals = []
    vals.append(syft_data)
    vals.append(strix_data)
    plotdec2(vals, "workstation\_resupply", True)

    benchmark_name = "finding_nemo"
    syft_data = syft_collect_data(benchmark_name)
    strix_data = strix_collect_data(benchmark_name)
    vals = []
    vals.append(syft_data)
    vals.append(strix_data)
    plotdec2(vals, "finding\_nemo", True)
