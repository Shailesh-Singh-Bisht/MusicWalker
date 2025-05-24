#include "PlayerArea.h"
#include <QVBoxLayout>

PlayerArea::PlayerArea(QWidget *parent) 
    : QWidget(parent), background(new QWidget(this))
{    
    setMinimumHeight(300);
    setMinimumWidth(800);
      // Create background widget first (bottom layer)
    background->setAutoFillBackground(true);
    background->setStyleSheet(R"(
        QWidget {
            background-color: #2a2a2a;
            border-radius: 15px;
            border: 1px solid #3a3a3a;
            margin: 0;
            padding: 0;
        }
    )");
    
    // Set the widget's own background to be fully transparent
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::transparent);
    setPalette(pal);
    setAutoFillBackground(true);
    background->setAttribute(Qt::WA_TransparentForMouseEvents); // Let clicks pass through
    background->lower(); // Put it behind other widgets
    
    // Create and style track label (top layer)
    trackLabel = new QLabel("No track selected", this);
    trackLabel->setAlignment(Qt::AlignCenter);
    trackLabel->setStyleSheet(R"(
        font-size: 28px;
        font-weight: bold;
        color: #ffffff;
        background: transparent;
        padding: 20px;
    )");
    
    // Create gradient effect for visual appeal
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(20);
    shadowEffect->setColor(QColor(0, 0, 0, 160));
    shadowEffect->setOffset(0, 0);
    trackLabel->setGraphicsEffect(shadowEffect);    // Setup layout for the track label
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch();
    layout->addWidget(trackLabel, 0, Qt::AlignCenter);
    layout->addStretch();
    layout->setContentsMargins(30, 30, 30, 30);
    
    // Make background fill the widget
    background->setGeometry(0, 0, width(), height());
    
    // Ensure this widget is transparent to show the background
    setStyleSheet("PlayerArea { background: transparent; }");
}

void PlayerArea::setTrackName(const QString &name) {
    trackLabel->setText(name);
}

void PlayerArea::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    if (background) {
        background->setGeometry(0, 0, width(), height());
    }
}