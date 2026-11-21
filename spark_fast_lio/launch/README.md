## 10_14

## Livox Mid-360

The outdoor profile is selected by default:

```bash
ros2 launch spark_fast_lio mapping_mid360.launch.yaml environment:=outdoor
```

Use the indoor profile for shorter range and finer scan/map voxels:

```bash
ros2 launch spark_fast_lio mapping_mid360.launch.yaml environment:=indoor
```

Choose the profile before starting a mapping session. Changing voxel resolution
inside an existing session would mix map resolutions in the ikd-Tree.

The default display publishes the complete algorithm cloud. To hide points whose
map-frame height is above 2.5 m without changing odometry or mapping, use:

```bash
ros2 launch spark_fast_lio mapping_mid360.launch.yaml display_mode:=height_limited
```

## 12_07

## 12_08

- `acl_jackal`

```
ros2 launch spark_fast_lio mapping_kimera_multi.launch.yaml scene_id:="acl_jackal"
```

- `acl_jackal2`

```
ros2 launch spark_fast_lio mapping_kimera_multi.launch.yaml scene_id:="acl_jackal2"
```

- `sparkal1`

```
ros2 launch spark_fast_lio mapping_kimera_multi.launch.yaml scene_id:="sparkal1"
```

#### Exceptional cases where needs more information (e.g., `lidar_frame`, `imu_frame`)

- `apis`

```
ros2 launch spark_fast_lio mapping_kimera_multi.launch.yaml scene_id:="apis" lidar_frame:="ouster_link" imu_frame:="camera_imu_optical_frame"
```

- `hathor`

```
ros2 launch spark_fast_lio mapping_kimera_multi.launch.yaml scene_id:="hathor" lidar_frame:=velodyne
```

- `sobek`

```
ros2 launch spark_fast_lio mapping_kimera_multi.launch.yaml scene_id:="sobek" lidar_frame:=ouster_link
```

- `sparkal2`

```
ros2 launch spark_fast_lio mapping_kimera_multi.launch.yaml scene_id:="sparkal2" lidar_frame:="velodyne"
```

- `thoth`

```
ros2 launch spark_fast_lio mapping_kimera_multi.launch.yaml scene_id:="thoth" lidar_frame:="ouster_link" imu_frame:="camera_imu_optical_frame"
```
