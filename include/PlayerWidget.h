#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QPushButton>

class PlayerWidget : public QWidget {
    Q_OBJECT
public:
    explicit PlayerWidget(QWidget *parent = nullptr);

signals:
    void playClicked();
    void pauseClicked();
    void stopClicked();
    void nextClicked();
    void prevClicked();
    void addClicked();
    void clearClicked();

private:
    // Playback control buttons
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QPushButton *nextButton;
    QPushButton *prevButton;
    
    // Queue management buttons
    QPushButton *addButton;
    QPushButton *clearButton;
};

#endif // PLAYERWIDGET_H