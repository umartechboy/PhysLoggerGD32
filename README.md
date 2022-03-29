# Useful Links
Arduino additional boards link for the STM32 board.
http://dan.drown.org/stm32duino/package_STM32duino_index.json

Board name:
STM32F1xx/GD32F1xx boards by stm32duino version 2020.8.9

Visual Studio: Visual Studio 2019
Extension: Arduino IDE for Visual Studio (VisualMicro)

arm-none-eabi toolchain from Cube IDE
https://drive.google.com/file/d/1Iq9hZ-0rsWQFR8FWtz4JfCobEzfqXEKW/view?usp=sharing


# Problem Statement
The precise problem statement for the project is as follows.

We have developed a firmware code for two variants of an application board based on STMicroelectronic's STM32F103CBT6 microcontroller. While deployed, the firmware uses a serial port to communicate with a computer connected to the application board via a USB port. The first variant of the board uses an FT232r IC to interface the controller's UART with the USB while in the other, we use the on-chip USB peripheral of the STM32 to emulate a serial-USB node that uses a driver called "Maple". The development is carried out in VisualStuido 2019 using an extension called VisualMicro that connects it to Arduino. 

Now, we want to:
1. replace the STM32 chip with a GigaDevices GD32E103CBT6, 
2. add support for the on-chip FPU when built for the GD IC and use the upgraded 120/108Mhz clock,
3. keep everything backward compatibility. meaning, that the same code can be used on both our previous boards and the new board that will use the GD IC,
4. keep using the peripherals that IC needs to run the application, (two UARTs in addition to the primary UART, Timers, PWM, ADCs etc)
4. keep using the existing build and deployment environment.

# Project Deliverables
Most possibly, the deliverables will be:
1. the new USB bootloader that can be uploaded via the on-chip serial bootloader and is compatible with the existing Maple Serial and Maple DFU computer drivers, this will enable code upload and app communication using the existing drivers,
2. an Arduino board package that enumerates an additional option to build for GD32E103CBT6 with FPU support and is compatible with the same code upload options,
3. a modified PhysLogger code that uses a system-wide c-define (most probably, a redefined F_CPU) to switch the parameters to achieve the same timing, and
4. documentation of the migration process.
