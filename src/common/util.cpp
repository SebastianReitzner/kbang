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

#include "util.h"


std::string randomToken(int minLength, int maxLength)
{
    if (minLength > maxLength) // assure minLength <= maxLength
    {
        const int tmp = maxLength;
        maxLength = minLength;
        minLength = tmp;
    }

    constexpr char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> tokenLenDist(0, maxLength - minLength + 1);
    std::uniform_int_distribution<std::mt19937::result_type> charLenDist(0, strlen(chars) - 1);
    const int length = minLength + (tokenLenDist(rng));
    std::string token = "";
    for (int i = 0; i < length; ++i)
    {
        token += chars[charLenDist(rng)];
    }
    token += '\0';
    return token;
}

/*bool randomBool(qreal probability)
{
    // https://stackoverflow.com/questions/43329352/generating-random-boolean

    const int random_val_size = 4096;
    const int true_val_treshold = (int)(random_val_size * probability);
    const int random_val = qrand() % random_val_size;
    return (random_val < true_val_treshold);
}*/
