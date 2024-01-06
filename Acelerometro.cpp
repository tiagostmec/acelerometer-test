#include "Acelerometro.h"
#include <iostream>
#include <fstream>
#include <sstream>
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
void Acelerometro::printData() {
    for (const auto& m : measurements) {
        std::cout << "Time Stamp (ms): " << m.time_stamp_ms << ", "
                  << "Accel X Axis: " << m.accel_x_axis << ", "
                  << "Accel Y Axis: " << m.accel_y_axis << ", "
                  << "Accel Z Axis: " << m.accel_z_axis << std::endl;
    }
}

void Acelerometro::calculateAngles() {
    for (const auto& m : measurements) {
        // Convertendo as leituras do acelerômetro para g's (considerando um fator de escala apropriado)
        // Aqui estou apenas assumindo que você tem um fator de escala. Adapte conforme sua necessidade.
        double SCALE_FACTOR = 1; //Verificar o fator de escala
        double G_px = static_cast<double>(m.accel_x_axis) * SCALE_FACTOR;
        double G_py = static_cast<double>(m.accel_y_axis) * SCALE_FACTOR;
        double G_pz = static_cast<double>(m.accel_z_axis) * SCALE_FACTOR;

        // Calcular o ângulo de pitch (phi_xyz)
        double rollAngle = atan(G_py / G_px) * 180.0 / M_PI;

        // Calcular o ângulo de roll (theta_xyz)
        double pitchAngle = atan(-G_px / sqrt(G_py * G_py + G_pz * G_pz)) * 180.0 / M_PI;
        rollAngles.push_back(rollAngle);
        pitchAngles.push_back(pitchAngle);
    }
}



void Acelerometro::saveResults(const std::string& outputFilename) {
        std::ofstream outputFile(outputFilename);
        if (!outputFile.is_open()) {
            std::cerr << "Não foi possível abrir o arquivo de saída: " << outputFilename << std::endl;
            return;
        }

        for (size_t i = 0; i < rollAngles.size(); ++i) {
            outputFile << "Roll Angle " << i + 1 << ": " << rollAngles[i] << " graus" << std::endl;
            outputFile << "Pitch Angle " << i + 1 << ": " << pitchAngles[i] << " graus" << std::endl;
            outputFile << "---------------------" << std::endl;
        }

        outputFile.close();
        std::cout << "Resultados salvos com sucesso em: " << outputFilename << std::endl;
    }
