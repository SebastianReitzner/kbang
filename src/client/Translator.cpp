#include "translator.h"

#include <QFile>
#include <QTextStream>

Translator* Translator::m_translatorInstance = nullptr;

Translator::Translator() {
   m_translationsMaps = new QHash<QString, QString>();
}

void Translator::LoadLanguajeMap(QFile* translationsFile) {
   if (!translationsFile->open(QIODevice::ReadOnly)) {
      return;
   }

   QTextStream instream(translationsFile);
   QString line;

   do {
      line = instream.readLine();
      QStringList words = line.split(";");
      m_translationsMaps->insert(words[0], words[1]);
   } while (!instream.atEnd());

   translationsFile->close();
};
Translator* Translator::GetTranslatorSingleton() {
   if (m_translatorInstance == nullptr) {
      m_translatorInstance = new Translator();
   }
   return m_translatorInstance;
};
QString Translator::Translate(QString textToTranslate) {
   if (m_translatorInstance->m_translationsMaps->contains(textToTranslate)) {
      return m_translatorInstance->m_translationsMaps->value(textToTranslate);
   }
   return textToTranslate;
}