int main(int argc, char* argv[]) {
  string input;
  cout << "input: ";
  cin >> input;

  promise<int> p;
  std::thread t(
      [&p](const string& s) {
        try {
          int number = stoi(s);
          p.set_value(number);  // 在此之后，p.get_future().get() 就能够返回了
          // 线程继续做其他事情
          this_thread::sleep_for(chrono::seconds(1));
          cout << "thread do something else..." << endl;
        } catch (...) {
          // 处理出错，此处的异常会由 p.get_future().get() 重新抛出
          p.set_exception(current_exception());
        },
      input);
  
  try 
  {
    cout << "result: " << p.get_future().get() << endl;
  } catch (const std::exception& e) {
    cout << "Failed to parse: " << input << " to integer: " << e.what() << endl;
  }
  t.join();
  return 0;
}
