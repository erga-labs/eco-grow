#ifndef OTA_H
#define OTA_H

#include <WiFi.h>
#include <HTTPClient.h>
#include <Update.h>
#include "secrets.h"  
bool performOTAUpdate();

#endif