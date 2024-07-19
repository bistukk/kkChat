#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QAudioFormat>
#include <QMediaDevices>
#include <QMessageBox>
#include <QAudioSource>
#include <QFile>

class Audio : public QObject
{
    Q_OBJECT
public:
    explicit Audio(QObject *parent = nullptr);

    void startAudio(const QString &fileName);
    void stopAudio();

signals:

private:
    QAudioSource *m_audio;
    QFile *m_file;
};

#endif // AUDIO_H
