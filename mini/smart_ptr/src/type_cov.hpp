// Copyright [2023] - MiniEye INC.

#ifndef SRC_EXAMPLE_HPP_
#define SRC_EXAMPLE_HPP_

#include <glog/logging.h>
#include <limits.h>

#include <memory>
#include <string>
#include <vector>

namespace example {

class SolutionBase {
 public:
  SolutionBase() {}
  virtual ~SolutionBase() {}

 public:
  virtual void ShowVir() {
    LOG(INFO) << "(virtual)This is a base class of solution.";
  }
  void Show() { LOG(INFO) << "This is a base class."; }
};

class GeoSolution : public SolutionBase {
 public:
  GeoSolution() {}
  ~GeoSolution() {}

 public:
  void ShowVir() override {
    LOG(INFO) << "(override)This is a geometric solution.";
  }

  void Show() { LOG(INFO) << "This is a geo class."; }
};

class AlgSolution : public SolutionBase {
 public:
  AlgSolution() {}
  ~AlgSolution() {}

 public:
  void ShowVir() override {
    LOG(INFO) << "(override)This is a algebra solution.";
  }

  void Show() { LOG(INFO) << "This is a algebra class."; }

  void set_ans(const int& ans) { ans_ = ans; }

 private:
  int ans_;
};
}  // namespace example

using GeoSolution = example::GeoSolution;
using AlgSolution = example::AlgSolution;
using SolutionBase = example::SolutionBase;
#endif  // SRC_EXAMPLE_HPP_
