#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_NUM0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_NUM1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_NUM2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_NUM3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_NUM4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_NUM5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_NUM6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_NUM7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_NUM8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_NUM9, SIGNAL(clicked()), this, SLOT(digit_numbers()));

    connect(ui->pushButton_NUM_sign, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_rem_from_division, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_rem_from_division->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if (ui->label->text().contains('.') && button->text() == "0")
    {
        new_label = (ui->label->text() + button->text());
    }
    else
    {
        all_numbers = (ui->label->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label_Error->setText("");
    }
    ui->label->setText(new_label);

}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;
    if (button->text() == "+/-")
    {
        all_numbers = (ui->label->text()).toDouble();
        all_numbers *= (-1);
    }
    QString new_label = QString::number(all_numbers, 'g', 15);
    ui->label->setText(new_label);
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *) sender();
    num1 = ui->label->text().toDouble();
    ui->label->setText("0");
    button->setChecked(true);
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_rem_from_division->setChecked(false);
    ui->label->setText("0");
}


void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->label->text().contains('.')))
    {
        ui->label->setText(ui->label->text() + ".");
    }
}


void MainWindow::on_pushButton_equal_clicked()
{
    double labelNum, num2;
    QString new_label;
    num2 = ui->label->text().toDouble();

    if (ui->pushButton_plus->isChecked())
    {
        labelNum = num1 + num2;
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked())
    {
        labelNum = num1 - num2;
        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_divide->isChecked())
    {
        if (num2 == 0)
        {
            ui->label_Error->setText("Помилка. Ділення на 0 неможливе.");
            ui->label_Error->setStyleSheet("color: red;");
            labelNum = 0;
        }
        else
        {
            labelNum = num1 / num2;
            ui->pushButton_divide->setChecked(false);
        }
    }
    else if (ui->pushButton_rem_from_division->isChecked())
    {
        if (num2 == 0)
        {
            ui->label_Error->setText("Помилка. Ділення на 0 неможливе.");
            ui->label_Error->setStyleSheet("color: red;");
            labelNum = 0;
        }
        else
        {
            int a = static_cast<int>(num1) % static_cast<int>(num2);
            labelNum = a;
            ui->pushButton_rem_from_division->setChecked(false);
        }
    }
    else if (ui->pushButton_multiply->isChecked())
    {
        labelNum = num1 * num2;
        ui->pushButton_multiply->setChecked(false);
    }
    new_label = QString::number(labelNum, 'g', 15);
    ui->label->setText(new_label);
}

