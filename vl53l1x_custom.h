#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/hal.h"
#include <Wire.h>
#include <VL53L1X.h>

using namespace esphome;

class VL53L1XCustomSensor : public Component {
 public:
  sensor::Sensor *distance_sensor = new sensor::Sensor();

  void setup() override {
    ESP_LOGI("vl53l1x", "Setting up VL53L1X sensor");

    Wire.begin();
    delay(100);

    // Initialize sensor
    if (!sensor_.begin()) {
      ESP_LOGE("vl53l1x", "Failed to detect VL53L1X sensor!");
      this->mark_failed();
      return;
    }

    ESP_LOGI("vl53l1x", "VL53L1X detected successfully");

    // Configure for long range mode (1300mm+)
    sensor_.setDistanceMode(VL53L1X::Long);
    sensor_.setMeasurementTimingBudget(66000);  // 66ms for best accuracy
    sensor_.startContinuous(100);  // 100ms measurement interval

    ESP_LOGI("vl53l1x", "Sensor configured for long range (1300mm)");
  }

  void update() override {
    if (sensor_.dataReady()) {
      int distance_mm = sensor_.read();

      // Filter invalid readings
      if (distance_mm > 0 && distance_mm < 4000) {
        distance_sensor->publish_state(distance_mm);
        ESP_LOGD("vl53l1x", "Distance: %d mm", distance_mm);
      }
    }
  }

  float get_setup_priority() const override {
    return setup_priority::IO;
  }

 private:
  VL53L1X sensor_;
};
