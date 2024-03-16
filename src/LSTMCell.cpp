/**
 * For any readers, I would like to defend myself by citing
 * the fact that this is a CPP rewrite of python code I
 * wrote when I was 17. Please do not be annoyed by the horrendous
 * code design.
 */

#include <cmath>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <eigen3/Eigen/src/Core/util/Constants.h>
#include <iostream>

const int LSTM_GATE_COUNT = 4;
typedef Eigen::Matrix<float, LSTM_GATE_COUNT, Eigen::Dynamic> WeightMatrix;

/**
 * Contains implementation of an LSTM Cell
 */
class LSTMCell {
public:
  int features;

  LSTMCell(int t_features) : features(t_features) {
    std::cout << "Initializing LSTMCell with " << t_features << " features"
              << std::endl;

    /**
     * Initialize gate weights in a matrix, with each
     * row being a different gate.
     * The initialization function is a random [-1;1]
     * multiplied by the square root of 1/(features + 1)
     */
    m_hidden_weights = WeightMatrix::Random(LSTM_GATE_COUNT, t_features) *
                       std::sqrt(1 / (t_features + 1));
    m_input_weights  = WeightMatrix::Random(LSTM_GATE_COUNT, t_features) *
                       std::sqrt(1 / (t_features + 1));

    std::cout << "LSTMCell initialized" << std::endl;
  }

private:
  int m_hidden = 0;
  int m_previous_output = 0;
  WeightMatrix m_hidden_weights;
  WeightMatrix m_input_weights;

};
