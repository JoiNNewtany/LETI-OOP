#include <sstream>
#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "polynomial.hpp"

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
    std::stringstream output;

    // Initialize polynomial
    number a(ui->doubleSpinBox_ar->value(), ui->doubleSpinBox_ai->value());
    number b(ui->doubleSpinBox_br->value(), ui->doubleSpinBox_bi->value());
    number c(ui->doubleSpinBox_cr->value(), ui->doubleSpinBox_ci->value());

    Polynomial poly(a, b, c);

    // Print text form
    output << "Input: " << poly << '\n';

    // Calculate roots
    number roots[2];
    switch (poly.findRoots(roots)) {
    case 0:
        output << "Two complex roots exist: "
               << roots[0] << "; " << roots[1];
        break;
    case 1:
        output << "One real root exists: "
               << roots[0];
        break;
    case 2:
        output << "Two real roots exist: "
               << roots[0] << "; " << roots[1];
        break;
    default:
        output << "Unable to calculate roots.";
        break;
    }
    output << '\n';

    // Calculate argument
    output << "Polynomial value: "
           << poly.findValue(number(ui->doubleSpinBox_argr->value(),
                                    ui->doubleSpinBox_argi->value()))
           << '\n';

    ui->resultTextEdit->setPlainText(QString::fromUtf8(output.str()));
    ui->statusbar->showMessage("Done!");
}
