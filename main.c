#include <stdio.h>
#include "pico/stdlib.h"
#include "neo/include/neopixel.h"
#include "display/include/display.h"
#include "buzzer/include/buzzer.h"
#include "FreeRTOS.h"
#include "task.h"
#include "joystick/include/joystick.h"
#include "button/include/button.h"
#include "rede/mqtt/include/mqtt.h"
#include "rede/wifi/include/wifi.h"
#include "led/include/led.h"
#include "event_groups.h"

char text_buffer[100];

bool conected_wifi = false;
bool conected_mqtt = false;
typedef enum {
    STATE_WIFI_DISCONNECTED,
    STATE_WIFI_CONNECTED
} wifi_connection_state_t;

typedef enum {
    STATE_MQTT_DISCONNECTED,
    STATE_MQTT_CONNECTED
} mqtt_connection_state_t;

EventGroupHandle_t xEventGroupWifi, xEventGroupMqtt;
#define WIFI_CONNECTED_BIT (1 << 0)
#define MQTT_CONNECTED_BIT (1 << 0)


void vConectWifi(void *pvParameters) {
    init_wifi(text_buffer);
    wifi_connection_state_t currentState = STATE_WIFI_DISCONNECTED;
    while (true) {
        if(currentState == STATE_WIFI_DISCONNECTED){
            if(connect_to_wifi("ssid", "password", text_buffer)){
                currentState = STATE_WIFI_CONNECTED;
                conected_wifi = true;
                xEventGroupSetBits(xEventGroupWifi, WIFI_CONNECTED_BIT);
                ofRed();
            }else{
                onRed();
                vTaskDelay(pdMS_TO_TICKS(5000)); 
            }
        }else{
            conected_wifi = is_connected();
            if (conected_wifi) {
                ofRed();
                vTaskDelay(pdMS_TO_TICKS(1000));
            } else {
                currentState = STATE_WIFI_DISCONNECTED;
                xEventGroupClearBits(xEventGroupWifi, WIFI_CONNECTED_BIT);
                xEventGroupClearBits(xEventGroupMqtt, MQTT_CONNECTED_BIT);
                conected_mqtt = false;
                onRed();
            }
        }
    }
}

void vConectMqtt(void * pvParameters){
    mqtt_connection_state_t currentState = STATE_MQTT_DISCONNECTED;
    while(true){
        xEventGroupWaitBits(xEventGroupWifi, WIFI_CONNECTED_BIT, pdFALSE, pdTRUE, portMAX_DELAY);
        onRed();
        while (conected_wifi) {
            if(currentState == STATE_MQTT_DISCONNECTED){
                mqtt_setup("bitdog5", "ip", "aluno", "senha123", text_buffer);

                int tentativas = 0;
                while (!conected_mqtt && tentativas < 50) {
                    vTaskDelay(pdMS_TO_TICKS(100));
                    tentativas++;
                }

                conected_mqtt = mqtt_is_connected();
                if(conected_mqtt){
                    currentState = STATE_MQTT_CONNECTED;
                    xEventGroupSetBits(xEventGroupMqtt, MQTT_CONNECTED_BIT);
                    ofRed();
                }else{
                    onRed();
                    vTaskDelay(pdMS_TO_TICKS(5000));
                }
            }else{
                conected_mqtt = mqtt_is_connected();
                if (conected_mqtt) {
                    ofRed();
                    vTaskDelay(pdMS_TO_TICKS(1000));
                } else {
                    currentState = STATE_MQTT_DISCONNECTED;
                    xEventGroupClearBits(xEventGroupMqtt, MQTT_CONNECTED_BIT);
                    onRed();
                }
            }
        }
        if (!conected_wifi) {
            currentState = STATE_MQTT_DISCONNECTED;
            xEventGroupClearBits(xEventGroupMqtt, MQTT_CONNECTED_BIT);
            conected_mqtt = false;
            continue;
        }
    }
}

int main() {
    stdio_init_all();
    TaskHandle_t wifi_handle, mqtt_handle;

    xEventGroupWifi = xEventGroupCreate();
    xEventGroupMqtt = xEventGroupCreate();

    xTaskCreate(vConectWifi, "Connect to wifi", 8100, NULL,1, &wifi_handle);
    xTaskCreate(vConectMqtt, "Conect Mqtt", 8100, NULL, 1, &mqtt_handle);

    vTaskCoreAffinitySet(mqtt_handle, (1 << 0));
    vTaskCoreAffinitySet(wifi_handle, (1 << 0)); 
    vTaskStartScheduler();
    while (true) {}
}
