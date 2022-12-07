#include "MagicHomeApi.h"

MagicHomeApi::MagicHomeApi(char *host_led, uint16_t port_led)
{
  host = host_led;
  port = port_led;
}

void MagicHomeApi::ClientConnect(){
  while(!client.connect(host, port))
  {
    Serial.println("Connection to host failed");
    delay(1000);
  }
  
  Serial.println("Connected to server successful!");
}

void MagicHomeApi::ClientDisconnect(){
  client.stop();
}
  
void MagicHomeApi::ClientGetResponse(){
  while (client.available() > 0)
  {
    char c = client.read();
    Serial.write(c);
  }
  Serial.print('\n');
}

void MagicHomeApi::TurnOn(){
  int len = 4;
  byte b[len] = {0x71, 0x23, 0x0F, 0xA3};
  SendData(b, len);
}

void MagicHomeApi::TurnOff(){
  int len = 4;
  byte b[len] = {0x71, 0x24, 0x0F, 0xA4};
  SendData(b, len);
}

void MagicHomeApi::SetColor(int r, int g, int b, int w, int brightness){
  int len = 8;
  byte data[len] = {0x31, BrightnessLevel(CheckRange(0, 255, r), brightness), BrightnessLevel(CheckRange(0, 255, g), brightness), 
  BrightnessLevel(CheckRange(0, 255, b), brightness), BrightnessLevel(CheckRange(0, 255, w), brightness), 0x00, 0x0f, 0x00};
  int sum = 0;
  for(int i = 0; i < 7; i++){
    sum += data[i];
  }
  data[7] = sum&0xFF;
  SendData(data, len);
}

void MagicHomeApi::SetColorARGB(int r, int g, int b, int brightness){
  int len = 13;
  byte data[len] = {0x41,0x01, BrightnessLevel(CheckRange(0, 255, r), brightness), BrightnessLevel(CheckRange(0, 255, g), brightness), 
  BrightnessLevel(CheckRange(0, 255, b), brightness),0x00,0x00,0x00,0x32,0x00,0x00,0xf0,0xe4};
  int sum = 0;
  for(int i = 0; i < 7; i++){
    sum += data[i];
  }
  data[13] = sum&0xFF;
  SendData(data, len);
}

void MagicHomeApi::SetPresetFunction(int f_number, int speed){
  int len = 5;
  byte data[len] = {0x61, CheckRange(37, 56, f_number), CheckRange(0, 100, 100-speed), 0x0F, 0x00};
  int sum = 0;
  for(int i = 0; i < 4; i++){
    sum += data[i];
  }
  data[4] = sum&0xFF;
  SendData(data, len);
}

void MagicHomeApi::SetPresetFunctionARGB(int f_number, int speed, int brightness){
  int len = 5;
  byte data[len] = {0x42, CheckRange(01, 74, f_number), CheckRange(0, 100, 100-speed), brightness, 0x1c};
  int sum = 0;
  for(int i = 0; i < 4; i++){
    sum += data[i];
  }
  data[4] = sum&0xFF;
  SendData(data, len);
}

void MagicHomeApi::SendData(byte data[], int len){
  ClientConnect();
  Serial.println("Data:");
  for(int i = 0; i < 5; i++){
    Serial.println(data[i]);
  }
  Serial.println("Data length:");
  client.write(data, len);
  ClientDisconnect();
}

int MagicHomeApi::CheckRange(int min, int max, int value){
  if(min > value){
    value = min;
  }
  else if(max < value){
    value = max;    
  }

  return value;
}

int MagicHomeApi::BrightnessLevel(int value, int brightness){
  return (value/100) * brightness;
}