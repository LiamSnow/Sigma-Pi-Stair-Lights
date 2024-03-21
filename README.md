# Sigma-Pi-Stair-Lights
Arduino code an ESP32 that controls two addressable LED strips (1200 LEDs total)
to pulse down the stairs in a variety of patterns.

## Running
1. Install Arduino IDE
2. Open this dir arduino/arduino.ino
3. Navigate to File > Preferences
4. Set "Additional boards manager URLs" to https://dl.espressif.com/dl/package_esp32_index.json
5. Open Boards Manager in left nav
6. Search for "esp32 by Espressif" and install
7. Open Library Manager in left nav
8. Search for "FastLED by Daniel Garcia" and install
9. Plug in ESP32
10. Click on Devices in the top nav (next to update & debug buttons)
11. Edit the plugged in Device (Not COMX)
12. Select "DOIT ESP32 DEVKIT Board"