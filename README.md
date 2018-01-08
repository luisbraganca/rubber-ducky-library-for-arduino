# Rubber Ducky library for Arduino

A library with scripts to use an arduino as a rubber ducky

## Device used

Arduino Leonardo Mini with USB adapter

![Arduino leonardo mini with USB adapter](https://raw.githubusercontent.com/luisbraganca/rubber-ducky-library-for-arduino/master/Screenshots/device.jpg)

## What's a Rubber Ducky?

"The USB Rubber Ducky is a keystroke injection tool disguised as a generic flash drive. Computers recognize it as a regular keyboard and accept pre-programmed keystroke payloads at over 1000 words per minute." Taken from [Hak5 Gear](https://hakshop.com/products/usb-rubber-ducky-deluxe).

## Why using an Arduino instead of a Rubber Ducky?

### Price

Rubber Ducky: $44.99

Arduino Leonardo Mini: $4.22 (no it's not a mistake)

### Customization

Rubber Ducky: ???

Arduino Leonardo Mini: Switches, Memory Card, Wifi, etc...

If you're interested in building one from scratch with switches and such, take a look at [Seytonic's youtube channel](https://www.youtube.com/channel/UCW6xlqxSY3gGur4PkGPEUeA), or you can simply buy a pre-built one from [his store](https://shop.malduino.com).

## Technical details

This library allows you to use an Arduino Leonardo as a Rubber Ducky(https://hakshop.com/products/usb-rubber-ducky-deluxe) with pre-built methods to simplify your keyboard script coding.

### Methods

#### Utilities

```arduino
/**
 * Prepares the virtual keyboard.
 * This method should be the first instruction on the setup code block.
 */
void init();
```

```arduino
/**
 * Ends the virtual keyboard.
 * This method should be the last instruction on the setup code block.
 */
void finish();
```

#### Library

