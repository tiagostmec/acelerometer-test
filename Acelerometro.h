#ifndef ACELEROMETRO_H
#define ACELEROMETRO_H

#include <vector>
#include <string>

struct Measurement {
    int time_stamp_ms;
    int accel_x_axis;
    int accel_y_axis;
    int accel_z_axis;
};

class Acelerometro {
public:
    Acelerometro(const std::string& filename);
    bool loadData();
    void calculateAngles();
    void saveResults(const std::string& outputFilename);
    std::vector<double> getRollAngle() const { return rollAngles; }
    std::vector<double> getPitchAngle() const { return pitchAngles; }
    std::vector<double> getTimeStamp() const { return TimeStamp; }

private:
    std::string filename;
    std::vector<Measurement> measurements;
    std::vector<double> rollAngles;
    std::vector<double> pitchAngles;
    std::vector<double> TimeStamp;
};

#endif // ACELEROMETRO_H
