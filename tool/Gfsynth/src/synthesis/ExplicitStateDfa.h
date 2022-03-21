#ifndef EXPLICIT_STATE_DFA_H
#define EXPLICIT_STATE_DFA_H

#include <exception>
#include <istream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <set>

#include "VarMgr.h"

namespace Syft {

/**
 * \brief A DFA with explicit states and symbolic transitions.
 */
class ExplicitStateDfa {
 private:

  std::shared_ptr<VarMgr> var_mgr_;

  size_t initial_state_;
  size_t state_count_;
  std::vector<size_t> final_states_;
  std::vector<CUDD::ADD> transition_function_;

  ExplicitStateDfa(std::shared_ptr<VarMgr> var_mgr);

  static std::runtime_error bad_file_format_exception(std::size_t line_number);

  static std::string ltlf_to_dfa_file(const std::string& ltlf_filename);

  static std::vector<std::string> read_mona_line(std::istream& in,
						 std::size_t line_number);

  static std::vector<std::string> read_variable_names(std::istream& in,
						      std::size_t line_number);
  
  static std::size_t read_state_count(std::istream& in,
				      std::size_t line_number);

  static std::vector<std::size_t> read_final_states(std::istream& in,
						    std::size_t line_number);

  static std::vector<std::size_t> read_behaviour(std::istream& in,
						 std::size_t line_number);

  static std::vector<std::vector<int>> read_node_table(std::istream& in,
						       std::size_t line_number);

  static CUDD::ADD build_add(
      std::size_t node_index,
      const std::shared_ptr<VarMgr>& var_mgr,
      const std::vector<std::string>& variable_names,
      const std::vector<std::vector<int>>& node_table,
      std::unordered_map<std::size_t, CUDD::ADD>& add_table);

 public:

  /**
   * \brief Constructs a DFA from a MONA output file.
   *
   * Assumes that the DFA is in MONA's external format and that state 0 is a
   * dummy initial state with a transition to state 1. State 1 is set as the
   * initial state in the returned DFA.
   *
   * \param var_mgr The variable manager for managing transition variables.
   * \param filename The name of the file to read the DFA from.
   * \return The DFA described in the file.
   */
  static ExplicitStateDfa read_from_file(std::shared_ptr<VarMgr> var_mgr,
					 const std::string& filename);

  /**
   * \brief Returns the variable manager.
   */
  std::shared_ptr<VarMgr> var_mgr() const;

  /**
   * \brief Returns the initial state of the DFA.
   */
  std::size_t initial_state() const;

  /**
   * \brief Returns the number of states in the DFA.
   */
  std::size_t state_count() const;

  /**
   * \brief Returns the list of indices of final states of the DFA.
   */
  std::vector<std::size_t> final_states() const;

  /**
   * \brief Returns the transition function of the DFA as a vector of ADDs.
   *
   * The ADD in index \a i represents the transition function for state \a i.
   */
  std::vector<CUDD::ADD> transition_function() const;

  /**
   * \brief Saves the transition function of the DFA in a .dot file.
   *
   * \param filename The name of the file to save the transition function to.
   */
  void dump_dot(const std::string& filename) const;

    /**
       * \brief Returns a product of two explicit DFAs.
       *
       * \param first_dfa The first DFA.
       * \param second_dfa The second DFA.
       * \return An explicit DFA of the product.
       */
       static ExplicitStateDfa product(const std::vector<ExplicitStateDfa>& dfa_vector);

    /**
    * \brief Redirects the transitions to unsafe states into self-loop transitions.
    *
    * All transitions going to the unsafe states are redirected into self-loop transitions.
    *
    * \param unsafe_states A set of unsafe states.
    */
    void prune_unsafe_transitions(const std::vector<size_t> unsafe_states);
};

}

#endif // EXPLICIT_STATE_DFA_H
