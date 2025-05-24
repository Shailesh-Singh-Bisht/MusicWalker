#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <SDL2/SDL_mixer.h>

class AudioPlayer : public QObject {
    Q_OBJECT
public:
    explicit AudioPlayer(QObject *parent = nullptr);
    ~AudioPlayer();

    bool load(const QString &filePath);
    void play();
    void pause();
    void stop();
    bool isPlaying() const;

private:
    Mix_Music *music = nullptr;
    bool m_isPlaying = false;
};

#endif // AUDIOPLAYER_H