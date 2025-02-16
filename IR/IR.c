#include "IR.h"

IRStatus Get_IR_Status(void) {
    if (LEFT_SENSOR == 0 && RIGHT_SENSOR == 0) {
        return FORWARD;
    } else if (LEFT_SENSOR == 1 && RIGHT_SENSOR == 0) {
        return LEFT;
    } else if (LEFT_SENSOR == 0 && RIGHT_SENSOR == 1) {
        return RIGHT;
    } else if (LEFT_SENSOR == 1 && RIGHT_SENSOR == 1) {
        return STOP;  // You can modify this to BACKWARD if needed
    }
    return STOP;
}