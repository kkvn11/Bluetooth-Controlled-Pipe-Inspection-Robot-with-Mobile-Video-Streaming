#include <hidef.h>      // Common defines and macros
#include "derivative.h" // Derivative-specific definitions
#include "HX1.h"
#include "HX2.h"
#include "PWM.h"
#include "lanya.h"

int ii, i;

void main(void) {
    lanyachushihua();
    PWM_initial(); // Initialize PWM
    yali1();       // Read pressure sensor 1
    yali2();       // Read pressure sensor 2

    while (1) {
        char lanya = SCI_receive(); // Receive command from Bluetooth

        switch (lanya) {
            case '1': // Start movement sequence
                yali1();
                a_zhang(); // Arm extend
                while (hx1 > 6800000) {
                    yali1(); // Wait until pressure below threshold
                }
                a_ting(); // Stop arm
                for (ii = 0; ii < 7; ii++) {
                    b_houtui(); // Perform backward movement
                    delay(200);
                    delay(200);
                    delay(200);
                    delay(200);
                    delay(200);
                }
                break;

            default:
                // No action
                break;
        }
    }
}
