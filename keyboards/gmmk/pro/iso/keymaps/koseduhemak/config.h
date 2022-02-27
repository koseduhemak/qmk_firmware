#if defined(IDLE_TIMEOUT_ENABLE) && defined(RGB_MATRIX_ENABLE)
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGBLIGHT_SLEEP
#endif

#ifdef IDLE_TIMEOUT_ENABLE
    #define TIMEOUT_THRESHOLD_DEFAULT 1  // default timeout minutes
    #define TIMEOUT_THRESHOLD_MAX 15     // upper limits (2 hours and 10 minutes -- no rgb indicators above this value)

    // prototype  functions
    uint16_t get_timeout_threshold(void);
    void     timeout_reset_timer(void);
    void     timeout_update_threshold(bool increase);
    void     timeout_tick_timer(void);
#endif  // IDLE_TIMEOUT_ENABLE