#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTextCodec>

#pragma execution_character_set("utf-8")

QString nowfile = NULL;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_clicked()
{
    QTextCodec *codeC = QTextCodec::codecForName("UTF-8");
    QTextCodec::ConverterState state;
    QString fileName = QFileDialog::getOpenFileName(
            this,
            tr("open a file."),
            "",
            tr("Windows Text(*.txt);;All files(*.*)")
    );
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Warning!", "Failed to open the file!");
    }
    else
    {

        //this->ui->textEdit->setText(fileName);
        nowfile = fileName;
        ui->addr->setText(nowfile);
        QString displayString;
        QFile file(nowfile);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
             qDebug()<< "Can't open the file!" <<endl;
        }
        QString temp;
        while (!file.atEnd())
        {
             QByteArray line = file.readLine();
             QString str(line);
             //qDebug()<< str;
             temp = codeC->toUnicode(line.constData(),line.size(),&state);
             if(state.invalidChars > 0)
             {
                 temp = QTextCodec::codecForName("GBK")->toUnicode(line);

             }
             str=temp;
             displayString.append(str);
        }
        ui->textEdit->clear();
        ui->textEdit->setText(displayString);
    }
}

void MainWindow::on_save_clicked()
{
    if (nowfile == NULL)
    {
        QString filename = QFileDialog::getSaveFileName(this,
            tr("Save a file."),
            "",
            tr("Windows Text(*.txt);;All File(*.*)")); //选择路径
        if(filename.isEmpty())
        {
            QMessageBox::warning(this, "Warning!", "Cannot save a file to NULL!");
            return;
        }
        nowfile = filename;
//        QMessageBox::warning(this, "Warning!", nowfile);
        ui->addr->setText(nowfile);
    }
//    QFile file(nowfile);
//    if(!file.open(QIODevice::WriteOnly)){
//        QMessageBox::warning(this, "Warning!", "Failed to open the file!");
//    }
////    qint64 pos;
////    pos = file.size();
////    file.seek(pos);

//    QString content = ui->textEdit->toPlainText();
//    content = content.trimmed();
//    ui->textEdit->setText(content);

//    qint64 length = -1;
//    length = file.write(content.toLocal8Bit(),content.length());

//    if(length == -1){
//        QMessageBox::warning(this, "Warning!", "Failed to write the file!");
//    }

//    //关闭文件
//    file.close();

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QFile file(nowfile);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this,"write file",tr("save file fail.%1").arg(file.errorString()));
        return;
    }
    QTextStream out(&file);
    out.setCodec("utf-8");
    out<<ui->textEdit->toPlainText().trimmed();
    file.close();
}
