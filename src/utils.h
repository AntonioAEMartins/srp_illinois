#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <omp.h>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

struct PERIODParameters {
  double minimum_period;
  double maximum_period;
  double total_duration;
};

struct BLSResult {
  double best_period;
  double best_duration;
  double best_phase;
  double best_d_value;
};

typedef std::tuple<double, double, double> SPECParameters;

template <typename T> T min_value(const std::vector<T> &v);

template <typename T> T max_value(const std::vector<T> &v);

template <typename T> T ptp(const std::vector<T> &v);

std::vector<double> arange(double start, double end, double step);

std::vector<double> linspace(double start, double end, size_t num);

std::vector<double> auto_phase(double period, double duration);

PERIODParameters auto_max_min_period(std::vector<double> &time);

std::vector<double> auto_period(double minimum_period = -1,
                                double maximum_period = -1,
                                double total_duration = -1);

std::vector<SPECParameters> spec_generator(std::vector<double> &time);

std::vector<SPECParameters> spec_generator_gambiarra(std::vector<double> &time);

std::vector<double> compute_trel(std::vector<double> &time);

std::vector<double> normalize(std::vector<double> &flux);

std::vector<double> compute_weights(std::vector<double> &flux_err);

double model(std::vector<double> &t_rel, std::vector<double> &flux,
             std::vector<double> &weights, double period, double duration,
             double phase);

BLSResult bls(std::vector<double> &time, std::vector<double> &flux,
              std::vector<double> &flux_err,
              std::vector<SPECParameters> &s_params);

void readCSV(const std::string &filename, std::vector<double> &time,
             std::vector<double> &flux, std::vector<double> &flux_err);

#endif // UTILS_H