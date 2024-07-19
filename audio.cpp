#include "audio.h"
#include <QDebug>

Audio::Audio(QObject *parent)
    : QObject{parent}, m_audio(nullptr), m_file(nullptr)
{
}

void Audio::startAudio(const QString &fileName)
{
    qDebug() << "startAudio called with fileName:" << fileName;

     qDebug() << 0 << Qt::endl;
    // 检查并停止任何现有的音频流
    if (m_audio) {
         qDebug() << 01 << Qt::endl;
        qDebug() << "Audio is already running. Stopping it.";
        stopAudio();
    }

    qDebug() << 1 << Qt::endl;

    QAudioDevice device = QMediaDevices::defaultAudioInput();
    if (device.isNull())  // 设备不存在
    {
        QMessageBox::warning(nullptr, "QAudioDevice", "录音设备不存在");
        qDebug() << "录音设备不存在";
        return;
    }

     qDebug() << 2 << Qt::endl;

    QAudioFormat m_format;
    // 设置采样频率
    m_format.setSampleRate(16000);
    // 设置通道数
    m_format.setChannelCount(1);
    // 设置位深
    m_format.setSampleFormat(QAudioFormat::Int16);

    // 判断设备是否支持该格式
    if (!device.isFormatSupported(m_format))
    {
        m_format = device.preferredFormat();
        qDebug() << "不支持指定格式，使用首选格式:" << m_format;
    }

     qDebug() << 3 << Qt::endl;
    // 打开文件
    m_file = new QFile(fileName);
    if (!m_file->open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(nullptr, "File Error", "无法打开文件进行写入");
        qDebug() << "无法打开文件进行写入";
        delete m_file;
        m_file = nullptr;
        return;
    }

     qDebug() << 4 << Qt::endl;
    // 创建录音对象
    m_audio = new QAudioSource(device, m_format, this);
    if (!m_audio) {
        qDebug() << "QAudioSource 创建失败";
        return;
    }

     qDebug() << 5 << Qt::endl;
    // 启动录音
    m_audio->start(m_file);
    qDebug() << "开始录音";
}

void Audio::stopAudio()
{
    qDebug() << "stopAudio called";

    // 停止录音
    if (m_audio)
    {
        m_audio->stop();
        delete m_audio;
        m_audio = nullptr;
        qDebug() << "停止录音";
    }

     qDebug() << 6 << Qt::endl;
    // 关闭文件
    if (m_file)
    {
        m_file->close();
        delete m_file;
        m_file = nullptr;
        qDebug() << "关闭文件";
    }
}
