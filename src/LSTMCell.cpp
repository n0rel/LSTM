#include "LSTMCell.h"
#include <iostream>

std::string LOG_PREFIX = "[LSTMCell] ";

/**
 * Contains implementation of an LSTM Cell
 */
LSTMCell::LSTMCell(int t_features) : features(t_features) {
  std::cout << LOG_PREFIX << "Initializing LSTMCell with " << t_features
            << " features" << std::endl;

  /**
   * Initialize gate weights in a matrix, with each
   * row being a different gate.
   * The initialization function is a random [-1;1]
   * multiplied by the square root of 1/(features + 1)
   */
  m_hidden_weights = WeightMatrix::Random(LSTM_GATE_COUNT, t_features) *
                     std::sqrt(1.0 / (t_features + 1.0));
  m_input_weights = WeightMatrix::Random(LSTM_GATE_COUNT, t_features) *
                    std::sqrt(1.0 / (t_features + 1.0));

  std::cout << LOG_PREFIX << "Hidden weights initialized:" << std::endl
            << m_hidden_weights << std::endl;
  std::cout << LOG_PREFIX << "Input weights initialized:" << std::endl
            << m_input_weights << std::endl;
}
