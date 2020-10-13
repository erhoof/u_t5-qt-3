#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "harddrive.h"

#include "HardDriveTableModel.h"
#include "NewRequestsModel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Init Hard Drive
    HardDriveInfo info;
    info.m_accessTime = 2000;
    info.m_rotationDelay = 1000;
    info.m_transferSpeed = 1000;
    info.m_cylinders = 5;
    info.m_heads = 1;
    info.m_sectors = 10;

    m_hardDrive = new HardDrive(info);

    // Init models
    m_hardDriveModel = new HardDriveTableModel(nullptr, m_hardDrive);
    m_newReqModel = new NewRequestsModel();

    // Hard Drive Scheme Table View
    ui->tableView->setModel(m_hardDriveModel);
    connect(m_hardDrive, &HardDrive::dataChanged, m_hardDriveModel, &HardDriveTableModel::updateData);

    // Set sizing
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->show();

    // New Requests List
    ui->listView_new->setModel(m_newReqModel);
    ui->listView_new->show();

    timerId = startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRequest()
{
    RequestModel newReq;
    newReq.id = m_curId;
    newReq.creationTime = QTime::currentTime();
    newReq.finishTime = newReq.creationTime;
    newReq.filename = randomCharSeq(5) + '.' + randomCharSeq(3);
    newReq.cylinder = rand() % m_hardDrive->cylindersCount();
    newReq.sector = rand() % m_hardDrive->sectorsCount();
    newReq.head = rand() % m_hardDrive->headsCount();

    if (rand() % 2)
        newReq.operationType = OperationType::Read;
    else
        newReq.operationType = OperationType::Write;

    m_newReqModel->addRequest(newReq);

    m_curId++;
}

QString MainWindow::randomCharSeq(int length)
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

    QString randomString;
    for(int i=0; i<length; i++)
    {
       int index = rand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
    }

    return randomString;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    event = nullptr; // remove warning

    if (rand() % 10 == 1)
        addRequest();
}
