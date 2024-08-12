# ESP32 Servo Control with Web Interface


<p align="center">
  <img width="674" alt="image" src="https://github.com/user-attachments/assets/54461d13-c843-468f-9378-0b1adf763e9f">
</p>


This project demonstrates how to control a servo motor using an ESP32 microcontroller via a web-based interface. The web interface allows users to adjust the servo's position using a slider, which sends commands to the ESP32 over Wi-Fi.

<p align="center">
  <img src="https://github.com/user-attachments/assets/2f771b4d-19d3-42fd-b6fc-a4c091dcac82" alt="Image Description">
</p>

## Components:
- ESP32
- Servo motor 

## Software:
- PlatformIO IDE on VS Code
- The Code for the ESP32 can be found here:
  - [main.cpp](main.cpp) 
- You can find the HTML and CSS files here:
  - [index.html](index.html) 
  - [style.css](style.css)
- Add this in the `platformio.ini` file:
  - ```bash
    lib_deps = 
      ESP Async WebServer
      ESP32Servo
    ```

## Wiring:
- Servo's signal wire to GPIO 15 on the ESP32.
- Servo's VCC to the 5V pin on the ESP32.
- Servo's GND to one of the GND pins (16) on the ESP32.

## To use:

1. Connect to Wi-Fi:
- Once the ESP32 is powered on, it will connect to the configured Wi-Fi network
- Check the Serial Monitor for the IP address assigned to the ESP32

2. Access the Web Interface:
- Open a web browser on any device connected to the same Wi-Fi network.
- Enter the IP address of the ESP32 in the browser's address bar (e.g., http://192.168.x.x).

3. Control the Servo:
- Use the slider on the web interface to adjust the servo's position.
- The servo should move in real-time as you adjust the slider.
