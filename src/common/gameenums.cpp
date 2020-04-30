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

#include "gameenums.h"
#include "util.h"


CardSuit stringToCardSuit(const QString& s) {
    if (s == "spades")      return CardSuit::SPADES;
    if (s == "hearts")      return CardSuit::HEARTS;
    if (s == "diamonds")    return CardSuit::DIAMONDS;
    if (s == "clubs")       return CardSuit::CLUBS;
    return CardSuit::SPADES;
}

QString cardSuitToString(const CardSuit& suit) {
    switch(suit) {
    case CardSuit::SPADES:   return "spades";
    case CardSuit::HEARTS:   return "hearts";
    case CardSuit::DIAMONDS: return "diamonds";
    case CardSuit::CLUBS:    return "clubs";
    default: return "";
    }
}

CharacterType stringToCharacterType(const QString& s) {
    if (s == "slab the killer") return CharacterType::SLAB_THE_KILLER;
    if (s == "lucky duke")      return CharacterType::LUCKY_DUKE;
    if (s == "suzy lafayette")  return CharacterType::SUZY_LAFAYETTE;
    if (s == "vulture sam")     return CharacterType::VULTURE_SAM;
    if (s == "black jack")      return CharacterType::BLACK_JACK;
    if (s == "sid ketchum")     return CharacterType::SID_KETCHUM;
    if (s == "jourdonnais")     return CharacterType::JOURDONNAIS;
    if (s == "el gringo")       return CharacterType::EL_GRINGO;
    if (s == "kit carlson")     return CharacterType::KIT_CARLSON;
    if (s == "jesse jones")     return CharacterType::JESSE_JONES;
    if (s == "pedro ramirez")   return CharacterType::PEDRO_RAMIREZ;
    if (s == "calamity janet")  return CharacterType::CALAMITY_JANET;
    if (s == "rose doolan")     return CharacterType::ROSE_DOOLAN;
    if (s == "bart cassidy")    return CharacterType::BART_CASSIDY;
    if (s == "paul regret")     return CharacterType::PAUL_REGRET;
    if (s == "willy the kid")   return CharacterType::WILLY_THE_KID;
    return CharacterType::UNKNOWN;
}

QString characterTypeToString(const CharacterType& t) {
    switch(t) {
    case CharacterType::UNKNOWN:         return "unknown";
    case CharacterType::SLAB_THE_KILLER: return "slab the killer";
    case CharacterType::LUCKY_DUKE:      return "lucky duke";
    case CharacterType::SUZY_LAFAYETTE:  return "suzy lafayette";
    case CharacterType::VULTURE_SAM:     return "vulture sam";
    case CharacterType::BLACK_JACK:      return "black jack";
    case CharacterType::SID_KETCHUM:     return "sid ketchum";
    case CharacterType::JOURDONNAIS:     return "jourdonnais";
    case CharacterType::EL_GRINGO:       return "el gringo";
    case CharacterType::KIT_CARLSON:     return "kit carlson";
    case CharacterType::JESSE_JONES:     return "jesse jones";
    case CharacterType::PEDRO_RAMIREZ:   return "pedro ramirez";
    case CharacterType::CALAMITY_JANET:  return "calamity janet";
    case CharacterType::ROSE_DOOLAN:     return "rose doolan";
    case CharacterType::BART_CASSIDY:    return "bart cassidy";
    case CharacterType::PAUL_REGRET:     return "paul regret";
    case CharacterType::WILLY_THE_KID:   return "willy the kid";
    }
    return "unknown";
}

PlayingCardType stringToPlayingCardType(const QString& s) {
    if (s == "bang")             return PlayingCardType::BANG;
    if (s == "missed")           return PlayingCardType::MISSED;
    if (s == "beer")             return PlayingCardType::BEER;
    if (s == "saloon")           return PlayingCardType::SALOON;
    if (s == "wellsfargo")       return PlayingCardType::WELLSFARGO;
    if (s == "diligenza")        return PlayingCardType::DILIGENZA;
    if (s == "generalstore")     return PlayingCardType::GENERALSTORE;
    if (s == "panic")            return PlayingCardType::PANIC;
    if (s == "catbalou")         return PlayingCardType::CATBALOU;
    if (s == "indians")          return PlayingCardType::INDIANS;
    if (s == "duel")             return PlayingCardType::DUEL;
    if (s == "gatling")          return PlayingCardType::GATLING;
    if (s == "mustang")          return PlayingCardType::MUSTANG;
    if (s == "appalossa")        return PlayingCardType::APPALOSSA;
    if (s == "barrel")           return PlayingCardType::BARREL;
    if (s == "dynamite")         return PlayingCardType::DYNAMITE;
    if (s == "jail")             return PlayingCardType::JAIL;
    if (s == "volcanic")         return PlayingCardType::VOLCANIC;
    if (s == "schofield")        return PlayingCardType::SCHOFIELD;
    if (s == "remington")        return PlayingCardType::REMINGTON;
    if (s == "carabine")         return PlayingCardType::CARABINE;
    if (s == "winchester")       return PlayingCardType::WINCHESTER;
    return PlayingCardType::UNKNOWN;
}

QString playingCardTypeToString(const PlayingCardType& c) {
    switch(c) {
    case PlayingCardType::BANG:           return "bang";
    case PlayingCardType::MISSED:         return "missed";
    case PlayingCardType::BEER:           return "beer";
    case PlayingCardType::SALOON:         return "saloon";
    case PlayingCardType::WELLSFARGO:     return "wellsfargo";
    case PlayingCardType::DILIGENZA:      return "diligenza";
    case PlayingCardType::GENERALSTORE:   return "generalstore";
    case PlayingCardType::PANIC:          return "panic";
    case PlayingCardType::CATBALOU:       return "catbalou";
    case PlayingCardType::INDIANS:        return "indians";
    case PlayingCardType::DUEL:           return "duel";
    case PlayingCardType::GATLING:        return "gatling";
    case PlayingCardType::MUSTANG:        return "mustang";
    case PlayingCardType::APPALOSSA:      return "appalossa";
    case PlayingCardType::BARREL:         return "barrel";
    case PlayingCardType::DYNAMITE:       return "dynamite";
    case PlayingCardType::JAIL:           return "jail";
    case PlayingCardType::VOLCANIC:       return "volcanic";
    case PlayingCardType::SCHOFIELD:      return "schofield";
    case PlayingCardType::REMINGTON:      return "remington";
    case PlayingCardType::CARABINE:       return "carabine";
    case PlayingCardType::WINCHESTER:     return "winchester";
    case PlayingCardType::UNKNOWN:        return "";
    }
    return "";
}

PlayerRole stringToPlayerRole(const QString& s) {
    if (s == "unknown")  return PlayerRole::UNKNOWN;
    if (s == "outlaw")   return PlayerRole::OUTLAW;
    if (s == "deputy")   return PlayerRole::DEPUTY;
    if (s == "sheriff")  return PlayerRole::SHERIFF;
    if (s == "renegade") return PlayerRole::RENEGADE;
    return PlayerRole::INVALID;
}

QString playerRoleToString(const PlayerRole& r) {
    if (r == PlayerRole::UNKNOWN)  return "unknown";
    if (r == PlayerRole::OUTLAW)   return "outlaw";
    if (r == PlayerRole::DEPUTY)   return "deputy";
    if (r == PlayerRole::SHERIFF)  return "sheriff";
    if (r == PlayerRole::RENEGADE) return "renegade";
    if (r == PlayerRole::INVALID)  return "invalid";
    NOT_REACHED();
    return "invalid";
}


GamePlayState stringToGamePlayState(const QString& s) {
    if (s == "draw")     return GamePlayState::DRAW;
    if (s == "turn")     return GamePlayState::TURN;
    if (s == "response") return GamePlayState::RESPONSE;
    if (s == "discard")  return GamePlayState::DISCARD;
    return GamePlayState::INVALID;
}

QString gamePlayStateToString(const GamePlayState& s) {
    if (s == GamePlayState::DRAW)     return "draw";
    if (s == GamePlayState::TURN)     return "turn";
    if (s == GamePlayState::RESPONSE) return "response";
    if (s == GamePlayState::DISCARD)  return "discard";
    if (s == GamePlayState::INVALID)  return "invalid";
    NOT_REACHED();
    return "invalid";
}

ReactionType stringToReactionType(const QString& s) {
    if (s == "bang")            return ReactionType::BANG;
    if (s == "gatling")         return ReactionType::GATLING;
    if (s == "indians")         return ReactionType::INDIANS;
    if (s == "duel")            return ReactionType::DUEL;
    if (s == "general-store")   return ReactionType::GENERALSTORE;
    if (s == "last-save")       return ReactionType::LASTSAVE;
    if (s == "lucky-duke")      return ReactionType::LUCKYDUKE;
    if (s == "kit-carlson")     return ReactionType::KITCARLSON;
    return ReactionType::NONE;
}

QString reactionTypeToString(const ReactionType& r) {
    switch(r) {
    case ReactionType::BANG:         return "bang";
    case ReactionType::GATLING:      return "gatling";
    case ReactionType::INDIANS:      return "indians";
    case ReactionType::DUEL:         return "duel";
    case ReactionType::GENERALSTORE: return "general-store";
    case ReactionType::LASTSAVE:     return "last-save";
    case ReactionType::LUCKYDUKE:    return "lucky-duke";
    case ReactionType::KITCARLSON:   return "kit-carlson";
    case ReactionType::NONE:         return "";
    }
    return "";
}

PocketType stringToPocketType(const QString& s) {
    if (s == "deck")      return PocketType::DECK;
    if (s == "graveyard") return PocketType::GRAVEYARD;
    if (s == "hand")      return PocketType::HAND;
    if (s == "table")     return PocketType::TABLE;
    if (s == "selection") return PocketType::SELECTION;
    return PocketType::INVALID;
}

QString pocketTypeToString(const PocketType& p) {
    if (p == PocketType::DECK)       return "deck";
    if (p == PocketType::GRAVEYARD)  return "graveyard";
    if (p == PocketType::HAND)       return "hand";
    if (p == PocketType::TABLE)      return "table";
    if (p == PocketType::SELECTION)  return "selection";
    return "";
}


GameState stringToGameState(const QString& s) {
    if (s == "WaitingForPlayers")   return GameState::WAITINGFORPLAYERS;
    if (s == "Playing")             return GameState::PLAYING;
    if (s == "Finished")            return GameState::FINISHED;
    return GameState::INVALID;
}

QString gameStateToString(const GameState& s) {
    switch(s) {
    case GameState::WAITINGFORPLAYERS:   return "WaitingForPlayers";
    case GameState::PLAYING:             return "Playing";
    case GameState::FINISHED:            return "Finished";
    default:                            break;
    }
    return "Invalid";
}

ClientType stringToClientType(const QString& s) {
    if (s == "player") return ClientType::PLAYER;
    else return ClientType::SPECTATOR;
}

QString clientTypeToString(const ClientType& t) {
    switch(t) {
    case ClientType::PLAYER:     return "player";
    case ClientType::SPECTATOR:  return "spectator";
    }
    return "";
}

GameMessageType stringToGameMessageType(const QString& s) {
    if (s == "game-started")                return GameMessageType::GAMESTARTED;
    if (s == "game-finished")               return GameMessageType::GAMEFINISHED;
    if (s == "player-draw-from-deck")       return GameMessageType::PLAYERDRAWFROMDECK;
    if (s == "player-draw-from-graveyard")  return GameMessageType::PLAYERDRAWFROMGRAVEYARD;
    if (s == "player-discard-card")         return GameMessageType::PLAYERDISCARDCARD;
    if (s == "player-play-card")            return GameMessageType::PLAYERPLAYCARD;
    if (s == "player-respond-with-card")    return GameMessageType::PLAYERRESPONDWITHCARD;
    if (s == "player-pass")                 return GameMessageType::PLAYERPASS;
    if (s == "player-pick-from-selection")  return GameMessageType::PLAYERPICKFROMSELECTION;
    if (s == "player-check-deck")           return GameMessageType::PLAYERCHECKDECK;
    if (s == "player-steal-card")           return GameMessageType::PLAYERSTEALCARD;
    if (s == "player-cancel-card")          return GameMessageType::PLAYERCANCELCARD;
    if (s == "deck-regenerate")             return GameMessageType::DECKREGENERATE;
    if (s == "player-died")                 return GameMessageType::PLAYERDIED;
    return GameMessageType::INVALID;
}

QString gameMessageTypeToString(const GameMessageType& g) {
    switch(g) {
    case GameMessageType::GAMESTARTED:               return "game-started";
    case GameMessageType::GAMEFINISHED:              return "game-finished";
    case GameMessageType::PLAYERDRAWFROMDECK:        return "player-draw-from-deck";
    case GameMessageType::PLAYERDRAWFROMGRAVEYARD:   return "player-draw-from-graveyard";
    case GameMessageType::PLAYERDISCARDCARD:         return "player-discard-card";
    case GameMessageType::PLAYERPLAYCARD:            return "player-play-card";
    case GameMessageType::PLAYERRESPONDWITHCARD:     return "player-respond-with-card";
    case GameMessageType::PLAYERPASS:                return "player-pass";
    case GameMessageType::PLAYERPICKFROMSELECTION:   return "player-pick-from-selection";
    case GameMessageType::PLAYERCHECKDECK:           return "player-check-deck";
    case GameMessageType::PLAYERSTEALCARD:           return "player-steal-card";
    case GameMessageType::PLAYERCANCELCARD:          return "player-cancel-card";
    case GameMessageType::DECKREGENERATE:            return "deck-regenerate";
    case GameMessageType::PLAYERDIED:                return "player-died";
    case GameMessageType::INVALID:                   return "";
    }
    return "";
}

