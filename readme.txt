*** BLE MIDI service for nRF51 chips by Nordic. ***

BLE MIDI is a specifation for MIDI over BLE (or Bluetooth Smart) by Apple, defined here: 
https://developer.apple.com/bluetooth/Apple-Bluetooth-Low-Energy-MIDI-Specification.pdf

Status: There's support for sending MIDI events to, for example Garageband, but I haven't tried receiving anything. 

The good people at Nordic have managed to produce some pretty hideous makefiles, so I just use the scons build system instead. I've found it to be a great replacement for make.

A lot of the code is copy/pasted from example projects so don't expect this to be a super clean lib, feel free to fork and improve.

** Prerequisites **

- A gcc-arm compiler, I've used gcc-arm-none-eabi-4_9-2015q3
- The nRF51 SDK, version 10
- The nRF51-DK devkit
- scons

** Setup **
Edit SConstruct and change sdkdir to your nRF51 SDK path and TOOLCHAIN to your gcc-arm toolchain

** Building **
Just run "scons" and you should be done.

** Running **
Plug in your devkit board and run "scons flash"
Open up Garageband on your Apple device and select Bluetooth midi devices in the settings menu. You should see your devkit and be able to connect to it.

Hit Button 1 and the devkit and a midi note should be sent.
