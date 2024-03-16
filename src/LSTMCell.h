#pragma once

#include <cmath>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <eigen3/Eigen/src/Core/util/Constants.h>

const int LSTM_GATE_COUNT = 4;
typedef Eigen::Matrix<float, LSTM_GATE_COUNT, Eigen::Dynamic> WeightMatrix;

class LSTMCell {
public:
  int features;
  LSTMCell(int t_features);

private:
  int m_hidden;
  int m_previous_output;
  WeightMatrix m_hidden_weights;
  WeightMatrix m_input_weights;
};
