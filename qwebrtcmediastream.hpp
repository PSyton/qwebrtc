#pragma once

#include <QSharedPointer>
#include <QString>

class QWebRTCMediaTrack;
class QWebRTCMediaStream {
public:
    virtual ~QWebRTCMediaStream() = default;

    virtual void addTrack(const QSharedPointer<QWebRTCMediaTrack>&) = 0;
    virtual void removeTrack(const QSharedPointer<QWebRTCMediaTrack>&) = 0;
    virtual QList<QSharedPointer<QWebRTCMediaTrack>> tracks() = 0;
    virtual QString label() = 0;
};
