#pragma once

#include <QHash>

class QFile;

class Translator {

public:
   static Translator* GetTranslatorSingleton();

   void LoadLanguajeMap(QFile* translationsFile);
   static QString Translate(QString textToTranslate);
   QHash<QString, QString>* GetTransmap() { return m_translationsMaps; }
private:
   Translator();

private:
   QHash<QString, QString> *m_translationsMaps = nullptr;
   static Translator * m_translatorInstance;
};
