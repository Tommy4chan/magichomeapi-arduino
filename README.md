
# MagicHomeApi Arduino

MagicHome Wifi protocol for Arduino like boards.

This library was designed for use with devices compatible with the MagicHome Wifi app.

## It currently supports

- RGB Controllers
- RGB+WW Controllers
- ARGB Controllers

## Commands

- Turning devices on and off
- Setting colors (rgb, rgbw,ARGB) + brightness
- Sending preset functions

## Usage/Examples

Create new object (You may find ip of controller in your router admin panel)
```cpp
MagicHomeApi Led("IP Address", 5577);
```
Turn device on
```cpp
Led.TurnOn();
```
Turn device off
```cpp
Led.TurnOff();
```
Set led color (r, g, b, w must be in range from 0 to 255, if not there is filter function), 
(brightness must be in range from 0 to 100)
```cpp
Led.SetColor(r, g, b, w, brightness);
Led.SetColorARGB(r, g, b, brightness);
```
Set preset function (speed must be in range from 0 to 100)

preset_number:
- 37 = Seven color cross fade
- 38 = Red gradual change
- 39 = Green gradual change
- 40 = Blue gradual change
- 41 = Yellow gradual change
- 42 = Cyan gradual change
- 43 = Purple gradual change
- 44 = White gradual change
- 45 = Red green cross fade
- 46 = Red blue cross fade
- 47 = Green blue cross fade
- 48 = Seven color strobe flash
- 49 = Red strobe flash
- 50 = Green strobe flash
- 51 = Blue stobe flash
- 52 = Yellow strobe flash
- 53 = Cyan strobe flash
- 54 = Purple strobe flash
- 55 = White strobe flash
- 56 = Seven color jumping
```cpp
Led.SetPresetFunction(preset_number, speed);
Led.SetPresetFunctionARGB(preset_number, speed, brightness);
```

## Feedback

If you have any feedback, all contact information is in my github profile

## Author

- [@Tommy4chan](https://github.com/Tommy4chan)

## Contributors

- [@Raphitech](https://github.com/Raphitech)

Copyright 2022 Anton Panurin (Tommy4chan). Licensed under MIT.
