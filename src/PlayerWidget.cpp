#include "PlayerWidget.h"
#include <QHBoxLayout>

PlayerWidget::PlayerWidget(QWidget *parent) 
    : QWidget(parent) {
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(15);
    mainLayout->setContentsMargins(15, 10, 15, 10);

    // Create playback control buttons
    prevButton = new QPushButton("⏮", this);
    playButton = new QPushButton("▶", this);
    pauseButton = new QPushButton("⏸", this);
    stopButton = new QPushButton("⏹", this);
    nextButton = new QPushButton("⏭", this);
    
    // Create queue management buttons
    addButton = new QPushButton("➕ Queue", this);
    clearButton = new QPushButton("❌ Clear", this);

    // Use a classic control font
    QFont controlFont("Segoe UI", 12, QFont::Bold);
    for (QPushButton* btn : { playButton, pauseButton, stopButton, prevButton, nextButton }) {
        btn->setFont(controlFont);
    }

    // Button styling
    QString controlStyle = R"(
        QPushButton {
            background-color: #3a3a3a;
            border: none;
            border-radius: 4px;
            color: white;
            min-width: 40px;
            min-height: 40px;
        }
        QPushButton:hover {
            background-color: #4a4a4a;
        }
    )";

    QString queueStyle = R"(
        QPushButton {
            background-color: #3a3a3a;
            border: none;
            border-radius: 4px;
            color: white;
            padding: 8px 16px;
        }
        QPushButton:hover {
            background-color: #4a4a4a;
        }
    )";

    for (QPushButton* btn : { playButton, pauseButton, stopButton, prevButton, nextButton }) {
        btn->setStyleSheet(controlStyle);
    }

    for (QPushButton* btn : { addButton, clearButton }) {
        btn->setStyleSheet(queueStyle);
    }

    // Layout arrangement
    mainLayout->addWidget(addButton);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(prevButton);
    mainLayout->addWidget(playButton);
    mainLayout->addWidget(pauseButton);
    mainLayout->addWidget(stopButton);
    mainLayout->addWidget(nextButton);
    mainLayout->addStretch();
    mainLayout->addWidget(clearButton);

    // Signal connections
    connect(playButton, &QPushButton::clicked, this, &PlayerWidget::playClicked);
    connect(pauseButton, &QPushButton::clicked, this, &PlayerWidget::pauseClicked);
    connect(stopButton, &QPushButton::clicked, this, &PlayerWidget::stopClicked);
    connect(nextButton, &QPushButton::clicked, this, &PlayerWidget::nextClicked);
    connect(prevButton, &QPushButton::clicked, this, &PlayerWidget::prevClicked);
    connect(addButton, &QPushButton::clicked, this, &PlayerWidget::addClicked);
    connect(clearButton, &QPushButton::clicked, this, &PlayerWidget::clearClicked);
}
