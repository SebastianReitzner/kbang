#include "ioproxy.h"

IOProxy::IOProxy(QObject* parent):QIODevice(parent) {
    open(QIODevice::WriteOnly);
}

IOProxy::~ IOProxy() {
    close();
}

qint64 IOProxy::readData(char*, qint64) {
    return 0;
}

qint64 IOProxy::writeData(const char* data, qint64 maxSize) {
    // Note: Not easy but an overflow here could be dangerous
    // also QBYteArray has a maximum of 2GB (though it really
    // depends on the OS below)
    QByteArray d(data, int(maxSize));
    emit networkOut(d);
    return d.size();
}
