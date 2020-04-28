/***************************************************************************
 *   Copyright (C) 2008 by MacJariel                                       *
 *   echo "badmailet@gbalt.dob" | tr "edibmlt" "ecrmjil"                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QtDebug>
#include "card.h"
#include "config.h"

#include <QPainter>
#include <QFont>

using namespace client;

QMap<PlayingCardType, Card*> Card::sm_playingCards;
QMap<PlayerRole,      Card*> Card::sm_roleCards;
QMap<CharacterType,   Card*> Card::sm_characterCards;

Card::Card(const QString& name, PlayingCardType playingCardType, const QString& imageFileName):
        m_name(name),
        m_type(Card::Playing),
        m_imageFileName(imageFileName)

{
    if (sm_playingCards.contains(playingCardType)) {
        qCritical("Unable to create a playing card. Given type already created.");
        return;
    }
    loadPixmap();
    sm_playingCards[playingCardType] = this;
}

Card::Card(const QString& name, PlayerRole role, const QString& imageFileName):
        m_name(name),
        m_type(Card::Role),
        m_imageFileName(imageFileName)

{
    if (sm_roleCards.contains(role)) {
        qCritical("Unable to create a role card. Given role card already created.");
        return;
    }
    loadPixmap();
    sm_roleCards[role] = this;
}

Card::Card(const QString& name, CharacterType character, const QString& imageFileName):
        m_name(name),
        m_type(Card::Character),
        m_imageFileName(imageFileName)
{
    if (sm_characterCards.contains(character)) {
        qCritical("Unable to create a character card. Given character card already created.");
        return;
    }
    loadPixmap();
    sm_characterCards[character] = this;
}

QPixmap Card::image(const CardSuit& suit, const CardRank& rank) const
{

        QPoint posRank(35, 590);

        QFont font;
        font.setPixelSize(60);
        QPixmap  result = image();
        QPainter painter(&result);

        QString textRank = rankToString(rank);
        QChar   textSuit = suitToChar(suit);
        QColor  suitColor = suitToColor(suit);

        QPainterPath path1;
        QPainterPath path2;
        //timesFont.setStyleStrategy(QFont::ForceOutline);
        path1.addText(posRank, font, textRank);
        QPoint posSuit = posRank + QPoint((int)(font.pixelSize() * 2 * textRank.size() / 3), 0);
        path2.addText(posSuit, font, textSuit);

        painter.setRenderHint(QPainter::Antialiasing);
/*
        painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap,
                         Qt::RoundJoin));

        painter.setBrush(Qt::black);
        painter.drawPath(path1);
        painter.drawPath(path2);
*/
        painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::RoundCap,
                         Qt::RoundJoin));

        painter.setBrush(Qt::black);
    painter.drawPath(path1);

        painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::RoundCap,
                         Qt::RoundJoin));
        painter.setBrush(suitColor);
        painter.drawPath(path2);
        return result;
}


void Card::loadDefaultRuleset()
{
    new Card("Bang!",       PlayingCardType::BANG,       "gfx/cards/bang.png");
    new Card("Mancato",     PlayingCardType::MISSED,     "gfx/cards/missed.png");
    new Card("Birra",       PlayingCardType::BEER,       "gfx/cards/beer.png");
    new Card("Saloon",      PlayingCardType::SALOON,     "gfx/cards/saloon.png");
    new Card("Wells Fargo", PlayingCardType::WELLSFARGO,  "gfx/cards/wellsfargo.png");
    new Card("Diligenza",   PlayingCardType::DILIGENZA,   "gfx/cards/diligenza.png");
    new Card("Emporio",     PlayingCardType::GENERALSTORE,"gfx/cards/emporio.png");
    new Card("Panico!",     PlayingCardType::PANIC,       "gfx/cards/panico.png");
    new Card("Cat Balou",   PlayingCardType::CATBALOU,    "gfx/cards/catbalou.png");
    new Card("Indiani!",    PlayingCardType::INDIANS,     "gfx/cards/indians.png");
    new Card("Duello",      PlayingCardType::DUEL,        "gfx/cards/duel.png");
    new Card("Gatling",     PlayingCardType::GATLING,     "gfx/cards/gatling.png");
    new Card("Mustang",     PlayingCardType::MUSTANG,    "gfx/cards/mustang.png");
    new Card("Appaloosa",   PlayingCardType::APPALOSSA,  "gfx/cards/appaloosa.png");
    new Card("Barile",      PlayingCardType::BARREL,     "gfx/cards/barrel.png");
    new Card("Dinamite",    PlayingCardType::DYNAMITE,   "gfx/cards/dynamite.png");
    new Card("Prigione",    PlayingCardType::JAIL,       "gfx/cards/jail.png");
    new Card("Volcanic",    PlayingCardType::VOLCANIC,   "gfx/cards/volcanic.png");
    new Card("Schofield",   PlayingCardType::SCHOFIELD,  "gfx/cards/schofield.png");
    new Card("Winchester",  PlayingCardType::WINCHESTER, "gfx/cards/winchester.png");
    new Card("Remington",   PlayingCardType::REMINGTON,  "gfx/cards/remington.png");
    new Card("Carabine",    PlayingCardType::CARABINE,   "gfx/cards/carabine.png");
    new Card("",            PlayingCardType::UNKNOWN,    "gfx/cards/back-playing.png");

    new Card("Bart Cassidy",    CharacterType::BART_CASSIDY,     "gfx/characters/bart-cassidy.png");
    new Card("Black Jack",      CharacterType::BLACK_JACK,       "gfx/characters/black-jack.png");
    new Card("Calamity Janet",  CharacterType::CALAMITY_JANET,   "gfx/characters/calamity-janet.png");
    new Card("El Gringo",       CharacterType::EL_GRINGO,        "gfx/characters/el-gringo.png");
    new Card("Jesse Jones",     CharacterType::JESSE_JONES,      "gfx/characters/jesse-jones.png");
    new Card("Jourdonnais",     CharacterType::JOURDONNAIS,      "gfx/characters/jourdonnais.png");
    new Card("Kit Carlson",     CharacterType::KIT_CARLSON,      "gfx/characters/kit-carlson.png");
    new Card("Lucky Duke",      CharacterType::LUCKY_DUKE,       "gfx/characters/lucky-duke.png");
    new Card("Paul Regret",     CharacterType::PAUL_REGRET,      "gfx/characters/paul-regret.png");
    new Card("Pedro Ramirez",   CharacterType::PEDRO_RAMIREZ,    "gfx/characters/pedro-ramirez.png");
    new Card("Rose Doolan",     CharacterType::ROSE_DOOLAN,      "gfx/characters/rose-doolan.png");
    new Card("Sid Ketchum",     CharacterType::SID_KETCHUM,      "gfx/characters/sid-ketchum.png");
    new Card("Slab the Killer", CharacterType::SLAB_THE_KILLER,  "gfx/characters/slab-the-killer.png");
    new Card("Suzy Lafayette",  CharacterType::SUZY_LAFAYETTE,   "gfx/characters/suzy-lafayette.png");
    new Card("Vulture Sam",     CharacterType::VULTURE_SAM,      "gfx/characters/vulture-sam.png");
    new Card("Willy the Kid",   CharacterType::WILLY_THE_KID,    "gfx/characters/willy-the-kid.png");
    new Card("",                CharacterType::UNKNOWN,          "gfx/cards/back-character.png");


    new Card("Sheriff",  PlayerRole::SHERIFF,    "gfx/cards/sheriff.png");
    new Card("Renegade", PlayerRole::RENEGADE,   "gfx/cards/renegade.png");
    new Card("Outlaw",   PlayerRole::OUTLAW,     "gfx/cards/outlaw.png");
    new Card("Deputy",   PlayerRole::DEPUTY,     "gfx/cards/deputy.png");
    new Card("",         PlayerRole::UNKNOWN,    "gfx/cards/back-role.png");
}


const Card* Card::findPlayingCard(PlayingCardType id)
{
    return (sm_playingCards.contains(id) ? sm_playingCards[id] : 0);
}

const Card* Card::findRoleCard(PlayerRole id)
{
    return (sm_roleCards.contains(id) ? sm_roleCards[id] : 0);
}

const Card* Card::findCharacterCard(CharacterType id)
{
    return (sm_characterCards.contains(id) ? sm_characterCards[id] : 0);
}

QString Card::rankToString(CardRank rank)
{
    if (rank <= 9) {
        return QString::number(rank);
    } else if (rank == 10) {
        return "10";
    } else if (rank == 11) {
        return "J";
    } else if (rank == 12) {
        return "Q";
    } else if (rank == 13) {
        return "K";
    } else if (rank == 14) {
        return "A";
    }
    return "";
}

QChar Card::suitToChar(CardSuit suit)
{
    switch (suit) {
    case CardSuit::CLUBS:    return 0x2663;
    case CardSuit::DIAMONDS: return 0x2666;
    case CardSuit::HEARTS:   return 0x2665;
    case CardSuit::SPADES:   return 0x2660;
    }
    NOT_REACHED();
    return QChar();
}

QColor Card::suitToColor(CardSuit suit)
{
    switch (suit) {
    case CardSuit::CLUBS:    return Qt::black;
    case CardSuit::DIAMONDS: return Qt::red;
    case CardSuit::HEARTS:   return Qt::red;
    case CardSuit::SPADES:   return Qt::black;
    }
    NOT_REACHED();
    return QColor();
}

QString Card::suitToColorString(CardSuit suit)
{

    QString color;
    switch (suit) {
    case CardSuit::CLUBS:
        color = "black";
        break;
    case CardSuit::DIAMONDS:
        color = "red";
        break;
    case CardSuit::HEARTS:
        color = "red";
        break;
    case CardSuit::SPADES:
        color = "black";
        break;
    }
    return QString("<font color=\"%1\">%2</font>").arg(color).arg(suitToChar(suit));
}


void Card::loadPixmap()
{
    if (!m_image.load(Config::dataPathString() + m_imageFileName)) {
        qWarning(qPrintable(QString("Cannot load pixmap: %1").arg(Config::dataPathString() + m_imageFileName)));
    }
}
