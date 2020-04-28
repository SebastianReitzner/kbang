#include "characterjourdonnais.h"
#include "cardbarrel.h"
#include "player.h"
#include "gamecycle.h"

CharacterJourdonnais::CharacterJourdonnais(QObject* parent):
        CharacterBase(parent, CharacterType::JOURDONNAIS),
        mp_integratedBarrel(0)
{
}

void CharacterJourdonnais::useAbility()
{
    if (mp_integratedBarrel == 0) {
        mp_integratedBarrel = new CardBarrel(mp_player->game(), 0, CardSuit::CLUBS, 2);
        mp_integratedBarrel->setVirtual(mp_player, PocketType::TABLE);
    }
    gameCycle().playCard(mp_player, mp_integratedBarrel);
}

