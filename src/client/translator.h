#pragma once

#include <QHash>

class QFile;
class QWidget;

enum class Languajes {
   SPANISH,
   ENGLISH
};

class Translator {

public:
   static Translator* GetTranslatorSingleton();
   static QString Translate(QString textToTranslate);

   void LoadLanguajeMap(QFile* translationsFile);
   void ChangeLanguaje(Languajes newLang);
   void UpdateUI(QWidget* widget);

private:
   Translator();
   QHash<QString, QString>* GetTransmap() { return m_translationsMaps; }
   void WriteTxtWantedTranslations(QString key);

private:
   QHash<QString, QString> *m_translationsMaps = nullptr;
   static Translator *m_translatorInstance;
};
