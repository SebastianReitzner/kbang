#include "characterlist.h"

#include "characterbase.h"
#include "characterblackjack.h"
#include "charactercalamityjanet.h"
#include "charactercassidygringo.h"
#include "characterjessejones.h"
#include "characterjourdonnais.h"
#include "characterkitcarlson.h"
#include "characterluckyduke.h"
#include "characterpedroramirez.h"
#include "characterpropertychange.h"
#include "charactersidketchum.h"
#include "charactersuzylafayette.h"
#include "charactervulturesam.h"
#include "util.h"

QList<CharacterType> CharacterList::sm_characterTypes;

CharacterList::CharacterList(QObject* parent, int size):
        QList<CharacterBase*>()
{
    if (sm_characterTypes.size() == 0)
        initCharacterTypes();
    Q_ASSERT(sm_characterTypes.size() != 0);
    shuffleList(sm_characterTypes);
    for (int i = 0; i < size; ++i) {
        append(createCharacter(parent, sm_characterTypes[i % sm_characterTypes.size()]));
    }
}

CharacterBase* CharacterList::createCharacter(QObject* parent, CharacterType type)
{
    switch(type) {
    case CharacterType::BART_CASSIDY:
        return new CharacterCassidyGringo(parent, CharacterCassidyGringo::BartCassidy);
    case CharacterType::BLACK_JACK:
        return new CharacterBlackJack(parent);
    case CharacterType::CALAMITY_JANET:
        return new CharacterCalamityJanet(parent);
    case CharacterType::EL_GRINGO:
        return new CharacterCassidyGringo(parent, CharacterCassidyGringo::ElGringo);
    case CharacterType::JESSE_JONES:
        return new CharacterJesseJones(parent);
    case CharacterType::JOURDONNAIS:
        return new CharacterJourdonnais(parent);
    case CharacterType::KIT_CARLSON:
        return new CharacterKitCarlson(parent);
    case CharacterType::LUCKY_DUKE:
        return new CharacterLuckyDuke(parent);
    case CharacterType::PAUL_REGRET:
        return new CharacterPropertyChange(parent, CharacterPropertyChange::PaulRegret);
    case CharacterType::PEDRO_RAMIREZ:
        return new CharacterPedroRamirez(parent);
    case CharacterType::ROSE_DOOLAN:
        return new CharacterPropertyChange(parent, CharacterPropertyChange::RoseDoolan);
    case CharacterType::SID_KETCHUM:
        return new CharacterSidKetchum(parent);
    case CharacterType::SLAB_THE_KILLER:
        return new CharacterPropertyChange(parent, CharacterPropertyChange::SlabTheKiller);
    case CharacterType::SUZY_LAFAYETTE:
        return new CharacterSuzyLafayette(parent);
    case CharacterType::VULTURE_SAM:
        return new CharacterVultureSam(parent);
    case CharacterType::WILLY_THE_KID:
        return new CharacterPropertyChange(parent, CharacterPropertyChange::WillyTheKid);
    case CharacterType::UNKNOWN:
        NOT_REACHED();
    }
    return new CharacterBase(parent, CharacterType::UNKNOWN);
}

void CharacterList::initCharacterTypes()
{
    Q_ASSERT(sm_characterTypes.size() == 0);
    sm_characterTypes.append(CharacterType::BART_CASSIDY);
    sm_characterTypes.append(CharacterType::BLACK_JACK);
    sm_characterTypes.append(CharacterType::CALAMITY_JANET);
    sm_characterTypes.append(CharacterType::EL_GRINGO);
    sm_characterTypes.append(CharacterType::JESSE_JONES);
    sm_characterTypes.append(CharacterType::JOURDONNAIS);
    sm_characterTypes.append(CharacterType::KIT_CARLSON);
    sm_characterTypes.append(CharacterType::LUCKY_DUKE);
    sm_characterTypes.append(CharacterType::PAUL_REGRET);
    sm_characterTypes.append(CharacterType::PEDRO_RAMIREZ);
    sm_characterTypes.append(CharacterType::ROSE_DOOLAN);
    sm_characterTypes.append(CharacterType::SID_KETCHUM);
    sm_characterTypes.append(CharacterType::SLAB_THE_KILLER);
    sm_characterTypes.append(CharacterType::SUZY_LAFAYETTE);
    sm_characterTypes.append(CharacterType::VULTURE_SAM);
    sm_characterTypes.append(CharacterType::WILLY_THE_KID);
}
