#include "AudioPlayer.h"
#include <QDebug>
#include <SDL.h>
#include <SDL_mixer.h>

AudioPlayer::AudioPlayer(QObject *parent) 
    : QObject(parent) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        qWarning() << "SDL_Init error:" << SDL_GetError();
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        qWarning() << "Mix_OpenAudio error:" << Mix_GetError();
    }
}

AudioPlayer::~AudioPlayer() {
    stop();
    int freq, channels;
    Uint16 format;
    if (Mix_QuerySpec(&freq, &format, &channels) != 0) {
        Mix_CloseAudio();
    }
    SDL_Quit();
}

bool AudioPlayer::load(const QString &filePath) {
    stop();
    music = Mix_LoadMUS(filePath.toUtf8().constData());
    if (!music) {
        qWarning() << "Mix_LoadMUS error:" << Mix_GetError();
        return false;
    }
    return true;
}

void AudioPlayer::play() {
    if (music && !m_isPlaying) {
        if (Mix_PlayMusic(music, 0) == -1) {
            qWarning() << "Mix_PlayMusic error:" << Mix_GetError();
            return;
        }
        m_isPlaying = true;
    }
}

void AudioPlayer::pause() {
    if (m_isPlaying) {
        Mix_PauseMusic();
        m_isPlaying = false;
    }
}

void AudioPlayer::stop() {
    if (music) {
        Mix_HaltMusic();
        Mix_FreeMusic(music);
        music = nullptr;
        m_isPlaying = false;
    }
}

bool AudioPlayer::isPlaying() const {
    return m_isPlaying;
}