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
    void printData();
    std::vector<double> getRollAngle() const { return rollAngles; }
    std::vector<double> getPitchAngle() const { return pitchAngles; }

private:
    std::string filename;
    std::vector<Measurement> measurements;
    std::vector<double> rollAngles;
    std::vector<double> pitchAngles;

};

#endif // ACELEROMETRO_H
