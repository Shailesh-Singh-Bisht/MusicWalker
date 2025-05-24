#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include "PlayerArea.h"
#include "PlayerWidget.h"
#include "QueueManager.h"
#include "AudioPlayer.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onPlayClicked();
    void onPauseClicked();
    void onStopClicked();
    void onNextClicked();
    void onPrevClicked();
    void onAddToQueue();
    void onClearQueue();
    void onTrackChanged(const QString &filePath);

private:
    PlayerArea *playerArea;
    PlayerWidget *playerWidget;
    QueueManager *queueManager;
    AudioPlayer *audioPlayer;
};

#endif // MAINWINDOW_H