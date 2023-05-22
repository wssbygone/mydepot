// Copyright [2022] - MiniEye INC.

#include "glog/logging.h"
#include "gtest/gtest.h"
#include "src/type_cov.hpp"
#include "src/circular_ref.hpp"

class MyClassTest : public testing::TestWithParam<int> {
 public:
  static void SetUpTestCase() { LOG(INFO) << "SetUpTestCase"; }
  static void TearDownTestCase() { LOG(INFO) << "TearDownTestCase"; }
  virtual void SetUp() {  // TEST跑之前会执行SetUp
    LOG(INFO) << "SetUp";
  }
  virtual void TearDown() {  // TEST跑完之后会执行TearDown
    LOG(INFO) << "TearDown";
  }
};

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
  FLAGS_logtostderr = true;
  FLAGS_colorlogtostderr = true;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
