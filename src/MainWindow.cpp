#include "MainWindow.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPalette>
#include <QFont>

MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent) {
    setWindowTitle("🎵 MusicWalker");
    resize(1920, 1080);
    setWindowState(Qt::WindowMaximized);

    // Set a dark theme
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(30, 30, 30));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Button, QColor(45, 45, 45));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::Base, QColor(35, 35, 35));
    setPalette(palette);

    // Apply global font
    QFont appFont("Segoe UI", 10);
    setFont(appFont);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setSpacing(12);
    layout->setContentsMargins(15, 15, 15, 15);

    playerArea = new PlayerArea(this);
    playerWidget = new PlayerWidget(this);
    queueManager = new QueueManager(this);
    audioPlayer = new AudioPlayer(this);

    layout->addWidget(playerArea);
    layout->addWidget(playerWidget);
    setCentralWidget(centralWidget);

    // Optional: custom styles for children if supported
    setStyleSheet(R"(
        QWidget {
            background-color: #1e1e1e;
            color: white;
        }
        QPushButton {
            background-color: #3a3a3a;
            color: white;
            border: 1px solid #555;
            border-radius: 4px;
            padding: 6px 12px;
        }
        QPushButton:hover {
            background-color: #505050;
        }
        QLabel {
            font-size: 14px;
        }
    )");

    // Signal-slot connections
    connect(playerWidget, &PlayerWidget::playClicked, this, &MainWindow::onPlayClicked);
    connect(playerWidget, &PlayerWidget::pauseClicked, this, &MainWindow::onPauseClicked);
    connect(playerWidget, &PlayerWidget::stopClicked, this, &MainWindow::onStopClicked);
    connect(playerWidget, &PlayerWidget::nextClicked, this, &MainWindow::onNextClicked);
    connect(playerWidget, &PlayerWidget::prevClicked, this, &MainWindow::onPrevClicked);
    connect(playerWidget, &PlayerWidget::addClicked, this, &MainWindow::onAddToQueue);
    connect(playerWidget, &PlayerWidget::clearClicked, this, &MainWindow::onClearQueue);
    connect(queueManager, &QueueManager::currentTrackChanged, this, &MainWindow::onTrackChanged);
}

void MainWindow::onPlayClicked() {
    if (audioPlayer->isPlaying()) return;

    if (queueManager->current().isEmpty() && queueManager->hasNext()) {
        queueManager->next();
    } else if (!queueManager->current().isEmpty()) {
        audioPlayer->play();
    }
}

void MainWindow::onPauseClicked() {
    audioPlayer->pause();
}

void MainWindow::onStopClicked() {
    audioPlayer->stop();
}

void MainWindow::onNextClicked() {
    if (queueManager->hasNext()) {
        queueManager->next();
    }
}

void MainWindow::onPrevClicked() {
    if (queueManager->hasPrevious()) {
        queueManager->previous();
    }
}

void MainWindow::onAddToQueue() {
    QStringList files = QFileDialog::getOpenFileNames(
        this,
        "Select MP3 Files",
        "",
        "MP3 Files (*.mp3)"
    );

    if (!files.isEmpty()) {
        queueManager->addToQueue(files);
    }
}

void MainWindow::onClearQueue() {
    audioPlayer->stop();
    queueManager->clearQueue();
    playerArea->setTrackName("No track selected");
}

void MainWindow::onTrackChanged(const QString &filePath) {
    if (audioPlayer->load(filePath)) {
        playerArea->setTrackName(QFileInfo(filePath).fileName());
        audioPlayer->play();
    }
}
