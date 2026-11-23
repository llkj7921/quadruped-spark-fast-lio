# Quadruped SPARK-FAST-LIO

面向机器狗和 Livox Mid-360 的 ROS 2 LiDAR–IMU 实时前端，基于
[MIT-SPARK/spark-fast-lio](https://github.com/MIT-SPARK/spark-fast-lio) 和
[HKU-MARS/FAST_LIO](https://github.com/hku-mars/FAST_LIO) 二次开发。
本仓库不是上游官方发行版本。

推荐从统一交付仓库
[`llkj7921/quadruped-slam`](https://github.com/llkj7921/quadruped-slam)
安装和启动。

## 主要功能

- Livox Mid-360 点云和 IMU 预处理、去畸变与 ESKF 里程计。
- 当前帧和 ikd-Tree 局部地图的体素控制。
- 室内、室外两套参数配置。
- 雷达断流、队列延迟和定位质量监测。
- 异常时立即冻结前端地图更新，恢复确认后重新开放。
- 发布 `odom -> base`，由后端重定位器维护 `map -> odom`。
- 使用 `slam_system_interfaces` 发布强类型健康和断流状态。

## 系统关系

```text
Livox driver
  | /livox/lidar + /livox/imu
  v
Quadruped SPARK-FAST-LIO
  | /odometry + /cloud_registered + health
  v
Quadruped KISS-SAM
```

兼容的后端和接口版本由
[`quadruped-slam/slam.repos`](https://github.com/llkj7921/quadruped-slam/blob/main/slam.repos)
锁定。

## 安装与启动

```bash
git clone https://github.com/llkj7921/quadruped-slam.git
cd quadruped-slam
./scripts/install.sh
./scripts/build.sh
cp config/robot.env.example config/robot.env
./scripts/start.sh
```

室内、室外配置位于：

```text
spark_fast_lio/config/mid360_indoor.yaml
spark_fast_lio/config/mid360_outdoor.yaml
```

选择环境：

```bash
./scripts/start.sh environment:=indoor
./scripts/start.sh environment:=outdoor
```

默认雷达输入为：

```text
/livox/lidar
/livox/imu
```

迁移到另一台机器人前必须确认 topic、点云格式、时间戳、LiDAR–IMU 外参和
`base_frame`，不能只复制旧机器的构建产物。

## 独立构建与测试

建议在包含 `slam_system_interfaces` 的兼容工作区内执行：

```bash
source /opt/ros/humble/setup.bash
colcon build --packages-up-to spark_fast_lio --symlink-install
colcon test --packages-select spark_fast_lio
colcon test-result --verbose
```

## 项目来源与许可证

本仓库保留上游 Git 历史，因此 GitHub Contributors 会包含原项目贡献者。
派生修改不改变原代码的许可证要求。

- 上游来源与论文：[docs/UPSTREAM_README.md](docs/UPSTREAM_README.md)
- 许可证：[spark_fast_lio/LICENSE](spark_fast_lio/LICENSE)（GNU GPL v2）
- 上游 ROS 2 项目：[`MIT-SPARK/spark-fast-lio`](https://github.com/MIT-SPARK/spark-fast-lio)
- 原始算法项目：[`HKU-MARS/FAST_LIO`](https://github.com/hku-mars/FAST_LIO)
