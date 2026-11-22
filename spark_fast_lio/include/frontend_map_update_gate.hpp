#pragma once

#include <atomic>
#include <string>

namespace spark_fast_lio {

class FrontendMapUpdateGate {
 public:
  void freeze() { allowed_.store(false); }

  void updateFromRecoveryStatus(const std::string& status) {
    allowed_.store(status.find("map_writes_allowed=true") != std::string::npos);
  }

  bool allowed() const { return allowed_.load(); }

 private:
  std::atomic<bool> allowed_{true};
};

}  // namespace spark_fast_lio
