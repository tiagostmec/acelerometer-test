#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selectLogFileButtonClicked();
    void selectOutputFileButtonClicked();
    void startButtonClicked();

private:
    Ui::MainWindow *ui;
    QString logFilePath;
    QString outputFilePath;
};

#endif // MAINWINDOW_H
