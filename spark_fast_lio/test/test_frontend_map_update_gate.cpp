#include <gtest/gtest.h>

#include "frontend_map_update_gate.hpp"

using spark_fast_lio::FrontendMapUpdateGate;

TEST(FrontendMapUpdateGate, FreezesImmediatelyOnGap) {
  FrontendMapUpdateGate gate;
  EXPECT_TRUE(gate.allowed());
  gate.freeze();
  EXPECT_FALSE(gate.allowed());
}

TEST(FrontendMapUpdateGate, OnlyExplicitRecoveryPermissionUnfreezes) {
  FrontendMapUpdateGate gate;
  gate.freeze();
  gate.updateFromRecoveryStatus(
      "status=suspected motion_allowed=true map_writes_allowed=false");
  EXPECT_FALSE(gate.allowed());
  gate.updateFromRecoveryStatus(
      "status=normal motion_allowed=true map_writes_allowed=true");
  EXPECT_TRUE(gate.allowed());
}
