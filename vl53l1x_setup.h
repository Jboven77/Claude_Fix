#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include <Wire.h>
#include <VL53L1X.h>

using namespace esphome;

class VL53L1XSensor : public Component {
 public:
  sensor::Sensor *distance_sensor = new sensor::Sensor();

  void setup() override {
    ESP_LOGI("vl53l1x", "Initializing VL53L1X sensor...");
    Wire.begin();
    delay(100);

    if (!sensor_.begin()) {
      ESP_LOGE("vl53l1x", "VL53L1X sensor not found!");
      this->mark_failed();
      return;
    }

    ESP_LOGI("vl53l1x", "VL53L1X detected");
    sensor_.setDistanceMode(VL53L1X::Long);
    sensor_.setMeasurementTimingBudget(66000);
    sensor_.startContinuous(100);
    ESP_LOGI("vl53l1x", "Configured for 1300mm range");
  }

  void update() override {
    if (sensor_.dataReady()) {
      int distance = sensor_.read();
      if (distance > 0 && distance < 4000) {
        distance_sensor->publish_state(distance);
      }
    }
  }

  float get_setup_priority() const override { return setup_priority::IO; }

 private:
  VL53L1X sensor_;
};
