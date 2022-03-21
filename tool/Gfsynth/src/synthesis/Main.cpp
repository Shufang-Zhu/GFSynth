#include <cstring>
#include <iostream>
#include <memory>

#include "Stopwatch.h"
#include "LTLfGR1Synthesizer.h"



int main(int argc, char ** argv) {
  if (argc != 2) {
      std::cout << "Usage: " << argv[0]
                << " <benchmark-name>"
                << std::endl;

    return 0;
  }

  Syft::Stopwatch total_time_stopwatch; // stopwatch for end-to-end execution
//  Syft::Stopwatch stopwatch; // stopwatch for individual steps

  total_time_stopwatch.start();
  std::cout << "Start solving the problem...\n";

  Syft::Stopwatch read_file_stopwatch; // stopwatch for reading input files
  read_file_stopwatch.start();
  std::cout << "* Start reading input files...\n";

  std::string benchmark_name = argv[1];
  std::string env_gr1_assum_filename = benchmark_name + ".env_gr1";
  std::string env_safety_assum_filename = benchmark_name + ".env_safety";
  std::string agn_reach_goal_filename = benchmark_name + ".agn_reach";
  std::string agn_safety_goal_filename = benchmark_name + ".agn_safety";
  std::string partition_filename = benchmark_name + ".p";


    std::shared_ptr<Syft::VarMgr> var_mgr = std::make_shared<Syft::VarMgr>();


    Syft::ExplicitStateDfa explicit_dfa_env_safety = Syft::ExplicitStateDfa::read_from_file(
            var_mgr, env_safety_assum_filename);

    Syft::ExplicitStateDfa explicit_dfa_agn_reach = Syft::ExplicitStateDfa::read_from_file(
            var_mgr, agn_reach_goal_filename);

    Syft::ExplicitStateDfa explicit_dfa_agn_safety = Syft::ExplicitStateDfa::read_from_file(
            var_mgr, agn_safety_goal_filename);


    Syft::GR1 gr1 = Syft::GR1::read_from_gr1_file(var_mgr, env_gr1_assum_filename);


    Syft::InputOutputPartition partition =
            Syft::InputOutputPartition::read_from_file(partition_filename);

    var_mgr->partition_variables(partition.input_variables,
                                 partition.output_variables);


    auto read_file_time = read_file_stopwatch.stop();
    std::cout << "* Finish reading input files, took time: "
              << read_file_time.count() << " ms" << std::endl;

    Syft::Stopwatch construct_symbolic_arena_stopwatch; // stopwatch for constructing symbolic game arena
    construct_symbolic_arena_stopwatch.start();
    std::cout << "* Start constructing symbolic game arena...\n";

    Syft::SymbolicStateDfa symbolic_dfa_env_safety = Syft::SymbolicStateDfa::from_explicit(
            std::move(explicit_dfa_env_safety));

    Syft::SymbolicStateDfa symbolic_dfa_agn_reach = Syft::SymbolicStateDfa::from_explicit(
            std::move(explicit_dfa_agn_reach));

    Syft::SymbolicStateDfa symbolic_dfa_agn_safety = Syft::SymbolicStateDfa::from_explicit(
            std::move(explicit_dfa_agn_safety));

    auto construct_symbolic_arena_time = construct_symbolic_arena_stopwatch.stop();
    std::cout << "* Finish constructing symbolic game arena, took time: "
              << construct_symbolic_arena_time.count() << " ms" << std::endl;

    Syft::LTLfGR1Synthesizer synthesizer(var_mgr, gr1, symbolic_dfa_env_safety,
                                         symbolic_dfa_agn_reach, symbolic_dfa_agn_safety);


    Syft::SynthesisResult result = synthesizer.run(benchmark_name);

    if (result.realizability == true) {
      std::cout << "The problem is REALIZABLE" << std::endl;
    }
    else{
      std::cout << "The problem is UNREALIZABLE" << std::endl;
    }


  auto total_time = total_time_stopwatch.stop();

  std::cout << "Total time: "
	    << total_time.count() << " ms" << std::endl;

  return 0;
}

