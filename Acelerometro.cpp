#include "Acelerometro.h"
#include <iostream>
#include <fstream>
#include <cmath>

Acelerometro::Acelerometro(const std::string& filename) : filename(filename) {}

bool Acelerometro::loadData() {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        Measurement m;
        if (sscanf(line.c_str(), "%d; %d; %d; %d", &m.time_stamp_ms, &m.accel_x_axis, &m.accel_y_axis, &m.accel_z_axis) == 4) {
            measurements.push_back(m);
        } else {
            std::cerr << "Erro ao ler a linha: " << line << std::endl;
        }
    }
    inputFile.close();

    if (measurements.empty()) {
        std::cerr << "Nenhuma medida válida foi encontrada no arquivo." << std::endl;
        return false;
    }

    std::cout << "Dados carregados com sucesso." << std::endl;
    return true;
}

void Acelerometro::calculateAngles() {
    for (const auto& m : measurements) {
        // Convertendo as leituras do acelerômetro para g's (considerando um fator de escala apropriado)
        double SCALE_FACTOR = 1; //escala cedida no exericio de mg
        double G_px = static_cast<double>(m.accel_x_axis) * SCALE_FACTOR;
        double G_py = static_cast<double>(m.accel_y_axis) * SCALE_FACTOR;
        double G_pz = static_cast<double>(m.accel_z_axis) * SCALE_FACTOR;
        double timestamp = m.time_stamp_ms;
        double sign = 1;
        double mi = 0.01;

        // Calcular o ângulo de roll (phi_xyz)
        if (G_pz >= 0){
            sign = 1;
        };
        if (G_pz < 0){
            sign = -1;
        };
        double rollAngle = atan(G_py / (sign*sqrt(G_pz*G_pz + mi*G_px))) * 180.0 / M_PI;

        // Calcular o ângulo de pitch (theta_xyz)
        double pitchAngle = atan(-G_px / sqrt(G_py * G_py + G_pz * G_pz)) * 180.0 / M_PI;
        rollAngles.push_back(rollAngle);
        pitchAngles.push_back(pitchAngle);
        TimeStamp.push_back(timestamp);
    }
}



void Acelerometro::saveResults(const std::string& outputFilename) {
        std::ofstream outputFile(outputFilename);
        if (!outputFile.is_open()) {
            std::cerr << "Não foi possível abrir o arquivo de saída: " << outputFilename << std::endl;
            return;
        }

        for (size_t i = 0; i < rollAngles.size(); ++i) {
            outputFile << "TimeStamp " << ": " << TimeStamp[i] << " ms" << std::endl;
            outputFile << "Roll Angle "  << ": " << rollAngles[i] << "°" << std::endl;
            outputFile << "Pitch Angle "  << ": " << pitchAngles[i] << "°" << std::endl;
            outputFile << "---------------------" << std::endl;
        }

        outputFile.close();
        std::cout << "Resultados salvos com sucesso em: " << outputFilename << std::endl;
    }
