#include "translator.h"

#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QObject>
#include <QLabel>
#include <QAbstractButton>
#include <QMenu>
#include <QAction>
#include <QMainWindow>

#include "config.h"

Translator* Translator::m_translatorInstance = nullptr;

Translator::Translator() {
   m_translationsMaps = new QHash<QString, QString>();

   auto wantedLang = Config::instance().readString("player", "languaje");
   if (wantedLang.compare("spanish")) {
      ChangeLanguaje(Languajes::SPANISH);
   }
   else { // Default
      ChangeLanguaje(Languajes::ENGLISH);
   }
}

void Translator::ChangeLanguaje(Languajes newLang) {
   
   m_translationsMaps->clear();

   switch (newLang)   {
      case Languajes::SPANISH:
         if (QFile::exists("kbang_translations_es.txt")) {
            LoadLanguajeMap(&QFile("kbang_translations_es.txt"));
            break;
         }
      default:
         if (QFile::exists("kbang_translations_en.txt")) {
            LoadLanguajeMap(&QFile("kbang_translations_en.txt"));
         }
         else {
            // Error
         }
         break;
      }

   foreach(QWidget *wid, qApp->topLevelWidgets()) {
      if (QMainWindow* mainWin = qobject_cast<QMainWindow*>(wid)) {
         UpdateUI(mainWin);
      }
   }

}

void Translator::UpdateUI(QWidget* widget) {
   for (auto wid : widget->findChildren<QWidget*>()) {
      QString text = "";
      if (auto label = dynamic_cast<QLabel*>(wid)) {
         text = Translate(label->objectName());
         if (text != "") {
            label->setText(text);
         }
      }
      else if (auto button = dynamic_cast<QAbstractButton*>(wid)) {
         text = Translate(button->objectName());
         if (text != "") {
            button->setText(text);
         }
      }
      else if (auto action = dynamic_cast<QAction*>(wid)) {
         text = Translate(action->objectName());
         if (text != "") {
            action->setText(text);
         }
      }
      else if (auto menu = dynamic_cast<QMenu*>(wid)) {
         text = Translate(menu->objectName());
         if (text != "") {
            menu->setTitle(text);
         }
      }
   }
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
   return "";
}