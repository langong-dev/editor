#ifndef OPENFILE_H
#define OPENFILE_H

#include <QDialog>

namespace Ui {
class OpenFile;
}

class OpenFile : public QDialog
{
    Q_OBJECT

public:
    explicit OpenFile(QWidget *parent = nullptr);
    ~OpenFile();

private:
    Ui::OpenFile *ui;
};

#endif // OPENFILE_H
