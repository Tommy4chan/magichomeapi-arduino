/*
  MagicHomeApi.h - Library for local communicating with MagicHome LED strip controller.
  It support rgbw version only but in future may have an update.
  Created by Anton Panurin(Tommy4chan), October 17, 2022.
*/
#ifndef MagicHomeApi_h
#define MagicHomeApi_h

#include "Arduino.h"
#include <WiFiClient.h>

class MagicHomeApi
{
  public:
    MagicHomeApi(char *host_led, uint16_t port_led);
    void ClientConnect();
    void ClientDisconnect();
    void ClientGetResponse();
    void TurnOn();
    void TurnOff();
    void SetColor(int r, int g, int b, int w, int brightness);
    void SetPresetFunction(int f_number, int speed);
    void SendData(byte data[], int len);
    int CheckRange(int min, int max, int value);
    int BrightnessLevel(int value, int brightness);
  private:
    WiFiClient client;
    char *host;
    uint16_t port;
};

#endif