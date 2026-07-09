# Common Device Tree for Realme RM6785 Series

![Android 16](https://img.shields.io/badge/Android-16-3DDC84?style=for-the-badge&logo=android&logoColor=white)
![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge)

<div align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/3/3d/Realme_6_White.jpg" alt="Realme 6 / 7 Series" width="300">
</div>

<br>

This repository contains the common device tree and configuration files required for building AOSP-based custom ROMs (such as LineageOS) for the **Realme RM6785** family of devices. 

The `RM6785` board covers several MediaTek Helio G90T / G95 based devices released by Realme, which share mostly identical hardware platforms.

## 📱 Supported Devices

This common tree supports the following devices:

| Device Name | Codename | Model Number | SoC |
| ----------- | -------- | ------------ | --- |
| **Realme 6** | `RMX2001` | RMX2001, RMX2001EU | MT6785 (Helio G90T) |
| **Realme 6i / 6s** | `RMX2002` | RMX2002, RMX2003, RMX2040 | MT6785 (Helio G90T) |
| **Realme 7** | `RMX2151` | RMX2151, RMX2155 | MT6785V (Helio G95) |
| **Realme Narzo 20 Pro** | `RMX2161` | RMX2161 | MT6785V (Helio G95) |
| **Realme Narzo 30 4G** | `RMX2156` | RMX2156 | MT6785V (Helio G95) |

## ⚙️ Device Specifications

| Component | Specification |
|:---------:|:-------------|
| **SoC** | MediaTek MT6785 (Helio G90T) / MT6785V (Helio G95) |
| **CPU** | Octa-core (2x2.05 GHz Cortex-A76 & 6x2.0 GHz Cortex-A55) |
| **GPU** | Mali-G76 MC4 |
| **Memory** | 4 GB / 6 GB / 8 GB LPDDR4X |
| **Storage** | 64 GB / 128 GB UFS 2.1 |
| **Display** | 6.5" FHD+ (1080 x 2400) IPS LCD @ 90Hz |
| **Battery** | 4300 mAh (Realme 6/6i) / 5000 mAh (Realme 7) / 4500 mAh (Narzo 20 Pro) |
| **Main Camera** | 64 MP (Primary) + 8 MP (Ultrawide) + 2 MP (Macro) + 2 MP (Depth) |
| **Front Camera** | 16 MP |
| **Fingerprint** | Side-mounted |

## 🛠️ Build Instructions

To build a ROM utilizing this common tree, you will typically need to clone the following repositories into your ROM's local manifest:

- **Common Device Tree:** `android_device_realme_RM6785-common`
- **Device Specific Tree:** e.g., `android_device_realme_RMX2001`
- **Vendor Blobs:** `android_vendor_realme_RM6785-common`
- **Kernel Source:** `android_kernel_realme_mt6785`

Once synced, simply initialize the environment and run the build command (for LineageOS):

```bash
source build/envsetup.sh
lunch lineage_RMX2001-userdebug
mka bacon
```

## 🐛 Bug Reporting & Contributions

If you find an issue related to hardware support (e.g. codecs, camera, sensors), please open an issue with detailed logs (`logcat` and `dmesg`).

Pull requests are welcome! Ensure that your commits follow the standard Android commit guidelines.

---

*Copyright (C) 2021-2025 The LineageOS Project*
