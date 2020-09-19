#include "openfile.h"
#include "ui_openfile.h"

OpenFile::OpenFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenFile)
{
    ui->setupUi(this);
}

OpenFile::~OpenFile()
{
    delete ui;
}
