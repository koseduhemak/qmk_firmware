#pragma once
#define ARRAYSIZE(arr)  sizeof(arr)/sizeof(arr[0])

void highlight_fkeys(void) {
    // only F-keys. Do not highlight ESC and PRINT
    for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_FN1); i++) {
        rgb_matrix_set_color(LED_LIST_FN1[i], RGB_RED);
    }
}

void highlight_capslock(void) {
    rgb_matrix_set_color(LED_CAPS, RGB_RED);
}