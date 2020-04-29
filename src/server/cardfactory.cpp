#include "cardfactory.h"
#include "cards.h"

#include <QSet>
#include <cstdlib>

struct CardFactory::CardFactoryImp
{

    void generateCards(Game* game, QMap<int, PlayingCard*>& res)
    {
        QList<PlayingCard*> list;
        //////////
       // BANG //
      //////////
        for (int i = 2; i <= 14; ++i) {
            list.append(new CardBang(game, id(), CardSuit::DIAMONDS, i));
        }
        for (int i = 2; i <= 9; ++i) {
            list.append(new CardBang(game, id(), CardSuit::CLUBS, i));
        }
        for (int i = 12; i <= 14; ++i) {
            list.append(new CardBang(game, id(), CardSuit::HEARTS, i));
        }
        list.append(new CardBang(game, id(), CardSuit::SPADES, 14));


        ////////////
       // MISSED //
      ////////////
        for (int i = 2; i <= 8; ++i) {
            list.append(new CardMissed(game, id(), CardSuit::SPADES, i));
        }
        for (int i = 10; i <= 14; ++i) {
            list.append(new CardMissed(game, id(), CardSuit::CLUBS, i));
        }

        ///////////////////
       // BEER + SALOON //
      ///////////////////
        for (int i = 6; i <= 11; ++i) {
            list.append(new CardBeer(game, id(), CardSuit::HEARTS, i, 0));
        }
        list.append(new CardBeer(game, id(), CardSuit::HEARTS, 5, 1));

        ////////////
       // HORSES //
      ////////////
        list.append(new CardHorse(game, id(), CardHorse::Appaloosa, CardSuit::SPADES, 14));
        list.append(new CardHorse(game, id(), CardHorse::Mustang,   CardSuit::HEARTS, 8));
        list.append(new CardHorse(game, id(), CardHorse::Mustang,   CardSuit::HEARTS, 9));

        /////////////
       // WEAPONS //
      /////////////
        list.append(new WeaponCard(game, id(), 1, CardSuit::SPADES, 10));
        list.append(new WeaponCard(game, id(), 1, CardSuit::CLUBS,  10));
        list.append(new WeaponCard(game, id(), 2, CardSuit::CLUBS,  11));
        list.append(new WeaponCard(game, id(), 2, CardSuit::CLUBS,  12));
        list.append(new WeaponCard(game, id(), 2, CardSuit::SPADES, 13));
        list.append(new WeaponCard(game, id(), 3, CardSuit::CLUBS,  13));
        list.append(new WeaponCard(game, id(), 4, CardSuit::CLUBS,  14));
        list.append(new WeaponCard(game, id(), 5, CardSuit::SPADES, 8));

        ////////////////
       // DRAW CARDS //
      ////////////////
        list.append(new CardDrawCards(game, id(), CardDrawCards::Diligence,  CardSuit::SPADES,  9));
        list.append(new CardDrawCards(game, id(), CardDrawCards::Diligence,  CardSuit::SPADES,  9));
        list.append(new CardDrawCards(game, id(), CardDrawCards::WellsFargo, CardSuit::HEARTS,  3));

        ////////////////
       // MULTISHOOT //
      ////////////////
        list.append(new CardMultiShoot(game, id(), CardMultiShoot::Indians, CardSuit::DIAMONDS,  13));
        list.append(new CardMultiShoot(game, id(), CardMultiShoot::Indians, CardSuit::DIAMONDS,  14));
        list.append(new CardMultiShoot(game, id(), CardMultiShoot::Gatling, CardSuit::HEARTS,    10));

        //////////
       // DUEL //
      //////////
        list.append(new CardDuel(game, id(), CardSuit::CLUBS,    8 ));
        list.append(new CardDuel(game, id(), CardSuit::SPADES,   11));
        list.append(new CardDuel(game, id(), CardSuit::DIAMONDS, 12));


        list.append(new CardGeneralStore(game, id(), CardSuit::SPADES, 12));
        list.append(new CardGeneralStore(game, id(), CardSuit::CLUBS, 9));

        list.append(new CardJail(game, id(), CardSuit::SPADES, 10));
        list.append(new CardJail(game, id(), CardSuit::SPADES, 11));
        list.append(new CardJail(game, id(), CardSuit::HEARTS, 4));

        list.append(new CardDynamite(game, id(), CardSuit::HEARTS, 2));

        list.append(new CardTaker(game, id(), CardTaker::Panic, CardSuit::DIAMONDS, 8 ));
        list.append(new CardTaker(game, id(), CardTaker::Panic, CardSuit::HEARTS,   11));
        list.append(new CardTaker(game, id(), CardTaker::Panic, CardSuit::HEARTS,   12));
        list.append(new CardTaker(game, id(), CardTaker::Panic, CardSuit::HEARTS,   14));

        list.append(new CardTaker(game, id(), CardTaker::CatBalou, CardSuit::DIAMONDS, 9 ));
        list.append(new CardTaker(game, id(), CardTaker::CatBalou, CardSuit::DIAMONDS, 10));
        list.append(new CardTaker(game, id(), CardTaker::CatBalou, CardSuit::DIAMONDS, 11));
        list.append(new CardTaker(game, id(), CardTaker::CatBalou, CardSuit::HEARTS,   13));

        list.append(new CardBarrel(game, id(), CardSuit::SPADES, 12));
        list.append(new CardBarrel(game, id(), CardSuit::SPADES, 13));

        foreach(PlayingCard* card, list) {
            res[card->id()] = card;
        }
    }


    int id()
    {
        int cardId;
        do {
            cardId = (int)qrand();
        } while(m_ids.contains(cardId));
        m_ids.insert(cardId);
        return cardId;
    }

    QSet<int>   m_ids;
};

CardFactory::CardFactory()
{
    mp_imp = new CardFactoryImp();
}

CardFactory::~CardFactory()
{
    delete mp_imp;
}

QMap<int, PlayingCard*> CardFactory::generateCards(Game* game)
{
    QMap<int, PlayingCard*> res;
    mp_imp->generateCards(game, res);
    return res;

}
