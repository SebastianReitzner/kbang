/***************************************************************************
 *   Copyright (C) 2009 by MacJariel                                       *
 *   MacJariel (at) gmail.com                                              *
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

#ifndef GAMEENUMS_H
#define GAMEENUMS_H

#include <QString>

/**
 * @deprecated
 */
enum class ActionRequestType {
    DRAW,
    PLAY,
    RESPOND,
    DISCARD
};

enum class PlayerRole {
    INVALID = 0,
    UNKNOWN,
    SHERIFF,
    DEPUTY,
    OUTLAW,
    RENEGADE
};

enum class PocketType {
    INVALID = 0,
    DECK,
    GRAVEYARD,
    HAND,
    TABLE,
    SELECTION
};

enum class PlayingCardType {
    UNKNOWN = 0,
    BANG,
    MISSED,
    BEER,
    SALOON,
    WELLSFARGO,
    DILIGENZA,
    GENERALSTORE,
    PANIC,
    CATBALOU,
    INDIANS,
    DUEL,
    GATLING,
    MUSTANG,
    APPALOSSA,
    BARREL,
    DYNAMITE,
    JAIL,
    VOLCANIC,
    SCHOFIELD,
    REMINGTON,
    CARABINE,
    WINCHESTER
};

enum class CharacterType {
    UNKNOWN = 0,
    BART_CASSIDY,
    BLACK_JACK,
    CALAMITY_JANET,
    EL_GRINGO,
    JESSE_JONES,
    JOURDONNAIS,
    KIT_CARLSON,
    LUCKY_DUKE,
    PAUL_REGRET,
    PEDRO_RAMIREZ,
    ROSE_DOOLAN,
    SID_KETCHUM,
    SLAB_THE_KILLER,
    SUZY_LAFAYETTE,
    VULTURE_SAM,
    WILLY_THE_KID
};

enum class ReactionType {
    NONE,
    BANG,
    GATLING,
    INDIANS,
    DUEL,
    GENERALSTORE,
    LASTSAVE,
    LUCKYDUKE,
    KITCARLSON
};

enum class ClientType {
    PLAYER,
    SPECTATOR
};

enum class CardSuit {
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS
};

/**
 * Represents the rank of a card. Numeral ranks are represented with the
 * corresponding number, others are represented by following values:
 *  * jack  = 11,
 *  * queen = 12,
 *  * king  = 13,
 *  * ace   = 14
 * This represention allows convenient comparing.
 */
typedef int CardRank;

enum class GamePlayState {
    INVALID = 0,
    DRAW,
    TURN,
    RESPONSE,
    DISCARD
};

enum class GameState {
    INVALID = 0,
    WAITINGFORPLAYERS,
    PLAYING,
    FINISHED
};


enum class GameMessageType {
    INVALID = 0,
    GAMESTARTED,
    GAMEFINISHED,
    PLAYERDRAWFROMDECK,
    PLAYERDRAWFROMGRAVEYARD,
    PLAYERDISCARDCARD,
    PLAYERPLAYCARD,
    PLAYERRESPONDWITHCARD,
    PLAYERPASS,
    PLAYERPICKFROMSELECTION,
    PLAYERCHECKDECK,
    PLAYERSTEALCARD,
    PLAYERCANCELCARD,
    DECKREGENERATE,
    PLAYERDIED,
};


CardSuit        stringToCardSuit(const QString& s);
QString         cardSuitToString(const CardSuit& suit);
CharacterType   stringToCharacterType(const QString& s);
QString         characterTypeToString(const CharacterType& t);
PlayingCardType stringToPlayingCardType(const QString& s);
QString         playingCardTypeToString(const PlayingCardType& c);
PlayerRole      stringToPlayerRole(const QString& s);
QString         playerRoleToString(const PlayerRole& r);
GamePlayState   stringToGamePlayState(const QString& s);
QString         gamePlayStateToString(const GamePlayState& s);
ReactionType    stringToReactionType(const QString& s);
QString         reactionTypeToString(const ReactionType& r);
PocketType      stringToPocketType(const QString& s);
QString         pocketTypeToString(const PocketType& p);
GameState       stringToGameState(const QString& s);
QString         gameStateToString(const GameState& s);
ClientType      stringToClientType(const QString& s);
QString         clientTypeToString(const ClientType& t);
GameMessageType stringToGameMessageType(const QString& s);
QString         gameMessageTypeToString(const GameMessageType& g);

#endif // GAMEENUMS_H
