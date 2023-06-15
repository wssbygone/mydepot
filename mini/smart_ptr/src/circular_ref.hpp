// Copyright [2023] - MiniEye INC.

#ifndef SRC_EXAMPLE2_HPP_
#define SRC_EXAMPLE2_HPP_

#include <glog/logging.h>

#include <memory>

namespace example {

class Egg;
class Checken {
 public:
  std::weak_ptr<Egg> p_egg_;
  // std::shared_ptr<Egg> p_egg_;
  ~Checken() { LOG(INFO) << "destructor chicken func"; }
};
class Egg {
 public:
  // std::weak_ptr<A> pa;
  std::shared_ptr<Checken> p_chicken_;
  ~Egg() { LOG(INFO) << "destructor egg func"; }
};

}  // namespace example

using Checken = example::Checken;
using Egg = example::Egg;

#endif  // SRC_EXAMPLE2_HPP_
