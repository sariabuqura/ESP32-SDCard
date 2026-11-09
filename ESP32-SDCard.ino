
#include <SPI.h>
#include <SD.h>

#define SD_CS 5

SPIClass sdSPI(VSPI);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("HW-125 SD Card Test");

  sdSPI.begin(18, 19, 23, SD_CS);

  if (!SD.begin(SD_CS, sdSPI, 1000000)) {
    Serial.println("SD initialization FAILED!");
    return;
  }

  Serial.println("SD initialization SUCCESS!");

  Serial.print("Card size: ");
  Serial.print(SD.cardSize() / (1024 * 1024));
  Serial.println(" MB");

  File file = SD.open("/hello.txt", FILE_WRITE);

  if (file) {
    file.println("Hi from ESP32!");
    file.close();
    Serial.println("File written successfully!");
  } else {
    Serial.println("File creation failed!");
  }
}

void loop() {
}
