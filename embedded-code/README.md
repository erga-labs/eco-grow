
# EcoGrow Embedded Systems

## Overview
Embedded systems implementation for the EcoGrow Smart Agriculture System using PlatformIO.

## Hardware Requirements
- ESP32 Microcontroller
- NPK Sensor
- Humidity Sensor
- Temperature Sensor

## Development Environment
- PlatformIO IDE or CLI
- VSCode (recommended)
- ESP32 Development Framework

## Setup Instructions
1. Install PlatformIO
   - Via VSCode Extension
   - Or using PlatformIO Core CLI

2. Clone the repository

3. Install dependencies:
   ```bash
   pio pkg install
   ```

## Configuration
- Sensor configuration at ```.example/pins.h```
- Environment configuration at ```.example/secrets.h```

## Build and Upload
- Build the project:
  ```bash
  pio run
  ```
- Upload to ESP32:
  ```bash
  pio run -t upload
  ```

## Debugging
- Enable serial monitor:
  ```bash
  pio device monitor
  ```

## Data Transmission
- Sends sensor data to PocketBase
- Implements secure API communication
- Supports OTA (Over-The-Air) updates

## Power Management
- Low-power mode implementations
- Battery optimization strategies

## Troubleshooting
- Ensure correct driver installations
- Check sensor connections
- Verify WiFi and server connectivity

## Licensing
Refer to the project's main LICENSE file