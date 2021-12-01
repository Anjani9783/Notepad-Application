#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    mFilename = "";
    ui->textEdit->setPlainText("");
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open File");
    if(!file.isEmpty())
    {
        QFile aFile(file);
        if(aFile.open(QFile::ReadOnly | QFile::Text))
        {
            mFilename = file;
            QTextStream in(&aFile);
            QString text = in.readAll();
            aFile.close();

            ui->textEdit->setPlainText(text);

        }
    }
}


void MainWindow::on_actionSave_triggered()
{
    QFile aFile(mFilename);
    if(aFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&aFile);
        out << ui->textEdit->toPlainText();
        aFile.flush();
        aFile.close();
    }
}


void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Open File");
    if(!file.isEmpty())
    {
       mFilename = file;
       on_actionSave_triggered();
    }
}


void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionBold_triggered()
{
       ui->textEdit->setFontWeight(QFont::Bold);
}


void MainWindow::on_actionUnbold_triggered()
{
    ui->textEdit->setFontWeight(QFont::Normal);
}


void MainWindow::on_actionSubscript_triggered()
{
     QTextCharFormat script;
     script.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
     if(ui->textEdit->hasFocus())
      ui->textEdit->mergeCurrentCharFormat(script);
}


void MainWindow::on_actionSuperscript_triggered()
{
    QTextCharFormat script;
    script.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    if(ui->textEdit->hasFocus())
     ui->textEdit->mergeCurrentCharFormat(script);
}


void MainWindow::on_actionAbout_triggered()
{
    QLabel *label = new QLabel();

        label->setGeometry(0, 0, 1200, 900);
        label->setText("<h1>Anjani Kumar Agrawal</h1><br>\
                       <b>Email:</b> anjaniagrawal9783@gmail.com<br><b>Phone: </b> 9783049783<br>\
                       <h2>Education</h2><br>\
                       <table>\
                       <tr>\
                         <th>Year</th>\
                         <th>Course</th>\
                         <th>Instiute</th>\
                         <th>Percentage/CGPA</th>\
                       </tr>\
                       <tr>\
                       <td>2018-2022</td>\
                       <td>B.E.(Computer Science Engineering)</td>\
                       <td>University Institute of Technology - Barkatullah University</td>\
                       <td>8.24</td>\
                     </tr>\
                     <tr>\
                       <td>2018</td>\
                       <td>Higher Secondary</td>\
                       <td>St. Joseph's Mission School, Bijuri</td>\
                       <td>6.5</td>\
                     </tr>\
                     <tr>\
                       <td>2015</td>\
                       <td>10th </td>\
                       <td>St. Joseph's Mission School, Bijuri</td>\
                       <td>7.8</td>\
                     </tr>\
                     </table>\
<h2>Projects</h2><br><b>Smart Irrigation System</b><br><p>It is an IoT Project made to automate the irrigation system using various parameters like temperature, humididty and soil moisture.</p><br><b>Mini AI tool</b><br><p>It is a web application provides various services like OCR and Youtube mp4 & mp3 downloader.</p><br><h2>Key Skills</h2><br><p><ul><li>Proficient in C++</li><li>Front End Technology</li></ul>");
        label->show();
}

