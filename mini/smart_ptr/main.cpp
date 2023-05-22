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
  shared_ptr<Checken> _checken(new Checken());
  shared_ptr<Egg> _egg(new Egg());
  // 循环引用
  if (_checken && _egg) {
    _checken->p_egg_ = _egg;
    _egg->p_checken_ = _checken;
  }
  LOG(INFO) << "_checken use count:" << _checken.use_count();
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