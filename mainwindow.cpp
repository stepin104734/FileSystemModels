#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pb_browseClicked()));
    list_model = new QFileSystemModel();
    tree_model = new QFileSystemModel();
    table_model = new QFileSystemModel();
    list_model->setFilter(QDir::Files);
    table_model->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pb_browseClicked()
{
    QString m_path = QFileDialog::getExistingDirectory();
    ui->lineEdit->setText(m_path);

    ui->listView->setModel(list_model);
    ui->listView->setRootIndex(list_model->setRootPath(m_path));

    ui->treeView->setModel(tree_model);
    ui->treeView->setRootIndex(tree_model->setRootPath(m_path));

    ui->tableView->setModel(table_model);
    ui->tableView->setRootIndex(table_model->setRootPath(m_path));
    ui->tableView->setColumnHidden(1,1);
    ui->tableView->setColumnHidden(2,1);


}

