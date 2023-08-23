#pragma once

#include "innoviz_msgs/msg/innoviz_scan.hpp"
#include "nebula_decoders/nebula_decoders_common/nebula_driver_base.hpp"
#include "nebula_decoders/nebula_decoders_innoviz/decoders/innoviz_scan_decoder.hpp"
#include "nebula_common/innoviz/innoviz_common.hpp"

namespace nebula
{
namespace drivers
{

class InnovizDriver : public NebulaDriverBase 
{
public:

    InnovizDriver(const std::shared_ptr<drivers::InnovizSensorConfiguration>& sensorConfiguration);
    drivers::NebulaPointCloudPtr ConvertScanToPointcloud(const std::shared_ptr<innoviz_msgs::msg::InnovizScan> & innoviz_scan);
    Status SetCalibrationConfiguration(const CalibrationConfigurationBase & calibration_configuration);
    Status GetStatus();

private:
    std::shared_ptr<drivers::InnovizScanDecoder> scan_decoder_;
    Status driver_status_;
};

}
}
