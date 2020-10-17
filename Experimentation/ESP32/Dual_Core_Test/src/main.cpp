#include <Arduino.h>

#define LED1 12
#define LED2 25

TaskHandle_t Task1, Task2;
SemaphoreHandle_t baton;

int counter = 0;

void blink(byte pin, int duration)
{

    digitalWrite(pin, HIGH);
    delay(duration);
    digitalWrite(pin, LOW);
    delay(duration);
}

void codeForTask1(void *parameter)
{
    for (;;)
    {
        xSemaphoreTake(baton, portMAX_DELAY);
        blink(LED1, 1000);
        xSemaphoreGive(baton);
        delay(50);
        Serial.print("Counter in Task 1: ");
        Serial.println(counter);
        counter++;
    }
}

void codeForTask2(void *parameter)
{
    for (;;)
    {
        xSemaphoreTake(baton, portMAX_DELAY);
        blink(LED2, 1000);
        xSemaphoreGive(baton);
        delay(50);
        Serial.print("Counter in Task 2: ");
        Serial.println(counter);
        counter++;
    }
}

// the setup function runs once when you press reset or power the board
void setup()
{
    Serial.begin(115200);
    // initialize digital pin LED_BUILTIN as an output.

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);

    baton = xSemaphoreCreateMutex();

    // A viewer suggested to use :     &codeForTask1, because his ESP crashed

    xTaskCreatePinnedToCore(
        codeForTask1,
        "led1Task",
        1000,
        NULL,
        1,
        &Task1,
        0);
    delay(500); // needed to start-up task1

    xTaskCreatePinnedToCore(
        codeForTask2,
        "led2Task",
        1000,
        NULL,
        1,
        &Task2,
        1);
}

void loop()
{

    delay(10);
}