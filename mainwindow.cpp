#include <sstream>
#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "polynomial.hpp"
#include "complex.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Enter polynomial values and press 'Calculate'.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
    // Initialize and calculate polynomial
    if(ui->radio_real->isChecked())
    {
        double a = ui->doubleSpinBox_ar->value();
        double b = ui->doubleSpinBox_br->value();
        double c = ui->doubleSpinBox_cr->value();
        double arg = ui->doubleSpinBox_argr->value();
        calculate(a, b, c, arg);
    }
    else
    {
        Complex a(ui->doubleSpinBox_ar->value(), ui->doubleSpinBox_ai->value());
        Complex b(ui->doubleSpinBox_br->value(), ui->doubleSpinBox_bi->value());
        Complex c(ui->doubleSpinBox_cr->value(), ui->doubleSpinBox_ci->value());
        Complex arg(ui->doubleSpinBox_argr->value(), ui->doubleSpinBox_argi->value());
        calculate(a, b, c, arg);
    }
}

template<class T>
void MainWindow::calculate(T a, T b, T c, T arg)
{
    std::stringstream output;
    T roots[2];
    Polynomial<T> poly(a, b, c);

    // Print text form
    output << "Input: " << poly << '\n';

    // Calculate roots
    switch (poly.findRoots(roots)) {
    case 1:
        output << "One root exists: "
               << roots[0];
        break;
    case 2:
        if (!(roots[0] == roots[0])) {
            output << "No real roots exist";
            break;
        }
        output << "Two roots exist: "
               << roots[0] << "; " << roots[1];
        break;
    default:
        output << "Unable to calculate roots.";
        break;
    }
    output << '\n';

    // Calculate argument
    output << "Polynomial value: "
           << poly.findValue(arg)
           << '\n';

    ui->resultTextEdit->setPlainText(QString::fromUtf8(output.str()));
    ui->statusbar->showMessage("Done!");
}
