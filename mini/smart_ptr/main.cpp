// Copyright {2023} - MiniEye INC.

#include <memory>
#include <thread>

#include "src/circular_ref.hpp"
#include "src/type_cov.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
  FLAGS_logtostderr = true;
  FLAGS_colorlogtostderr = true;

  LOG(INFO) << "============= 循环引用 =============";
  shared_ptr<Checken> _chicken(new Checken());
  shared_ptr<Egg> _egg(new Egg());
  // 循环引用
  if (_chicken && _egg) {
    _chicken->p_egg_ = _egg;
    _egg->p_chicken_ = _chicken;
  }
  LOG(INFO) << "_chicken use count:" << _chicken.use_count();
  LOG(INFO) << "_egg use count:" << _egg.use_count();

  LOG(INFO) << "============= 指针转换 =============";
  shared_ptr<SolutionBase> _base_s(new SolutionBase());
  _base_s->ShowVir();
  shared_ptr<GeoSolution> _geo_s(new GeoSolution());
  _geo_s->ShowVir();

  LOG(INFO) << "============= 上行转换 geo->base =============";
  LOG(INFO) << "static_pointer_cast:";
  // 静态转换
  shared_ptr<SolutionBase> _base_s1 = static_pointer_cast<SolutionBase>(_geo_s);
  _base_s1->ShowVir();
  _base_s1->Show();
  LOG(INFO) << "dynamic_pointer_cast:";
  // 具有检查功能，可以检测下行转换风险
  shared_ptr<SolutionBase> _base_s2 =
      dynamic_pointer_cast<SolutionBase>(_geo_s);
  if (_base_s2) {
    _base_s2->ShowVir();
    _base_s2->Show();
  }
  LOG(INFO) << "reinterpret_pointer_cast:";
  shared_ptr<SolutionBase> _base_s3 =
      reinterpret_pointer_cast<SolutionBase>(_geo_s);
  _base_s3->ShowVir();
  _base_s3->Show();

  LOG(INFO) << "============= 下行转换 base->geo =============";
  LOG(INFO) << "static_pointer_cast:";
  shared_ptr<SolutionBase> _geo_s1 = static_pointer_cast<GeoSolution>(_base_s);
  _geo_s1->ShowVir();
  _geo_s1->Show();
  LOG(INFO) << "dynamic_pointer_cast:";
  shared_ptr<SolutionBase> _geo_s2 = dynamic_pointer_cast<GeoSolution>(_base_s);
  if (_geo_s2) {
    _geo_s2->ShowVir();
    _geo_s2->Show();
  }
  // 转换失败
  // _geo_s2->Run();
  // _geo_s2->Show();
  LOG(INFO) << "reinterpret_pointer_cast:";
  shared_ptr<SolutionBase> _geo_s3 =
      reinterpret_pointer_cast<GeoSolution>(_base_s);
  _geo_s3->ShowVir();
  _geo_s3->Show();

  LOG(INFO) << "const_pointer_cast:";
  shared_ptr<const AlgSolution> _geo_s4(new AlgSolution);
  shared_ptr<AlgSolution> _geo_s5 = const_pointer_cast<AlgSolution>(_geo_s4);
  // 无法通过编译
  // _geo_s4->set_ans(1);
  _geo_s5->set_ans(1);
}
/*
I0612 16:45:16.127625 19978 main.cpp:17] ============= 循环引用 =============
I0612 16:45:16.127691 19978 main.cpp:25] _checken use count:2
I0612 16:45:16.127696 19978 main.cpp:26] _egg use count:1
I0612 16:45:16.127698 19978 main.cpp:28] ============= 指针转换 =============
I0612 16:45:16.127701 19978 type_cov.hpp:22] (virtual)This is a base class of solution.
I0612 16:45:16.127704 19978 type_cov.hpp:34] (override)This is a geometric solution.
I0612 16:45:16.127707 19978 main.cpp:34] ============= 上行转换 geo->base =============
I0612 16:45:16.127709 19978 main.cpp:35] static_pointer_cast:
I0612 16:45:16.127712 19978 type_cov.hpp:34] (override)This is a geometric solution.
I0612 16:45:16.127713 19978 type_cov.hpp:24] This is a base class.
I0612 16:45:16.127715 19978 main.cpp:40] dynamic_pointer_cast:
I0612 16:45:16.127718 19978 type_cov.hpp:34] (override)This is a geometric solution.
I0612 16:45:16.127720 19978 type_cov.hpp:24] This is a base class.
I0612 16:45:16.127722 19978 main.cpp:48] reinterpret_pointer_cast:
I0612 16:45:16.127724 19978 type_cov.hpp:34] (override)This is a geometric solution.
I0612 16:45:16.127727 19978 type_cov.hpp:24] This is a base class.
I0612 16:45:16.127729 19978 main.cpp:54] ============= 下行转换 base->geo =============
I0612 16:45:16.127732 19978 main.cpp:55] static_pointer_cast:
I0612 16:45:16.127733 19978 type_cov.hpp:22] (virtual)This is a base class of solution.
I0612 16:45:16.127735 19978 type_cov.hpp:24] This is a base class.
I0612 16:45:16.127737 19978 main.cpp:59] dynamic_pointer_cast:
I0612 16:45:16.127740 19978 main.cpp:68] reinterpret_pointer_cast:
I0612 16:45:16.127743 19978 type_cov.hpp:22] (virtual)This is a base class of solution.
I0612 16:45:16.127744 19978 type_cov.hpp:24] This is a base class.
I0612 16:45:16.127746 19978 main.cpp:74] const_pointer_cast:
I0612 16:45:16.127749 19978 circular_ref.hpp:23] destructor egg func
I0612 16:45:16.127753 19978 circular_ref.hpp:17] destructor checken func

*/