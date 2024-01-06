#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Acelerometro.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow())
{
    ui->setupUi(this);
    connect(ui->selectLogFileButton, &QPushButton::clicked, this, &MainWindow::selectLogFileButtonClicked);
    connect(ui->selectOutputFileButton, &QPushButton::clicked, this, &MainWindow::selectOutputFileButtonClicked);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectLogFileButtonClicked()
{
    logFilePath = QFileDialog::getOpenFileName(this, "Selecionar arquivo de log", "", "Log Files (*.log)");
    if (!logFilePath.isEmpty()) {
        ui->label->setText(logFilePath);  // Usando o label do ui_mainwindow.h
    }
}

void MainWindow::selectOutputFileButtonClicked()
{
    outputFilePath = QFileDialog::getSaveFileName(this, "Selecionar local para salvar", "", "Text Files (*.txt)");
    if (!outputFilePath.isEmpty()) {
        ui->label_2->setText(outputFilePath);  // Usando o segundo label do ui_mainwindow.h
    }
}

void MainWindow::startButtonClicked()
{
    Acelerometro acelerometro(logFilePath.toStdString());
    if (acelerometro.loadData()) {
        acelerometro.calculateAngles();
        acelerometro.saveResults(outputFilePath.toStdString());
        QMessageBox::information(this, "Concluído", "Dados calculados e salvos com sucesso.");
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao carregar dados do arquivo de log.");
    }
}
