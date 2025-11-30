# Local VL53L1X Component Setup

Copy these files from your Averyy component:

```
C:\Users\jerem\Documents\ESPHOME_PROJECTS\EXTERNAL_COMPONENTS\vl53l1x\
```

**IMPORTANT:** Create a subfolder named `vl53l1x` inside the vl53l1x folder first!

Your final structure should be:

```
external_components/
  vl53l1x/
    vl53l1x/           ← Create this subfolder
      __init__.py
      sensor.py
      vl53l1x.cpp
      vl53l1x.h
```

Steps:
1. Create folder: `external_components/vl53l1x/vl53l1x/`
2. Copy the 4 files into that subfolder
3. Compile and flash

Done!
