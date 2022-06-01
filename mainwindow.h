#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QFileSystemModel *list_model;
    QFileSystemModel *tree_model;
    QFileSystemModel *table_model;

private:
    Ui::MainWindow *ui;

private slots:
   void pb_browseClicked();

};
#endif // MAINWINDOW_H
