//
// Created by shufang on 8/11/20.
//

#include "GR1Synthesizer.h"
#include "boost/multi_array.hpp"
#include <cassert>

#include <iostream>

namespace Syft {

    GR1Synthesizer::GR1Synthesizer(SymbolicStateDfa spec, Player starting_player,
                                   Player protagonist_player,
                                   GR1 gr1, CUDD::BDD state_space)
            : DfaGameSynthesizer(spec, starting_player, protagonist_player)
            , gr1_(gr1), state_space_(state_space)
            {}



    SynthesisResult GR1Synthesizer::run() const {
        SynthesisResult result;
        return result;


    }

    /*
    SynthesisResult GR1Synthesizer::run() const {
        SynthesisResult result;
        std::vector<CUDD::BDD> env_justices = gr1_.env_justices; // Stores environment justice \phi_1 to \phi_m
        std::vector<CUDD::BDD> agn_justices = gr1_.agn_justices; // Stores agent justice \psi_1 to \psi_n
        int env_justices_num = env_justices.size();
        int agn_justices_num = agn_justices.size();

        boost::multi_array<std::vector<CUDD::BDD>, 2> x_mem(boost::extents[agn_justices_num][env_justices_num]);
        boost::multi_array<std::vector<CUDD::BDD>, 1> y_mem(boost::extents[agn_justices_num]);
        std::vector<CUDD::BDD> z_mem;
    */
        /*
         * The solution can be formulated as the following \mu-calculus formula
         *            Z_1     \mu Y(\/_{i=1}^m \nu X (\psi_1 & Pre(Z_2) | Pre(Y) | !\phi_i & Pre(X))
         *            Z_2     \mu Y(\/_{i=1}^m \nu X (\psi_2 & Pre(Z_3) | Pre(Y) | !\phi_i & Pre(X))
         * gr = \nu [  :  ] [                                :                                       ]
         *             :                                     :
         *            Z_n     \mu Y(\/_{i=1}^m \nu X (\psi_n & Pre(Z_1) | Pre(Y) | !\phi_i & Pre(X))
         */
/*
        CUDD::BDD x, y, z;
        int cy = 0;
        z = state_space_;
        while (true) {
            CUDD::BDD z_new;
            for(int j = 0; j < agn_justices_num; j++) {
                cy = 0;
                y = var_mgr_->cudd_mgr()->bddZero();

                while (true) {
                    CUDD::BDD start = (agn_justices[j] & z) | y;
                    CUDD::BDD y_new = var_mgr_->cudd_mgr()->bddZero();

                    for (int i = 0; i < env_justices_num; i++) {
                        x = z;

                        while (true) {
                            CUDD::BDD moves = state_space_ & preimage(start | (!env_justices[i] & x));
                            CUDD::BDD x_new = project_into_states(moves);
                            if (x_new == x) {
                                break;
                            }
                            x = x_new;
                        }
                        x_mem[j][i].push_back(x);
                        y_new = y_new | x;
                    }
                    y_mem[j].push_back(y_new);
                    cy++;

                    if (y_new == y) {
                        break;
                    }
                    y = y_new;
                }
                z_new = y;
                z_mem.push_back(z_new);

            }

            if (z_new == z) {
                break;
            }
            z = z_new;

        }
        if (includes_initial_state(z)) {
            result.realizability = true;
            result.winning_states = z;
            result.transducer = nullptr; // TODO(Shufang): cannot directly apply boolean synthesis
        } else {
            result.realizability = false;
            result.winning_states = z;
            result.transducer = nullptr;
        }

        return result;

    }
*/


}