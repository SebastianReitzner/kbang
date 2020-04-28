#include "charactersidketchum.h"
#include "gamecycle.h"
#include "gametable.h"
#include "gameexceptions.h"
#include "player.h"
#include "playingcard.h"
#include "reactionhandler.h"


CharacterSidKetchum::CharacterSidKetchum(QObject *parent):
        CharacterBase(parent, CharacterType::SID_KETCHUM)
{
}

void CharacterSidKetchum::useAbility(QList<PlayingCard*> cards)
{
    if (cards.size() != 2)
        throw BadCardException();

    foreach (PlayingCard* card, cards) {
        if (card->owner() != mp_player ||
            card->pocket() != PocketType::HAND)
            throw BadCardException();
    }

    if (gameCycle().gamePlayState() == GamePlayState::TURN &&
        gameCycle().currentPlayer() == mp_player) {
        notifyAbilityUse();
        foreach (PlayingCard* card, cards) {
            gameTable().playerDiscardCard(card);
        }
        mp_player->modifyLifePoints(1, 0);
        return;
    }

    if (gameCycle().gamePlayState() == GamePlayState::RESPONSE &&
        gameCycle().requestedPlayer() == mp_player &&
        gameCycle().reactionHandler()->reactionType() == ReactionType::LASTSAVE) {
        notifyAbilityUse();
        foreach (PlayingCard* card, cards) {
            gameTable().playerDiscardCard(card);
        }
        gameCycle().reactionHandler()->dismiss();
        return;
    }
    throw BadGameStateException();
}
