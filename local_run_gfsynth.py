import os
import sys


if __name__ == '__main__':
    for benchmark_name in ["workstation_resupply", "finding_nemo"]:
        output_folder = "out/Gfsynth/"+benchmark_name
        if not os.path.exists(output_folder):
            os.makedirs(output_folder)
        for i in range(1,6):
            benchmark = "benchmark/" + benchmark_name + "/" + benchmark_name + "_" + str(i) + "/" + str(i)
            output_file = output_folder + "/" + str(i) + ".res"
            run_syft = "./Gfsynth " + benchmark + " > " + output_file
            print(run_syft)
            os.system(run_syft)
            t = open(output_file, "r")
            lines = t.readlines()
            total_time = lines[len(lines)-1]
            for line in lines:
                if "REALIZABLE" in line:
                    realizability = line.strip("\n").split(" ")[-1]
                    break
            print(realizability+" "+total_time)
            t.close()




