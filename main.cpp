#include "Acelerometro.h"

int main() {
    Acelerometro acelerometro("/home/tiago/acelerometer/attitude_exam.log");
    if (acelerometro.loadData()) {
        acelerometro.calculateAngles();
        //acelerometro.printData(); // Imprimir os dados lidos "DEBUG CHOICE"
        acelerometro.saveResults("resultados.txt");
    }
    return 0;
}

