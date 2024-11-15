# Project README

## Overview

This project involves the configuration and initialization of the **LTDC (LCD-TFT Display Controller)** and **MIPI DSI (Display Serial Interface)** peripherals for interfacing with a display. The configurations are implemented in the source files and also provided in the `.ioc` file for STM32CubeMX visualization.

---

## Configuration Files and Details

### 1. **MIPI DSI Configuration**
- **Source File:** `dsihost.c`
- **Header File:** `dsihost.h`
- **Purpose:** Contains the configuration and initialization logic for the MIPI DSI interface.
  - **Key Functions:**
    - `MX_DSIHOST_DSI_Init()`: Initializes the DSI peripheral with required parameters.
    - `ICN6211_Init()`: Sends the DSI command sequence to initialize the ICN6211 display driver.
  - **Details:**
    - Look for `HAL_DSI_ShortWrite` and `HAL_DSI_LongWrite` calls for the sequence of commands sent to the display.

### 2. **LTDC Configuration**
- **Source File:** `ltdc.c`
- **Header File:** `ltdc.h`
- **Purpose:** Configures the LTDC peripheral for managing the display.
  - **Key Functions:**
    - `MX_LTDC_Init()`: Configures LTDC parameters like synchronization timings, pixel format, and background color.
    - `LCD_Init()`: Manages the hardware-level initialization of the display (e.g., reset, enable, and standby pin toggling).
  - **Details:**
    - Includes initialization of display timing parameters and frame buffer settings.

---

## Viewing the Configuration

### Using STM32CubeMX
- **File:** `NAIAD2.ioc`
- **Details:**
  - The `.ioc` file provides a visual representation of the peripheral configurations.
  - Open the `.ioc` file in STM32CubeMX to:
    - Inspect settings for MIPI DSI, LTDC, and other peripherals.
    - Modify configurations visually and regenerate code.

---

## Usage Guide

### 1. **Code Navigation**
- MIPI DSI initialization: `dsihost.c`
- LTDC initialization: `ltdc.c`
- Display initialization: `ICN6211_Init()` and `LCD_Init()`

### 2. **Hardware Setup**
- Ensure the display is properly connected.
- Check the pin assignments for:
  - **Reset Pin:** Controlled in `LCD_Init()`.
  - **Standby Pin:** Controlled in `LCD_Init()`.
  - **Enable Pin:** Controlled in `LCD_Init()`.

### 3. **Customizing the Display Initialization**
- Adjust the DSI initialization commands in `ICN6211_Init()` based on your display's datasheet.
- Modify LTDC timing and frame buffer settings in `MX_LTDC_Init()` as needed.

### 4. **Debugging**
- Use the `.ioc` file for a comprehensive view of the peripheral setup.
- Verify `HAL_DSI_ShortWrite` and `HAL_DSI_LongWrite` calls for proper data transmission to the display.

---



