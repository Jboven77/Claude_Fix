# VL53L1X Local Component Setup

This directory contains the VL53L1X time-of-flight sensor component for ESPHome.

## Files Needed

Copy these files from: `C:\Users\jerem\Documents\ESPHOME_PROJECTS\EXTERNAL_COMPONENTS\vl53l1x\`

- `__init__.py`
- `sensor.py`
- `vl53l1x.cpp`
- `vl53l1x.h`

Place them in this directory: `external_components/vl53l1x/`

## Configuration

The YAML file automatically loads this local component:

```yaml
external_components:
  - source:
      type: local
      path: ./external_components/vl53l1x
    components: [vl53l1x]
```

Once files are in place, ESPHome will compile and flash correctly.
