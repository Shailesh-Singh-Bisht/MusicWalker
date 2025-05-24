#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H

#include <QObject>
#include <QString>
#include <QStringList>

class QueueManager : public QObject
{
    Q_OBJECT

public:
    explicit QueueManager(QObject *parent = nullptr);

    // Queue management
    void addToQueue(const QString &filePath);
    void addToQueue(const QStringList &filePaths);
    void clearQueue();
    QString next();
    QString previous();
    QString current() const;
    bool hasNext() const;
    bool hasPrevious() const;

signals:
    void queueChanged();
    void currentTrackChanged(const QString &filePath);

private:
    QStringList m_queue;
    QStringList m_history;
    QString m_currentTrack;

    void updateHistory();
};

#endif // QUEUEMANAGER_H