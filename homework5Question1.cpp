// Martin Wu Question 1

#include <iostream>
using namespace std;

class BicycleSpeedometer {
private:
    double distance;
    double time; 

public:
    BicycleSpeedometer() {
        distance = 0.0;
        time = 0.0;
    }
    void setDistance(double d) {
        distance = d;
    }
    void setTime(double t) {
        time = t;
    }
    double getDistance() const {
        return distance;
    }
    double getTime() const {
        return time;
    }
    double computeAverageSpeed() const {
 
        double timeInHours = time / 60.0;
        return distance / timeInHours;
    }
};

int main() {
    BicycleSpeedometer speedometer;
    double distance, time;

    cout << "Enter distance traveled (miles): ";
    cin >> distance;
    cout << "Enter time taken (minutes): ";
    cin >> time;

    speedometer.setDistance(distance);
    speedometer.setTime(time);
 
    cout << "Distance:      " << speedometer.getDistance() << " miles" << endl;
    cout << "Time:          " << speedometer.getTime() << " minutes" << endl;
    cout << "Average Speed: " << speedometer.computeAverageSpeed() << " mph" << endl;

    return 0;
}