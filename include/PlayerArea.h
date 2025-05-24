#ifndef PLAYERAREA_H
#define PLAYERAREA_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QResizeEvent>

class PlayerArea : public QWidget {
    Q_OBJECT
public:
    explicit PlayerArea(QWidget *parent = nullptr);
    void setTrackName(const QString &name);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QLabel *trackLabel;
    QWidget *background;
};

#endif // PLAYERAREA_H