#include <iostream>
#include "roboflex_core/core.h"
#include "roboflex_core/core_nodes/core_nodes.h"
#include "roboflex_webcam_uvc/webcam_uvc.h"

using namespace roboflex;

int main()
{
    auto webcam = webcam_uvc::WebcamSensor(800, 600, 20, 1, UVC_FRAME_FORMAT_ANY);
    webcam.print_device_info();
    auto message_printer = nodes::MessagePrinter();
    webcam > message_printer;

    webcam.start();
    core::sleep_ms(5000);
    webcam.stop();

    std::cout << "DONE" << std::endl;
    return 0;
}