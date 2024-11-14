#include <unity.h>
#include "main.h"
#include "LED.h"
#include "PushButton.h"

void setUp(void) {
    LED_Init(LED0);
    PushB_Init(PushB0);
}

void tearDown(void) {
    // Reset hardware state
}

void test_button_press_led_on(void) {
    // Simulate button press
    TEST_ASSERT_EQUAL(1, Read_PushB(PushB0));
    // Verify LED turns on
    TEST_ASSERT_EQUAL(HIGH, LED_GetState(LED0));
}

void test_button_release_led_off(void) {
    // Simulate button release
    TEST_ASSERT_EQUAL(0, Read_PushB(PushB0));
    // Verify LED turns off  
    TEST_ASSERT_EQUAL(LOW, LED_GetState(LED0));
}

void test_button_toggle_sequence(void) {
    // Test sequence of button presses
    TEST_ASSERT_EQUAL(0, Read_PushB(PushB0));
    TEST_ASSERT_EQUAL(LOW, LED_GetState(LED0));
    
    TEST_ASSERT_EQUAL(1, Read_PushB(PushB0)); 
    TEST_ASSERT_EQUAL(HIGH, LED_GetState(LED0));
    
    TEST_ASSERT_EQUAL(0, Read_PushB(PushB0));
    TEST_ASSERT_EQUAL(LOW, LED_GetState(LED0));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_button_press_led_on);
    RUN_TEST(test_button_release_led_off); 
    RUN_TEST(test_button_toggle_sequence);
    return UNITY_END();
}
