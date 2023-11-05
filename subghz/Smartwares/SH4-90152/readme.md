Simple 4-channel 433.92mhz remote from Smartwares

* The 'ALL' on/off function only sends the 4 button commands after each other, so i've added that as a subplaylist + subghz_remote

Key is as follows
* 00 00 00 00 31 0F 00 11 (last bytes = state -> id, in this case ON -> channel 1)

Other keys are
```
* 00 00 00 00 31 0F 00 12
* 00 00 00 00 31 0F 00 13
* 00 00 00 00 31 0F 00 14

or for turning off

* 00 00 00 00 31 0F 00 02
* 00 00 00 00 31 0F 00 03
* 00 00 00 00 31 0F 00 04
```

![alt text](https://www.smartwares.eu/product/image/large/sh4-90152_0.jpg)
https://www.smartwares.eu/nl-nl/smartwares-sh4-90152-4-kanaals-afstandsbediening-sh4--90152
