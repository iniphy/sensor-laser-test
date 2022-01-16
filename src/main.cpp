#include <RecFusion.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
using namespace RecFusion;

#define TURN_ON(sensor) if (!(sensor).setLaserState(true)) { \
    cerr << "Failed to turn on the laser" << endl; \
}


#define TURN_OFF(sensor) if (!(sensor).setLaserState(false)) { \
    cerr << "Failed to turn off the laser" << endl; \
}

int main() {
    cout << "----- Sensor-laser-test. Welcome! -----" << endl;

    // Check for number of connected sensors
    cout << "Finding out how many sensors are connected..." << endl;
    Sensor initial_sensor;
    int numSensors = initial_sensor.deviceCount();
    if (numSensors == 0) {
        cerr << "No sensors are connected. Feed me please." << endl;
        return EXIT_FAILURE;
    } else {
        cout << "Found " << numSensors << " connected sensors." << endl;
    }

    // Opening all sensors
    cout << "Opening " << numSensors << " sensors..." << endl;
    vector sensors<Sensor>(numSensors);

    for (int k = 0; k < numSensors; k++) {
        Sensor new_sensor;
        new_sensor.open(k);
        if (new_sensor.isOpen()) {
            cout << "Sensor (id=" << k << ") opened successfully." << endl;
        } else {
            cerr << "Error opening sensor (id=" << k << ")." << endl;
            return EXIT_FAILURE;
        }
        sensors.push_back(new_sensor);
    }

    // Perform calibration (x5 1 second blink)
    cout << "Performing calibration (x5 of 1 second blinking) for each sensor." << endl;
    for (int k = 0; k < numSensors; ++k) {
        cout << "Blinking sensor (id=" << k << ")." << endl;
        for (int x = 0; x < 5; ++x) {
            TURN_ON(sensors[k])
            // sleep 1000 ms
            this_thread::sleep_for(chrono::milliseconds(1000));
            TURN_OFF(sensors[k])
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    }

    // Performing fast laser on/off
    cout << "Performing fast laser on/off (x5 events each after 5 seconds)." << endl;
    for (int k = 0; k < numSensors; ++k) {
        cout << "Fast laser on/off for sensor (id=" << k << ")." << endl;
        for (int x = 0; x < 5; ++x) {
            TURN_ON(sensors[k])
            TURN_OFF(sensors[k])
            this_thread::sleep_for(chrono::milliseconds(5000));
        }
    }
    cout << "Testing sequence completed." << endl;
    return EXIT_SUCCESS;
}
