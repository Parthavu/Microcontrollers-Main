#include <Arduino.h>

TaskHandle_t Task1, Task2;



void Task1code(void *parameter) //Core 0
{
    for (;;)
    {
        
    }
}

void Task2code(void *parameter) //Core 1
{
    for (;;)
    {
    
    }
}

void setup(){
    
    xTaskCreatePinnedToCore(
        Task1code,
        "Task1",
        10000,
        NULL,
        0,
        &Task1,
        0
    );

    xTaskCreatePinnedToCore(
        Task2code,
        "Task2",
        10000,
        NULL,
        0,
        &Task2,
        0
    );

}

void loop(){}