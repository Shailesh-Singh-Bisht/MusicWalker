#include "QueueManager.h"
#include <QDebug>
#include <QFileInfo>

QueueManager::QueueManager(QObject *parent) 
    : QObject(parent)
    , m_currentTrack("")
{
}

void QueueManager::addToQueue(const QString &filePath) {
    if (filePath.isEmpty()) {
        qDebug() << "Warning: Attempted to add empty file path to queue";
        return;
    }
    
    m_queue.append(filePath);
    emit queueChanged();
}

void QueueManager::addToQueue(const QStringList &filePaths) {
    if (filePaths.isEmpty()) {
        qDebug() << "Warning: Attempted to add empty file list to queue";
        return;
    }
    
    m_queue.append(filePaths);
    emit queueChanged();
}

void QueueManager::clearQueue() {
    m_queue.clear();
    m_history.clear();
    m_currentTrack.clear();
    
    emit queueChanged();
    emit currentTrackChanged("");
}

QString QueueManager::next() {
    if (!hasNext()) {
        return QString();
    }

    updateHistory();
    m_currentTrack = m_queue.takeFirst();
    emit currentTrackChanged(m_currentTrack);
    emit queueChanged();
    
    return m_currentTrack;
}

QString QueueManager::previous() {
    if (!hasPrevious()) {
        return QString();
    }

    if (!m_currentTrack.isEmpty()) {
        m_queue.prepend(m_currentTrack);
    }

    m_currentTrack = m_history.takeLast();
    emit currentTrackChanged(m_currentTrack);
    emit queueChanged();
    
    return m_currentTrack;
}

QString QueueManager::current() const {
    return m_currentTrack;
}

bool QueueManager::hasNext() const {
    return !m_queue.isEmpty();
}

bool QueueManager::hasPrevious() const {
    return !m_history.isEmpty();
}

void QueueManager::updateHistory() {
    if (!m_currentTrack.isEmpty()) {
        m_history.append(m_currentTrack);
    }
}